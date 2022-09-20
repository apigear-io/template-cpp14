#pragma once

#include <memory>

namespace Poco {
namespace Net {
class WebSocket;
}
} //namespace Poco::Net

namespace ApiGear{
namespace PocoImpl{

class OLinkRemote;

class IConnectionStorage
{
public:
virtual ~IConnectionStorage() = default;
virtual void notifyConnectionClosed() = 0;
virtual void addConnection(std::unique_ptr<Poco::Net::WebSocket> connectionSocket) = 0;
};

}}  //namespace ApiGear::PocoImpl
