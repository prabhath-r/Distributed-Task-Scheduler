#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include "Node.h"
#include <vector>

class Orchestrator {
private:
    std::vector<Node> nodes; // list of nodes
    std::vector<Task> taskQueue; // queue of tasks

public:
    void addNode(const Node& node) {
        nodes.push_back(node);
    }

    void addTask(const Task& task) {
        taskQueue.push_back(task);
    }

    // Basic FCFS scheduling for now
    void scheduleTasks() {
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
};
#endif // ORCHESTRATOR_H