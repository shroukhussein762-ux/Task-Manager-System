#include "../Header/User.h"
Project *User::GetProjectById(int ProjectId)
{
    if (projects.count(ProjectId))
    {
        return &projects[ProjectId];
    }
    else
        return nullptr;
}