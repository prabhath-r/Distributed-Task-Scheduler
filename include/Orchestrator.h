#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include <vector>
#include "Node.h"
#include "Task.h"

class Orchestrator {
public:
    Orchestrator(const std::vector<Node>& nodes);
    void distributeTasks(const std::vector<Task>& tasks);
    void monitorNodes();

private:
    std::vector<Node> nodes;
};

#endif 
