#include "Orchestrator.h"

Orchestrator::Orchestrator() {}

void Orchestrator::addNode(const Node& node) {
    nodes.push_back(node);
}

void Orchestrator::addTask(const Task& task) {
    taskQueue.push(task);
    tasksVector.push_back(task); // add to the vector for easy lookup
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
    const std::vector<int>& dependencies = task.getDependencies();

    if (dependencies.empty()) {
        return;
    }

    bool allDependenciesCompleted = true;
    for (int dependencyId : dependencies) {
        Task& dependencyTask = getTaskById(dependencyId);

        if (dependencyTask.getState() != TaskState::COMPLETED) {
            allDependenciesCompleted = false;
            break;
        }
    }

    if (!allDependenciesCompleted) {
        task.setState(TaskState::WAITING);
    }
}

Task& Orchestrator::getTaskById(int id) {
    for (Task& t : tasksVector) {
        if (t.getId() == id) {
            return t;
        }
    }
    throw std::runtime_error("Task ID not found.");
}
