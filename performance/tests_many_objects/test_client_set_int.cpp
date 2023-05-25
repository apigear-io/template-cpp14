#include "inspected_sink.h"
#include "olink/clientnode.h"
#include "olink/clientregistry.h"
#include "olink/core/types.h"
#include "apigear/olink/olinkconnection.h"
#include <memory>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <future>

#include "api/generated/olink/testapi0client.h"
#include "api/generated/olink/testapi1client.h"
#include "prepare_test_data.h"

struct PropertyIntTestData
{
public:
    std::shared_ptr<InspectedSink> sink;
    std::function<void(int)> testFunction;
};

class IntPropertySetter {
public:
    template<class Interface>
    void testFunction(std::shared_ptr<Interface> object, int value)
    {
        object->setPropInt(value);
    }
};

int main(int argc, char* argv[])
{
    std::vector<uint16_t> timePerMessage;
    auto messages_number = 1000u;
    if (argc > 1)
    {
        char* p;
        messages_number = strtol(argv[1], &p, 10);
    }
    auto portNumber = 8000;
    auto localHostAddress = "ws://127.0.0.1:" + std::to_string(portNumber);

    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::PocoImpl::OlinkConnection client(registry);
    client.connectToHost(Poco::URI(localHostAddress));
    std::vector<std::shared_future<void>> tasks;
    IntPropertySetter setter;
    auto testData = getTestData<PropertyIntTestData, IntPropertySetter>(setter);

    for (auto& element : testData)
    {
        client.connectAndLinkObject(element.sink);
    }
    auto begin = std::chrono::high_resolution_clock::now();
    for (auto& element : testData)
    {
        auto sendMessagesTask = std::async(std::launch::async,
            [&element, messages_number](){
                while (element.sink->initReceived != true)
                {
                    // wait until ready to use.
                }
                for (auto i = 0; i < messages_number; i++)
                {
                    element.testFunction(i);
                }
            });
        tasks.push_back(sendMessagesTask.share());
    }

    for (auto task : tasks)
    {
        task.wait();
    }
    auto allMessagesReceived = false;
    while (!allMessagesReceived)
    {
        auto serviceWithAllMessages = 0u;
        for (auto& element : testData)
        {
            if (element.sink->propertyChangedTimes == messages_number -1)
            {
                serviceWithAllMessages++;
            }
        }
        allMessagesReceived = serviceWithAllMessages == testData.size();
    }
    for (auto& element : testData)
    {
        client.disconnectAndUnlink(element.sink->olinkObjectName());
    }
    auto end = std::chrono::high_resolution_clock::now();
    client.disconnect();
  
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);


    std::cout << "Time measured " << time.count() << std::endl;

    return 0;
}