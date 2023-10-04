#include <catch.hpp>
#include "Task.h"

TEST_CASE("Task Initialization", "[Task]") {
    Task task(1, 5);

    REQUIRE(task.getId() == 1);
    REQUIRE(task.getDuration() == 5);
}

TEST_CASE("Task Set Algorithm and Output Format", "[Task]") {
    Task task(1, 5);
    task.setAlgorithm("edge_detection");
    task.setOutputFormat("png");

    REQUIRE(task.getAlgorithm() == "edge_detection");
    REQUIRE(task.getOutputFormat() == "png");
}
