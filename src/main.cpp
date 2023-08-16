#include <iostream>
#include "Node.h"
#include "Task.h"
#include "Orchestrator.h"

int main() {

    Node node1("Node 1");
    Node node2("Node 2");
    Node node3("Node 3");

    std::vector<Task> tasks = {Task(1, 5), Task(2, 7), Task(3, 4)};

    //Use orchestrator to define three nodes
    Orchestrator orchestrator({node1, node2, node3});

    // Task distribution
    orchestrator.distributeTasks(tasks);

    orchestrator.monitorNodes();

    return 0;
}
