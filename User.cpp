#include "User.h"
User::User(int Id, const string &Name)
{
    this->Id = Id;
    this->Name = Name;
    ProjectCounter = 1;
}

int User::GetId()
{
    return Id;
}

string User::GetName()const
{
    return Name;
}

void User::CreateProject(const string &NewProjectName)
{
    projects[ProjectCounter] = Project(ProjectCounter, NewProjectName);
    ProjectCounter++;
}

Project *User::GetProjectById(int ProjectId)
{
    if (projects.count(ProjectId))
    {
        return &projects[ProjectId];
    }
    else
        return nullptr;
}

void User::ViewProjects()
{
    if (projects.empty())
    {
        cout << "No projects available.\n";
        return;
    }

    for (auto &p : projects)
    {
        cout << "Project ID: " << p.second.GetId()
             << " | Name: " << p.second.GetName() << endl;
    }
}