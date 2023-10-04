#include "Task.h"

Task::Task(int _id, int _cpu, int _mem) : 
    id(_id), requiredCPU(_cpu), requiredMemory(_mem), isCompleted(false) {}

int Task::getId() const {
    return id;
}

int Task::getCPU() const {
    return requiredCPU;
}

int Task::getMemory() const {
    return requiredMemory;
}

bool Task::completed() const {
    return isCompleted;
}

void Task::markCompleted() {
    isCompleted = true;
}
