<<<<<<< HEAD
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "User.h"
#include <vector>
#include<map>

class TaskManager{
    private:
    map<int,User>users;
    int UserCounter;


    void CreateUser();
    void ViewUsers();
    void CreateProject();
    void AddTask();
    void UpdateTaskStatus();
    void ViewTasks();

    public:
    TaskManager();
    void run();
};


=======
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "User.h"
#include <vector>
#include<map>

class TaskManager{
    private:
    map<int,User>users;
    int UserCounter;


    void CreateUser();
    void ViewUsers();
    void CreateProject();
    void AddTask();
    void UpdateTaskStatus();
    void ViewTasks();

    public:
    TaskManager();
    void run();
};


>>>>>>> 4d09b1b (Enhance task management with OOP principles and enums)
#endif