<<<<<<< HEAD
#include "Project.h"
#include <iostream>

Project::Project(int Id, const string &name)
{
    this->Id = Id;
    this->name = name;
    taskCounter = 1;
}

int Project::GetId()
{
    return Id;
}

string Project::GetName()
{
    return name;
}

void Project::AddTask(const string &title, const string &description)
{
    tasks[taskCounter] = Task(taskCounter, title, description);
    taskCounter++;
}
void Project::UpdateTaskStatus(int taskId, const string &newStatus)
{
    if (tasks.count(taskId))
    {
        tasks[taskId].ChangeStatus(newStatus);
        cout << "Status updated successfully.\n";
    }
    else
        cout << "Task not found.\n";
}

void Project::ViewTasks()
{
    if (tasks.empty())
    {
        cout << "No tasks found.\n";
        return;
    }

    for (auto &t : tasks)
    {
        t.second.Display();
    }
=======
#include "Project.h"
#include <iostream>

Project::Project(int Id, const string &name)
{
    this->Id = Id;
    this->name = name;
    taskCounter = 1;
}

int Project::GetId()
{
    return Id;
}

string Project::GetName()
{
    return name;
}

void Project::AddTask(const string &title, const string &description)
{
    tasks[taskCounter] = Task(taskCounter, title, description);
    taskCounter++;
}
void Project::UpdateTaskStatus(int taskId, const string &newStatus)
{
    if (tasks.count(taskId))
    {
        tasks[taskId].ChangeStatus(newStatus);
        cout << "Status updated successfully.\n";
    }
    else
        cout << "Task not found.\n";
}

void Project::ViewTasks()
{
    if (tasks.empty())
    {
        cout << "No tasks found.\n";
        return;
    }

    for (auto &t : tasks)
    {
        t.second.Display();
    }
>>>>>>> 4d09b1b (Enhance task management with OOP principles and enums)
}