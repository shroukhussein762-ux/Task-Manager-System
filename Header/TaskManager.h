#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include "User.h"
#include <map>
#include<set>
// Main controller class that manages users, projects, and system flow
class TaskManager
{
private:
    std::map<int, User> users;// Stores all users registered in the system
    int UserCounter;// Tracks the next available user ID
    std::set<int> availableIdsForUser;// Reuses IDs from deleted users
// User Management
    void CreateUser();
    void ViewUsers(bool cls) const;
    void DeleteUser();
    // Project Management
    void CreateProject(int userId);
    void ViewUserProjects();
    void DeleteProject();
    // Task Management
    void AddTask(int userId, int projectId);
    void UpdateTaskStatus();
    void ViewTasks();
    void ViewFilteredTasks();
    void DeleteTask();

    // File I/O operations
    void saveData();
    void loadData();

public:
// Entry point of the application
    TaskManager();
    void run();
};
#endif