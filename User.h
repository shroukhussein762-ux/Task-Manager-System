#ifndef USER_H
#define USER_H

#include "Project.h"
#include <vector>
#include<map>

class User
{
private:
    int Id;
    string Name;
    map<int,Project> projects;
    int ProjectCounter;

public:
    User() : Id(-1), Name(""), ProjectCounter(1) {}
    User(int Id, const string& Name);

    int GetId();
    string GetName()const;

    void CreateProject(const string& NewProjectName);
    void ViewProjects();

    Project *GetProjectById(int ProjectId);
};

#endif