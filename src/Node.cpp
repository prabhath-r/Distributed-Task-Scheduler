#include "Node.h"
#include <iostream>
#include <thread>  

Node::Node(std::string nodeId) : nodeId(nodeId) {}

void Node::addTask(const Task& task) {
    tasks.push_back(task);
}

void Node::startProcessing() {
    for (Task& task : tasks) {
        std::cout << "Node " << nodeId << " is processing Task " << task.getId() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(task.getDuration()));  // simulating task processing by sleeping for the task's duration

        completeTask(task.getId());
    }
}

void Node::completeTask(int taskId) {
    std::cout << "Node " << nodeId << " completed Task " << taskId << std::endl;
}
