#include "task.h"
#include <algorithm>

Task::Task(int _id, int _cpu, int _mem, int _priority)
    : id(_id), requiredCPU(_cpu), requiredMemory(_mem), priority(_priority), state(TaskState::WAITING) {}

int Task::getId() const {
    return id;
}

int Task::getCPU() const {
    return requiredCPU;
}

int Task::getMemory() const {
    return requiredMemory;
}

TaskState Task::getState() const {
    return state;
}

int Task::getPriority() const {
    return priority;
}

const std::vector<int>& Task::getDependencies() const {
    return dependencies;
}

void Task::setState(TaskState _state) {
    state = _state;
}

void Task::addDependency(int taskId) {
    dependencies.push_back(taskId);
}

void Task::removeDependency(int taskId) {
    dependencies.erase(std::remove(dependencies.begin(), dependencies.end(), taskId), dependencies.end());
}
