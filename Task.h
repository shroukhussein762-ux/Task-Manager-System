<<<<<<< HEAD
#ifndef TASK_H
#define TASK_H
#include <iostream>
using namespace std;
class Task
{
private:
    int id;
    string title, status, description;

public:
    Task() : id(-1), title(""), status(""), description("") {}
    Task(int id, const string& title, const string& description);
    int GetId();
    string GetTitle();
    string GetStatus();
    string GetDescription();

    void ChangeStatus(const string& NewStatus);
    void Display();
};
#endif
=======
#ifndef TASK_H
#define TASK_H
#include <iostream>
using namespace std;
class Task
{
private:
    int id;
    string title, status, description;

public:
    Task() : id(-1), title(""), status(""), description("") {}
    Task(int id, const string& title, const string& description);
    int GetId();
    string GetTitle();
    string GetStatus();
    string GetDescription();

    void ChangeStatus(const string& NewStatus);
    void Display();
};
#endif
>>>>>>> 4d09b1b (Enhance task management with OOP principles and enums)
