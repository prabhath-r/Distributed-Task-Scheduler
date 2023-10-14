# Distributed-Task-Scheduler
System aimed to streamline the allocation of tasks across a network of nodes, optimizing resource utilization, and minimizing task execution latency.

The Distributed Task Scheduler System is a dynamic solution designed to optimize the distribution of computational tasks across a network of nodes. My primary focus with this project is to schedule and prioritizing tasks, managing resources, and resolving dependencies, ensuring a seamless and efficient computational experience.

## Overview

The system serves as a robust foundation for any distributed computing environment, ensuring optimal task execution, minimized resource wastage, and maximized throughput. The modular design promises easy integration of future enhancements, catering to evolving computational needs.

## Features

- **Dynamic Task Management:** Uses priority queues to ensure tasks with higher priorities are executed first.
- **Resource Allocation:** Checks computational nodes for available CPU cores and memory before task dispatch.
- **Dependency Resolution:** Sophisticated system to ensure tasks are executed in the correct order based on dependencies.

## Future Enhancements

- Introducing multithreading for concurrent task processing.
- Dynamic resource rebalancing.
- Support for intricate task relationship structures.
- Performance analytics dashboard.

## Getting Started

### Prerequisites

- C++ Compiler (Recommend GCC or Clang)
- Standard Template Library (STL)

### Installation

1. Clone the repository:
   `git clone https://github.com/prabhath-r/DistributedTaskScheduler.git`
   
3. Navigate to the project directory and compile:
   `g++ -o scheduler main.cpp `
   
3. After successful compilation, run the binary
   `./scheduler --help`

### Usage
I've designed this project for simplicity and ease of use. Since the development of the dashboard is in progress, the primary way to interact with the Distributed Task Scheduler System is through the command line or terminal, following the instructions above.

### Feedback
As this is an evolving project, feedback on usability, bugs, or feature requests is highly appreciated. You can provide feedback through the project's GitHub issues section or directly via email to prabhathr96@gmail.com

### License
This project is licensed under the MIT License. See the LICENSE.md file for details.
