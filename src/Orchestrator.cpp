#include "Orchestrator.h"
#include <iostream>

Orchestrator::Orchestrator(const std::vector<Node>& nodes) : nodes(nodes) {}

void Orchestrator::distributeTasks(const std::vector<Task>& tasks) {
    int currentNodeIndex = 0;

    for (const Task& task : tasks) {
        nodes[currentNodeIndex].addTask(task);
        currentNodeIndex = (currentNodeIndex + 1) % nodes.size(); // load balancing
    }
}

void Orchestrator::monitorNodes() {
    for (Node& node : nodes) {
        node.startProcessing();
    }
}
