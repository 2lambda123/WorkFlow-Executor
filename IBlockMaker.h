#ifndef WORKFLOW_IBLOCKMAKER_H
#define WORKFLOW_IBLOCKMAKER_H

class IBlockMaker {

public:
    virtual Worker* create() = 0;
    virtual ~IBlockMaker() {}
};

#endif