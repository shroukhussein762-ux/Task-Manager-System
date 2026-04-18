#ifndef PROJECT_H
#define PROJECT_H
#include "Task.h"
#include <string>
#include <set>
#include <map>

#include <fstream>
class Project
{
private:
    int Id;
    std::string name;
    std::map<int, Task> tasks;
    std::set<int> availableIdsForTask; // Stores IDs that can be reused
    int taskCounter;

public:
    // Constructors
    Project() {};

    Project(int id, const std::string &name);
    // Getters and ID management
    int GetId() const;
    std::string GetName() const;
    int GetNextAvailableTaskId();
    void SetId(int Id);
    // Task operations
    void AddTask(const std::string &title, const std::string &description);
    void ViewTasks() const;
    void UpdateTaskStatus(int TaskId);
    void ViewTasksByStatus() const;
    void DeleteTask(int taskId);
    // Data persistence
    void Save(std::ostream &outFile) const;
    static Project Load(std::istream &inFile);
};
#endif