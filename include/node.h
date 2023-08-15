#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include "Task.h"

class Node {
public:
    Node(std::string nodeId);
    void addTask(const Task& task);
    void startProcessing();
    void completeTask(int taskId);

    const std::vector<Task>& getTasks() const {
        return tasks;
    }

private:
    std::string nodeId;
    std::vector<Task> tasks;
};

#endif
