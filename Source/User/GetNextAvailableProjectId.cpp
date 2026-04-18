#include "../Header/User.h"
using namespace std;
int User::GetNextAvailableProjectId()
{
    int idToUse;
    if (!availableIdsForProject.empty())
    {
        idToUse = *availableIdsForProject.begin();
        availableIdsForProject.erase(availableIdsForProject.begin());
    }
    else
    {
        idToUse = ProjectCounter++;
        Id = idToUse;
    }
    return idToUse;
}