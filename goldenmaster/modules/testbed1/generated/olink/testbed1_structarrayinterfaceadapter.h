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

#include "generated/api/testbed1.h"
#include "generated/api/testbed1_common.h"
#include "olink/remotenode.h"

// using namespace ApiGear;
// using namespace ApiGear::ObjectLink;
namespace Test {
namespace Testbed1 {
class TEST_TESTBED1_EXPORT OLinkStructArrayInterfaceAdapter : public ApiGear::ObjectLink::IObjectSource, public IStructArrayInterfaceSubscriber
{
public:
    explicit OLinkStructArrayInterfaceAdapter(IStructArrayInterface* impl, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~OLinkStructArrayInterfaceAdapter() override;
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

public: // IStructArrayInterfaceSubscriber interface
    void OnSigBool(const std::list<StructBool>& paramBool) override;
    void OnSigInt(const std::list<StructInt>& paramInt) override;
    void OnSigFloat(const std::list<StructFloat>& paramFloat) override;
    void OnSigString(const std::list<StructString>& paramString) override;
    void OnPropBoolChanged(const std::list<StructBool>& Value) override;
    void OnPropIntChanged(const std::list<StructInt>& Value) override;
    void OnPropFloatChanged(const std::list<StructFloat>& Value) override;
    void OnPropStringChanged(const std::list<StructString>& Value) override;

private:
    IStructArrayInterface* m_impl;
    ApiGear::ObjectLink::IRemoteNode *m_node;
    ApiGear::ObjectLink::RemoteRegistry* m_registry;
};
} // namespace Testbed1
} // namespace Test
