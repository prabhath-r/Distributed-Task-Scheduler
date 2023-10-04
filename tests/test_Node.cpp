#include <catch.hpp>
#include "Node.h"
#include "Task.h"

TEST_CASE("Node Add Task", "[Node]") {
    Node node("Test Node");
    Task task(1, 5);
    node.addTask(task);

    REQUIRE(node.getTasks().size() == 1);
    REQUIRE(node.getTasks()[0].getId() == task.getId());
    REQUIRE(node.getTasks()[0].getDuration() == task.getDuration());
}

TEST_CASE("Node Complete Task", "[Node]") {
    Node node("Test Node");
    Task task(1, 5);
    node.addTask(task);
    
    // Redirect cout to a stringstream to capture output
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    node.completeTask(task.getId());
    
    // Reset cout redirection
    std::cout.rdbuf(oldCout);

    // Assertions based on the captured output
    REQUIRE(output.str() == "Node Test Node completed Task 1\n");
}
