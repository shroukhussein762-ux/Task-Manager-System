#include "../Header/User.h"
using namespace std;
void User::CreateProject(const string &NewProjectName)
{
    int idToUse = GetNextAvailableProjectId();
    projects[idToUse] = Project(idToUse, NewProjectName);
}