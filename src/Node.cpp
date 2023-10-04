#include "Orchestrator.h"

Orchestrator::Orchestrator() {}

void Orchestrator::addNode(const Node& node) {
    nodes.push_back(node);
}

void Orchestrator::addTask(const Task& task) {
    taskQueue.push(task);
}

void Orchestrator::distributeTasks() {
    for (Node& node : nodes) {
        if (taskQueue.empty()) {
            break;
        }
        if (node.available()) {
            std::vector<Task> tasksForNode;
            while (!taskQueue.empty() && tasksForNode.size() < node.getAvailableCPU()) {
                tasksForNode.push_back(taskQueue.top());
                taskQueue.pop();
            }
            node.executeTasks(tasksForNode);
        }
    }
}

void Orchestrator::scheduleTasks() {
    distributeTasks();
}

void Orchestrator::handleTaskDependencies(Task& task) {
    // todo: handle tasks that depend on other task or tasks
}
