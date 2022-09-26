#pragma warning (disable: 4251) 
#pragma warning (disable: 4099) 

#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "private/frame.hpp"
#include "private/sourceobjectmock.hpp"
#include "private/test_server/test_server.hpp"

#include "../olinkhost.h"

#include "olink/remoteregistry.h"
#include "olink/core/types.h"
#include "olink/core/protocol.h"

#include "Poco/Net/WebSocket.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPClientSession.h"

#include "nlohmann/json.hpp"

namespace tests{

namespace {
    // Message converter to translate messages for network format. Same should be used in tested classes.
    ApiGear::ObjectLink::MessageConverter converter(ApiGear::ObjectLink::MessageFormat::JSON);

    Frame receiveFrame (Poco::Net::WebSocket& socket)
    {
        Frame inFrame;
        Poco::Buffer<char> pocobuffer(0);
        auto receivedSize = socket.receiveFrame(pocobuffer, inFrame.flags);
        inFrame.payload = std::string(pocobuffer.begin(), receivedSize);
        return inFrame;
    }
}

//virtual nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args);
//virtual void olinkSetProperty(const std::string& propertyId, const nlohmann::json& value);
// 
//virtual void olinkLinked(const std::string& objectId, IRemoteNode* node);
//virtual void olinkUnlinked(const std::string& objectId);

    TEST_CASE("OLinkHost tests")
    {
        ApiGear::ObjectLink::RemoteRegistry registry;
        registry.onLog([](auto /*level*/, auto msg){ std::cout << msg << std::endl; });

        SourceObjectMock source1;
        std::string objectId = "tests.sink1";
        ALLOW_CALL(source1, olinkObjectName()).RETURN(objectId);
        registry.addSource(source1);

        // Common data.
        auto portNumber = 8000;
        auto localHostAddress = "127.0.0.1";
        Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/ws", Poco::Net::HTTPRequest::HTTP_1_1);
        Poco::Net::HTTPResponse response;

        nlohmann::json initProperties1 = { {"property1", "some_string1" }, { "property2",  92 }, { "property3", true } };
        nlohmann::json initProperties2 = { {"property1", "some_string2" }, { "property2",  29 }, { "property3", false } };

        std::string any_payload = "any";

        ApiGear::PocoImpl::OLinkHost testHost(registry);

        SECTION("Server creates two nodes for link messages from different sessions for same source and sends back init message. Unlink happens before server closes.")
        {
            testHost.listen(portNumber);
            
            Poco::Net::HTTPClientSession clientSession1(localHostAddress, portNumber);
            Poco::Net::HTTPClientSession clientSession2(localHostAddress, portNumber);
            Poco::Net::WebSocket clientSocket1(clientSession1, request, response), clientSocket2(clientSession2, request, response);
            
            auto preparedLinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId));
            REQUIRE_CALL(source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));
            REQUIRE_CALL(source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));

            REQUIRE_CALL(source1, olinkCollectProperties()).RETURN(initProperties1);
            REQUIRE_CALL(source1, olinkCollectProperties()).RETURN(initProperties2);

            clientSocket1.sendFrame(preparedLinkMessage.c_str(), static_cast<int>(preparedLinkMessage.size()));
            clientSocket2.sendFrame(preparedLinkMessage.c_str(), static_cast<int>(preparedLinkMessage.size()));
            
            Poco::Thread::sleep(50);
            auto nodes = registry.getNodes(objectId);
            REQUIRE(nodes.size() == 2);
            auto node1AfterLinkBoth = nodes[0];
            auto node2AfterLinkBoth = nodes[1];
            REQUIRE(node1AfterLinkBoth != nullptr);
            REQUIRE(node2AfterLinkBoth != nullptr);
            REQUIRE(node1AfterLinkBoth != node2AfterLinkBoth);

            // Check that server sent init messages
            auto expectedInitMessage1 = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1));
            auto expectedInitMessage2 = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties2));
            {
                auto msg1 = receiveFrame(clientSocket1);
                auto checkReceivedMessage = msg1.payload == expectedInitMessage1 || msg1.payload == expectedInitMessage2;
                REQUIRE(checkReceivedMessage);
                REQUIRE(msg1.flags == Poco::Net::WebSocket::FRAME_TEXT);
            }

            {
                auto msg2 = receiveFrame(clientSocket2);
                auto checkReceivedMessage = msg2.payload == expectedInitMessage1 || msg2.payload == expectedInitMessage2;
                REQUIRE(checkReceivedMessage);
                REQUIRE(msg2.flags == Poco::Net::WebSocket::FRAME_TEXT);
            }

            REQUIRE_CALL(source1, olinkUnlinked(objectId));

            auto unlinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(objectId));
            clientSocket1.sendFrame(unlinkMessage.c_str(), static_cast<int>(unlinkMessage.size()));
            
            Poco::Thread::sleep(50);
            nodes = registry.getNodes(objectId);
            REQUIRE(nodes.size() == 1);
            auto node2AfterUnlink1 = nodes[0];
            REQUIRE(node2AfterUnlink1 != nullptr);
            bool nodeDidNotChanged = node2AfterUnlink1 == node1AfterLinkBoth || node2AfterUnlink1 == node2AfterLinkBoth;
            REQUIRE(nodeDidNotChanged);

            REQUIRE_CALL(source1, olinkUnlinked(objectId));
            clientSocket2.sendFrame(unlinkMessage.c_str(), static_cast<int>(unlinkMessage.size()));
            Poco::Thread::sleep(50);
            nodes = registry.getNodes(objectId);
            REQUIRE(nodes.size() == 0);
            
            clientSocket1.sendFrame(any_payload.c_str(), static_cast<int>(any_payload.size()),Poco::Net::WebSocket::FRAME_OP_CLOSE);
            clientSocket2.sendFrame(any_payload.c_str(), static_cast<int>(any_payload.size()),Poco::Net::WebSocket::FRAME_OP_CLOSE);
            // Send close Frame
            Poco::Thread::sleep(50);

            testHost.close();
        }

        SECTION("Host close before session closes. Only information is close frame to clients.")
        {
            testHost.listen(portNumber);

            Poco::Net::HTTPClientSession clientSession1(localHostAddress, portNumber);
            Poco::Net::WebSocket clientSocket1(clientSession1, request, response);

            auto preparedLinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId));
            REQUIRE_CALL(source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));

            REQUIRE_CALL(source1, olinkCollectProperties()).RETURN(initProperties1);

            clientSocket1.sendFrame(preparedLinkMessage.c_str(), static_cast<int>(preparedLinkMessage.size()));

            Poco::Thread::sleep(150);
            auto nodes = registry.getNodes(objectId);
            REQUIRE(nodes.size() == 1);
            REQUIRE(nodes[0]!= nullptr);

            // Check that server sent init messages
            auto expectedInitMessage1 = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1));
            {
                auto msg1 = receiveFrame(clientSocket1);
                REQUIRE(msg1.payload == expectedInitMessage1);
                REQUIRE(msg1.flags == Poco::Net::WebSocket::FRAME_TEXT);
            }

            testHost.close();
            Poco::Thread::sleep(50);
            REQUIRE(registry.getNodes(objectId).size() == 0);
            REQUIRE(registry.getSource(objectId) == &source1);

            {
                auto closeFrame = receiveFrame(clientSocket1);
                REQUIRE(closeFrame.flags == Poco::Net::WebSocket::FRAME_OP_CLOSE);
            }
        }

        SECTION("Source removal doesn't affect setup. It should inform somehow clients that service is not available.")
        {
            testHost.listen(portNumber);

            Poco::Net::HTTPClientSession clientSession1(localHostAddress, portNumber);
            Poco::Net::WebSocket clientSocket1(clientSession1, request, response);

            auto preparedLinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId));
            REQUIRE_CALL(source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));

            REQUIRE_CALL(source1, olinkCollectProperties()).RETURN(initProperties1);

            clientSocket1.sendFrame(preparedLinkMessage.c_str(), static_cast<int>(preparedLinkMessage.size()));

            Poco::Thread::sleep(50);
            auto nodes = registry.getNodes(objectId);
            REQUIRE(nodes.size() == 1);
            REQUIRE(nodes[0] != nullptr);

            // Check that server sent init messages
            auto expectedInitMessage1 = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1));
            {
                auto msg1 = receiveFrame(clientSocket1);
                REQUIRE(msg1.payload == expectedInitMessage1);
                REQUIRE(msg1.flags == Poco::Net::WebSocket::FRAME_TEXT);
            }
            // start test
            registry.removeSource(objectId);
            Poco::Thread::sleep(100);

            REQUIRE(registry.getNodes(objectId).size() == 0);
            REQUIRE(registry.getSource(objectId) == nullptr);

            // test cleanup
            testHost.close();
            Poco::Thread::sleep(50);

            // Receive close frame on close.
            {
                auto closeFrame = receiveFrame(clientSocket1);
                REQUIRE(closeFrame.flags == Poco::Net::WebSocket::FRAME_OP_CLOSE);
            }
        }

        SECTION("One of connections receive close frame")
        {
            testHost.listen(portNumber);

            Poco::Net::HTTPClientSession clientSession1(localHostAddress, portNumber);
            Poco::Net::HTTPClientSession clientSession2(localHostAddress, portNumber);
            Poco::Net::WebSocket clientSocket1(clientSession1, request, response), clientSocket2(clientSession2, request, response);

            auto preparedLinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId));
            REQUIRE_CALL(source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));
            REQUIRE_CALL(source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));

            REQUIRE_CALL(source1, olinkCollectProperties()).RETURN(initProperties1);
            REQUIRE_CALL(source1, olinkCollectProperties()).RETURN(initProperties2);

            clientSocket1.sendFrame(preparedLinkMessage.c_str(), static_cast<int>(preparedLinkMessage.size()));
            clientSocket2.sendFrame(preparedLinkMessage.c_str(), static_cast<int>(preparedLinkMessage.size()));

            Poco::Thread::sleep(50);
            auto nodes = registry.getNodes(objectId);
            REQUIRE(nodes.size() == 2);
            auto nodeA = nodes[0];
            auto nodeB = nodes[1];
            REQUIRE(nodeA != nullptr);
            REQUIRE(nodeB != nullptr);
            REQUIRE(nodeA != nodeB);

            // Check that server sent init messages
            auto expectedInitMessage1 = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1));
            auto expectedInitMessage2 = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties2));
            {
                auto msg1 = receiveFrame(clientSocket1);
                auto checkReceivedMessage = msg1.payload == expectedInitMessage1 || msg1.payload == expectedInitMessage2;
                REQUIRE(checkReceivedMessage);
                REQUIRE(msg1.flags == Poco::Net::WebSocket::FRAME_TEXT);
            }

            {
                auto msg2 = receiveFrame(clientSocket2);
                auto checkReceivedMessage = msg2.payload == expectedInitMessage1 || msg2.payload == expectedInitMessage2;
                REQUIRE(checkReceivedMessage);
                REQUIRE(msg2.flags == Poco::Net::WebSocket::FRAME_TEXT);
            }

            // START TEST
            clientSocket1.sendFrame(any_payload.c_str(), static_cast<int>(any_payload.size()), Poco::Net::WebSocket::FRAME_OP_CLOSE);
            // Send close Frame
            Poco::Thread::sleep(100);
            nodes = registry.getNodes(objectId);
            // Node 2 still works for source
            REQUIRE(nodes.size() == 1);
            auto node2 = nodes[0];
            REQUIRE(node2 != nullptr);
            bool nodeDidNotChanged = node2 == nodeA || node2 == nodeB;
            REQUIRE(nodeDidNotChanged);
            // client 2 receives close frame
            testHost.close();
            {
                auto closeFrame = receiveFrame(clientSocket2);
                REQUIRE(closeFrame.flags == Poco::Net::WebSocket::FRAME_OP_CLOSE);
            }
        }

    }

}// namespace tests