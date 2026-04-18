#include "../Header/User.h"
using namespace std;
void User::DeleteProject(int projectId)
{
    if (projects.erase(projectId))
    {
        availableIdsForProject.insert(projectId);

        cout << indent << "Project ID [" << projectId << "] and all its tasks deleted successfully.\n";
    }
    else
    {
        cout << indent << "Error: Project ID not found.\n";
    }
}