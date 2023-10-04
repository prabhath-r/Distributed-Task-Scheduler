#include "Orchestrator.h"
#include <iostream>

int main() {
    // Creating some nodes
    Node node1(1, 100, 1000); 
    Node node2(2, 200, 2000);

    // Creating some tasks
    Task task1(1, 50, 500);
    Task task2(2, 150, 1500);

    // Orchestrator
    Orchestrator orchestrator;
    orchestrator.addNode(node1);
    orchestrator.addNode(node2);

    orchestrator.addTask(task1);
    orchestrator.addTask(task2);

    orchestrator.scheduleTasks();

    // Check if tasks are completed
    if (task1.completed()) {
        std::cout << "Task 1 completed" << std::endl;
    }
    if (task2.completed()) {
        std::cout << "Task 2 completed" << std::endl;
    }

    return 0;
}

