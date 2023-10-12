#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include "Node.h"
#include "Task.h"
#include <vector>
#include <queue>
#include <stdexcept>

class Orchestrator {
private:
    std::vector<Node> nodes;
    std::priority_queue<Task> taskQueue; // tasks are ordered by priority
    void distributeTasks();
    Task& getTaskById(int id); // Internal method to get a task by its ID

public:
    Orchestrator();
    
    // Node and Task management
    void addNode(const Node& node);
    void addTask(const Task& task);

    // Scheduling
    void scheduleTasks();
    void handleTaskDependencies(Task& task);
};

#endif // ORCHESTRATOR_H
