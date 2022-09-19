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

#include "olinkhost.h"
#include "olink/remoteregistry.h"
#include <iostream>
#include "private/requesthandlerfactory.h"

using namespace ApiGear::PocoImpl;

OLinkHost::OLinkHost(ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_webserver(nullptr)
    , m_handlerFactory(nullptr)
    , m_registry(&registry)
{
    m_registry->onLog(m_log.logFunc());
}

OLinkHost::~OLinkHost()
{
    m_webserver->stop();
    delete m_webserver;
    m_webserver = nullptr;
}

void OLinkHost::listen(int port)
{
    std::cout << "wss.listen() on ";
    if(m_handlerFactory == nullptr)
    {
        m_handlerFactory = new RequestHandlerFactory(*m_registry);
    }
    m_webserver = new Poco::Net::HTTPServer(m_handlerFactory, port);
    std::cout << m_webserver->port() << std::endl;
    m_webserver->start();
}

void OLinkHost::close()
{
    m_handlerFactory->close();
    m_webserver->stop();
}

void OLinkHost::onClosed()
{
    std::cout << "wss.closed()\n";
}

