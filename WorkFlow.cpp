#include <memory>
#include "WorkFlow.h"
#include "BlockFactory.h"

void WorkFlow::executeWorkFlow(const std::string& filename) {

    parser.readWorkFlowFile(filename);
    auto scheme = parser.getScheme();
    auto blockArgsMap = parser.getBunchOfBlocksArgs();

    InOutTypesForBlock prevOutType = InOutTypesForBlock::NO;
    InOutTypesForBlock currentInType;
    std::list<std::string> text;

    for (auto it = scheme.begin(); it != scheme.end(); ++it) {
        BlockArguments blockArgs = blockArgsMap.at(*it);
        std::shared_ptr<Worker> block(BlockFactory::Instance().create(blockArgs.getName()));
        currentInType = block->getInType(currentInType);
        if (currentInType != prevOutType) {
            throw UnavailableWorkFlowException("Workflow is incorrect");
        }
        prevOutType = block->getOutType(prevOutType);
        text = block->execute(blockArgs.getParams(), text);
    }
}