#include <stdexcept>
#include "SortBlock.h"

#include "BlockMaker.h"

static BlockMaker<SortBlock> maker("sort");

std::list<std::string>& SortBlock::execute(const std::list<std::string>& params, std::list<std::string>& text) {
    if (!params.empty()) {
        throw IncorrectAmountOfParams("Sortblock doesn't need params, given " + std::to_string(params.size()));
    }

    text.sort();
    return text;
}
