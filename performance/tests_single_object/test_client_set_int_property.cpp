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
By default test request property int change 1000 times from each of 100 threads.
Test waits for the responses after sending all the messages, not for each one.
You can play around with running this program with different messages number and different threads number.
*/
int main(int argc, char* argv[])
{
    std::vector<uint16_t> timePerMessage;
    auto sendThreadNumber = 100u;
    auto messages_number = 1000u;
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
    auto begin = std::chrono::high_resolution_clock::now();

    client.connectAndLinkObject(sink);
    while (!sink->isReady())
    {
        // Wait until object is linked with server.
    }

    for (int threadNo = 0u; threadNo < sendThreadNumber; threadNo++)
    {
        auto sendMessagesTask = std::async(std::launch::async,
            [sink, messages_number, threadNo]() {
                auto beginM = std::chrono::high_resolution_clock::now();

                for (auto i = 0u; i < messages_number; i++)
                {
                    sink->setPropInt(threadNo * messages_number + i);
                }

                auto endM = std::chrono::high_resolution_clock::now();
                return (beginM-endM).count();
            });
        tasks.push_back(sendMessagesTask.share());
    }

    for (auto task : tasks)
    {
        task.wait();
    }
    while (sink->propertyChangedTimes < messages_number* sendThreadNumber -1)
    {
        // Wait until all responses received.
    }
    client.disconnect();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "received " << sink->propertyChangedTimes << " of " << messages_number * sendThreadNumber << "  " << (double)sink->propertyChangedTimes / (double)messages_number / (double)sendThreadNumber << std::endl;;

    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);


    std::cout<<"Time measured "<< time .count() << std::endl;
    
    return 0;
}