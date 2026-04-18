#include "../Header/Project.h"

// Determines the next ID for a task, prioritizing reused IDs over new ones
int Project::GetNextAvailableTaskId()
{
    int idToUse;
    // Check if there are any deleted IDs available for reuse
    if (!availableIdsForTask.empty())
    { // Take the smallest available ID
        idToUse = *availableIdsForTask.begin();
        availableIdsForTask.erase(availableIdsForTask.begin());
    }
    else
    {
        idToUse = taskCounter++; // Otherwise, use the counter and increment it
    }
    return idToUse;
}