CXX = g++
CXXFLAGS = -I./include

all: scheduler

scheduler: src/Task.cpp src/Node.cpp src/Orchestrator.cpp src/main.cpp
    $(CXX) $(CXXFLAGS) src/Task.cpp src/Node.cpp src/Orchestrator.cpp src/main.cpp -o scheduler

clean:
    rm -f scheduler