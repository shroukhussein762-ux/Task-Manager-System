#ifndef TASK_H
#define TASK_H
#include <iostream>
using namespace std;
// Definition of available task statuses
enum Status { TODO, IN_PROGRESS, DONE };
class Task
{
private:
    int id;
    string title, description;
    Status status;
    int priority;

public:
    Task() : id(-1), title(""), status(TODO), description("3") {}
    Task(int id, const string& title, const string& description,int priority);
    int GetId();
    string GetTitle();
    string GetStatus();
    string GetDescription();

    void ChangeStatus(int choice);
    void Display();
};
#endif
