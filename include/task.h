#ifndef TASK_H
#define TASK_H

class Task {
private:
    int id; // unique identifier for the task
    int requiredCPU; // required CPU resources
    int requiredMemory; // required Memory resources
    bool isCompleted; // task completion status

public:
    Task(int _id, int _cpu, int _mem) : 
        id(_id), requiredCPU(_cpu), requiredMemory(_mem), isCompleted(false) {}

    int getId() const { return id; }
    int getCPU() const { return requiredCPU; }
    int getMemory() const { return requiredMemory; }
    bool completed() const { return isCompleted; }

    void markCompleted() { isCompleted = true; }
};

#endif // TASK_H
