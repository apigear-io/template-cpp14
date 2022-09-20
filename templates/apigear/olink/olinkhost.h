/*
* MIT License
*
* Copyright (c) 2021 ApiGear
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#pragma once

#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/WebSocket.h"
#include "private/connectionstorage.h"

#include <memory>


#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define APIGEAR_OLINK_EXPORT __attribute__ ((dllexport))
#else
#define APIGEAR_OLINK_EXPORT __declspec(dllexport)
#endif
#else
#if __GNUC__ >= 4
#define APIGEAR_OLINK_EXPORT __attribute__ ((visibility ("default")))
#else
#define APIGEAR_OLINK_EXPORT
#endif
#endif

namespace Poco {
namespace Net {

class HTTPServerRequest;
class HTTPServerResponse;
}} // namespace Poco::Net


namespace ApiGear {
namespace PocoImpl {

class RequestHandlerFactory;

class APIGEAR_OLINK_EXPORT OLinkHost
{
public:
    explicit OLinkHost(ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~OLinkHost();
    void listen(int port);
    void close();
    void onClosed();

private:
    std::unique_ptr<Poco::Net::HTTPServer> m_webserver;
    ApiGear::ObjectLink::RemoteRegistry& m_registry;
    ConnectionStorage m_connectionStorage;
};

} // namespace PocoImpl
} // namespace ApiGear
