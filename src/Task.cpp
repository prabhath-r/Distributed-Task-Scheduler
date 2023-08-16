#include "Task.h"

Task::Task(int id, int duration) : id(id), duration(duration) {}

void Task::setAlgorithm(const std::string& algorithm) {
    this->algorithm = algorithm;
}

void Task::setOutputFormat(const std::string& outputFormat) {
    this->outputFormat = outputFormat;
}
