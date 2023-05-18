#include "test_sink.h"
#include "olink/clientnode.h"
#include "olink/clientregistry.h"
#include "olink/core/types.h"
#include "apigear/olink/olinkconnection.h"
#include <memory>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <future>

/*
By default test request property string change 600 times from each of 100 threads.
Each message is over 100 character long.
Test waits for the responses after sending all the messages, not for each one.
You can play around with running this program with different messages number and different threads number.
*/
int main(int argc, char* argv[])
{
    std::vector<uint16_t> timePerMessage;
    auto sendThreadNumber = 100u;
    auto messages_number = 600u;
    if (argc > 1)
    {
        char* p;
        messages_number = strtol(argv[1], &p, 10);
    }
    if (argc > 2)
    {
        char* p;
        sendThreadNumber = strtol(argv[2], &p, 10);
    }
    auto portNumber = 8000;
    auto localHostAddress = "ws://127.0.0.1:" + std::to_string(portNumber);

    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::PocoImpl::OlinkConnection client(registry);
    client.connectToHost(Poco::URI(localHostAddress));

    auto sink = std::make_shared<TestSink>();
    std::vector<std::shared_future<long long>> tasks;

    // Prepare messages to send before test starts not to slow down it with allocation of this many messages:
    std::vector<std::vector<std::string>> messagesToSend;
    for (int threadNo = 0u; threadNo < sendThreadNumber; threadNo++)
    {
        std::vector<std::string> msgsForSingleThread;
        for (auto i = 0u; i < messages_number; i++)
        {
            msgsForSingleThread.push_back("Some longer property to be set, prepared before test for each message number to reduce allocating time in tests"
                + std::to_string(threadNo* messages_number + i));//make every message different
        }
        messagesToSend.push_back(msgsForSingleThread);
    }

        uint32_t totalMessage = 0;

        client.connectAndLinkObject(sink);
        auto begin = std::chrono::high_resolution_clock::now();
        while(!sink->isReady())
        {
            // Wait until object is linked with server.
        }
   
        for (int threadNo = 0u; threadNo < sendThreadNumber; threadNo++)
        {
            auto& messagesForThread = messagesToSend[threadNo];
            auto sendMessagesTask = std::async(std::launch::async,
                [sink, messages_number, &messagesForThread](){
                    auto beginM = std::chrono::high_resolution_clock::now();
                    for (auto i = 0u; i < messages_number; i++)
                    {
                        sink->setPropString(messagesForThread[i]);
                    }

                auto endM = std::chrono::high_resolution_clock::now();
                return std::chrono::duration_cast<std::chrono::milliseconds>(endM - beginM).count();
            });
            tasks.push_back(sendMessagesTask.share());
        }            
        
    for (auto task : tasks)
    {
        task.wait();
    }
    while (sink->propertyChangedTimes < messages_number * sendThreadNumber - 1)
    {
        // Wait until all responses received.
    }
 
    client.disconnect();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "received " << sink->propertyChangedTimes << " of " << messages_number * sendThreadNumber << "  " << (double)sink->propertyChangedTimes / (double)messages_number / (double)sendThreadNumber << std::endl;;

    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Time measured " << time.count() << std::endl;
    return 0;
}