/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"
#include "olink/remotenode.h"

// using namespace ApiGear;
// using namespace ApiGear::ObjectLink;
namespace Test {
namespace TbSame1 {
class TEST_TB_SAME1_EXPORT OLinkSameStruct2InterfaceAdapter : public ApiGear::ObjectLink::IObjectSource, public ISameStruct2InterfaceSubscriber
{
public:
    explicit OLinkSameStruct2InterfaceAdapter(ISameStruct2Interface* impl, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~OLinkSameStruct2InterfaceAdapter() override;
public:
    void publishState();
    nlohmann::json captureState();
    void applyState(const nlohmann::json& state);
    
public: // IObjectSource interface
    std::string olinkObjectName() override;
    nlohmann::json olinkInvoke(std::string name, nlohmann::json args) override;
    void olinkSetProperty(std::string name, nlohmann::json value) override;
    void olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) override;
    void olinkUnlinked(std::string name) override;
    nlohmann::json olinkCollectProperties() override;

public: // ISameStruct2InterfaceSubscriber interface
    void OnSig1(const Struct1& param1) override;
    void OnSig2(const Struct1& param1,const Struct2& param2) override;
    void OnProp1Changed(const Struct2& Value) override;
    void OnProp2Changed(const Struct2& Value) override;

private:
    ISameStruct2Interface* m_impl;
    ApiGear::ObjectLink::IRemoteNode *m_node;
    ApiGear::ObjectLink::RemoteRegistry* m_registry;
};
} // namespace TbSame1
} // namespace Test