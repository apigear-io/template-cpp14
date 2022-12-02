#pragma once

#include <string>

namespace ApiGear {
namespace PocoImpl {

/**
* A set of actions presented by a socket user to a socket helper that encapsulates socket functionality.
* see SocketWrapper class.
*/
class ISocketUser
{
public:
    /**
    * Handler for raw message received.
    */
    virtual void handleTextMessage(const std::string& message) = 0;
    /**
    * A callback to inform the socket user that connection was closed with close frame received from network.
    */
    virtual void onConnectionClosedFromNetwork() = 0;
};

}}   //namespace ApiGear::PocoImpl
