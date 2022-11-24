
#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple/implementation/nopropertiesinterface.h"
#include "tb_simple/implementation/nooperationsinterface.h"
#include "tb_simple/implementation/nosignalsinterface.h"

using namespace Test::TbSimple;

int main(){
    std::unique_ptr<ISimpleInterface> testSimpleInterface = std::make_unique<SimpleInterface>();
    std::unique_ptr<ISimpleArrayInterface> testSimpleArrayInterface = std::make_unique<SimpleArrayInterface>();
    std::unique_ptr<INoPropertiesInterface> testNoPropertiesInterface = std::make_unique<NoPropertiesInterface>();
    std::unique_ptr<INoOperationsInterface> testNoOperationsInterface = std::make_unique<NoOperationsInterface>();
    std::unique_ptr<INoSignalsInterface> testNoSignalsInterface = std::make_unique<NoSignalsInterface>();

    return 0;
}
