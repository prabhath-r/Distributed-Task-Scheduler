#ifndef TASK_H
#define TASK_H

class Task {
public:
    Task(int id, int duration);

    int getId() const {
        return id;
    }

    int getDuration() const {
        return duration;
    }

    void setAlgorithm(const std::string& algorithm) {
        this->algorithm = algorithm;
    }

    void setOutputFormat(const std::string& outputFormat) {
        this->outputFormat = outputFormat;
    }

private:
    int id;
    int duration;
    std::string algorithm;
    std::string outputFormat;
};

#endif
