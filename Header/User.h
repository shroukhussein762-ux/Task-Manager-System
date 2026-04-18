#ifndef USER_H
#define USER_H
#include "Project.h"
#include <map>
#include <set>
#include <string>
#include <fstream>

class User
{
private:
    int Id;
    std::string Name;
    std::map<int, Project> projects;      // Collection of projects owned by the user
    std::set<int> availableIdsForProject; // Reusable project IDs
    int ProjectCounter;

public:
    // Constructors
    User() {};
    User(int Id, const std::string &Name);
    // Getters and ID Management
    int GetId() const;
    std::string GetName() const;
    int GetNextAvailableProjectId();
    Project *GetProjectById(int ProjectId);
    // Project Operations
    void CreateProject(const std::string &NewProjectName);
    void ViewProjects(const std::string name) const;
    void DeleteProject(int projectId);

    //// File I/O operations
    void Save(std::ostream &outFile) const;
    void SetId(int Id);
    static User Load(std::istream &inFile);
};

#endif