#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

enum class TaskState {
    WAITING, 
    RUNNING, 
    COMPLETED
};

class Task {
private:
    int id;
    int requiredCPU;
    int requiredMemory;
    int priority; // higher value means higher priority
    TaskState state;
    std::vector<int> dependencies; // IDs of tasks this task depends on

public:
    Task(int _id, int _cpu, int _mem, int _priority);

    // Getters
    int getId() const;
    int getCPU() const;
    int getMemory() const;
    TaskState getState() const;
    int getPriority() const;
    const std::vector<int>& getDependencies() const;

    // Setters
    void setState(TaskState _state);
    void addDependency(int taskId);
    void removeDependency(int taskId);
};

#endif // TASK_H
