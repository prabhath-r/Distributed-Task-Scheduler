#include "Orchestrator.h"

void Orchestrator::addNode(const Node& node) {
    nodes.push_back(node);
}

void Orchestrator::addTask(const Task& task) {
    taskQueue.push_back(task);
}

void Orchestrator::scheduleTasks() {
    for (Task& task : taskQueue) {
        for (Node& node : nodes) {
            if (node.available() && 
                task.getCPU() <= node.getAvailableCPU() && 
                task.getMemory() <= node.getAvailableMemory()) {
                
                node.executeTask(task);
                task.markCompleted();
                break;
            }
        }
    }
}
