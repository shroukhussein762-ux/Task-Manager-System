#include "../Header/Project.h"
using namespace std;

// Removes a task by its ID and stores the ID for future reuse
void Project::DeleteTask(int taskId)
{ 
    
    // Try to erase the task from the map
    if (tasks.erase(taskId))
    { // Add the deleted ID to the set of available IDs
        availableIdsForTask.insert(taskId);

        cout << indent << "Task ID [" << taskId << "] deleted successfully.\n";
    }
    else
    {
        // If the ID doesn't exist in the map
        cout << indent << "Error: Task ID not found.\n";
    }
}