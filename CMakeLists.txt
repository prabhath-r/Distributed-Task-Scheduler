cmake_minimum_required(VERSION 3.10)
project(DistributedTaskOrchestrator)

# Standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(include)

add_executable(orchestrator
    src/main.cpp
    src/Node.cpp
    src/Task.cpp
    src/Orchestrator.cpp
)

# Enable testing
enable_testing()

# Unit Testing
add_subdirectory(lib/Catch2)
include_directories(${CATCH_INCLUDE_DIR})

# Test executable
add_executable(tests
    tests/test_Node.cpp
    tests/test_Task.cpp
    tests/test_Orchestrator.cpp
)

target_link_libraries(tests Catch2::Catch2)

# Register the test executable
add_test(NAME tests COMMAND tests)
