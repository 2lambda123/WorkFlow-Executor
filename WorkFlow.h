#ifndef WORKFLOW_WORKFLOW_H
#define WORKFLOW_WORKFLOW_H

#endif 

#include "WorkFlowParser.h"

class WorkFlow {
    WorkFlowParser parser;
public:
    void executeWorkFlow(const std::string& filename);
};