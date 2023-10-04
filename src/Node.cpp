#include "../include/Node.h"

Node::Node(int _id, int _cpu, int _mem) : 
    id(_id), totalCPU(_cpu), totalMemory(_mem), isAvailable(true) {}

int Node::getId() const {
    return id;
}

int Node::getAvailableCPU() const {
    return totalCPU;
}

int Node::getAvailableMemory() const {
    return totalMemory;
}

bool Node::available() const {
    return isAvailable;
}

void Node::markBusy() {
    isAvailable = false;
}

void Node::markAvailable() {
    isAvailable = true;
}

void Node::executeTask(const Task& task) {
    if (task.getCPU() <= totalCPU && task.getMemory() <= totalMemory) {
        markBusy();
        // Here you can add logic to simulate task execution
    }
}
