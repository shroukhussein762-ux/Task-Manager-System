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
    void ViewFilteredTasks();

    public:
    TaskManager();
    void run();
};


#endif