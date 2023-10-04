#ifndef NODE_H
#define NODE_H

#include "Task.h"

class Node {
private:
    int id; // unique identifier for the node
    int totalCPU; // total CPU resources
    int totalMemory; // total Memory resources
    bool isAvailable; // node availability status

public:
    Node(int _id, int _cpu, int _mem) : 
        id(_id), totalCPU(_cpu), totalMemory(_mem), isAvailable(true) {}

    int getId() const { return id; }
    int getAvailableCPU() const { return totalCPU; }
    int getAvailableMemory() const { return totalMemory; }
    bool available() const { return isAvailable; }

    void markBusy() { isAvailable = false; }
    void markAvailable() { isAvailable = true; }

    // Simulating task execution (for now, just marking node as busy)
    void executeTask(const Task& task) {
        if (task.getCPU() <= totalCPU && task.getMemory() <= totalMemory) {
            markBusy();
            // Here you can add logic to simulate task execution
        }
    }
};


#endif // NODE_H
