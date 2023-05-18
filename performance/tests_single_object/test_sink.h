#pragma once
#include "api/generated/olink/testapiclient.h"

/*
* A wrapper for tested object that adds counting of incoming messages.
*/
class TestSink : public Test::Api::olink::TestApiClient
{
public:
    void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override {
        propertyChangedTimes++;
        Test::Api::olink::TestApiClient::olinkOnPropertyChanged(propertyId, value);
    }
    uint32_t propertyChangedTimes = 0;
};