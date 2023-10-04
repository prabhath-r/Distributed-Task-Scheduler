#include <catch.hpp>
#include "Node.h"
#include "Task.h"
#include "Orchestrator.h"

TEST_CASE("Orchestrator Distribute Tasks", "[Orchestrator]") {
    Node node1("Node 1");
    Node node2("Node 2");
    Node node3("Node 3");

    Orchestrator orchestrator({node1, node2, node3});

    std::vector<Task> tasks = {Task(1, 5), Task(2, 7), Task(3, 4)};
    orchestrator.distributeTasks(tasks);

    REQUIRE(node1.getTasks().size() == 1);
    REQUIRE(node2.getTasks().size() == 1);
    REQUIRE(node3.getTasks().size() == 1);
}

TEST_CASE("Orchestrator Monitor Nodes", "[Orchestrator]") {
    Node node1("Node 1");
    
    Node node2("Node 2");
    Node node3("Node 3");

    Orchestrator orchestrator({node1, node2, node3});

    std::vector<Task> tasks = {Task(1, 3), Task(2, 2)};
    orchestrator.distributeTasks(tasks);

    std::stringstream output;     // Redirecting output to stringstream
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    orchestrator.monitorNodes();
    std::cout.rdbuf(oldCout); 

    REQUIRE(output.str() == "Node Node 1 is processing Task 1\nNode Node 2 is processing Task 2\nNode Node 1 completed Task 1\nNode Node 2 completed Task 2\nNode Node 3 is processing Task 3\nNode Node 3 completed Task 3\n");
}

