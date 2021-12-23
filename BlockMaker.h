#ifndef WORKFLOW_BLOCKMAKER_H
#define WORKFLOW_BLOCKMAKER_H

#include "IBlockMaker.h"
#include "BlockFactory.h"

template<typename T>
class BlockMaker : public IBlockMaker
{
public:
    Worker* create() override {
        return new T();
    }

    BlockMaker(const std::string& key)
    {
        BlockFactory::Instance().RegisterMaker(key, this);
    }
};

#endif