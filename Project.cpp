#include "Project.h"
#include <iostream>
using namespace std;
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
{int prio;
    cout << "Enter Priority (1: High, 2: Medium, 3: Low): ";
    cin >> prio;
    tasks[taskCounter] = Task(taskCounter, title, description,prio);
    taskCounter++;
}
void Project::UpdateTaskStatus(int taskId)
{
    if (tasks.count(taskId))
    {int statusChoice;
    cout << "Select New Status:\n1. To Do\n2. In Progress\n3. Done\nChoice: ";
    cin >> statusChoice;
        tasks[taskId].ChangeStatus(statusChoice);
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
}

void Project::ViewTasksByStatus() {
    if (tasks.empty()) {
        cout << "No tasks found in this project.\n";
        return;
}

    int choice;
    cout << "Filter by status:\n1. To Do\n2. In Progress\n3. Done\nChoice: ";
    cin >> choice;

  string targetStatus;
    if (choice == 1) targetStatus = "To Do";
    else if (choice == 2) targetStatus ="In Progress";
    else if (choice == 3) targetStatus = "Done";
    else {
        cout << "Invalid choice.\n";
        return;
    }

    bool found = false;
    cout << "\n--- Filtered Tasks ---\n";
    for (auto &t : tasks) {
        if (t.second.GetStatus() == targetStatus) { 
        t.second.Display();
            found = true;
        }
    }

    if (!found) {
        cout << "No tasks found with this status.\n";
    }
}