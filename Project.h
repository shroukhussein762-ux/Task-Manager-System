#ifndef PROJEST_H
#define PROJECT_H
#include "Task.h"
#include <vector>
#include <map>
using namespace std;

class Project
{
private:
    int Id;
    string name;
    map<int, Task> tasks;
    int taskCounter;

public:
    Project() : Id(1), name(""), taskCounter(1)
    {
    }

    Project(int id, const string &name);

    int GetId();
    string GetName();

    void AddTask(const string &title, const string &description);
    void ViewTasks();
    void UpdateTaskStatus(int TaskId);
    void ViewTasksByStatus();
};
#endif