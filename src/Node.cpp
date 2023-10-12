#include "node.h"
#include <thread>
#include <algorithm>

void Node::processTask(Task& task) {
    // Simulating task processing
    std::this_thread::sleep_for(std::chrono::seconds(1));
    task.setState(TaskState::COMPLETED);
}

Node::Node(int _id, int _cpu, int _mem, int _threads)
    : id(_id), totalCPU(_cpu), totalMemory(_mem), isAvailable(true), threads(_threads) {}

int Node::getId() const {
    return id;
}

int Node::getAvailableCPU() const {
    return totalCPU;  // Simplification for now
}

int Node::getAvailableMemory() const {
    return totalMemory;  // Simplification for now
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

void Node::executeTasks(std::vector<Task>& tasks) {
    for (Task& task : tasks) {
        if (task.getState() == TaskState::WAITING) {
            processTask(task);
        }
    }
}
