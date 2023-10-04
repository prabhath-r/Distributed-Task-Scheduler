#ifndef NODE_H
#define NODE_H

#include "Task.h"
#include <string>
#include <vector>
#include <thread>
#include <mutex>

class Node {
private:
    int id;
    int totalCPU;
    int totalMemory;
    bool isAvailable;
    int threads; // number of threads the node has
    std::mutex mtx; // mutex for thread safety

    void processTask(Task& task); // private method to process a task

public:
    Node(int _id, int _cpu, int _mem, int _threads);
    
    // Getters
    int getId() const;
    int getAvailableCPU() const;
    int getAvailableMemory() const;
    bool available() const;

    // Node state methods
    void markBusy();
    void markAvailable();

    // Task methods
    void executeTasks(std::vector<Task>& tasks);
};

#endif // NODE_H
