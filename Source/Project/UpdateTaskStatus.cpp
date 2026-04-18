#include "../Header/Project.h"
using namespace std;
// Finds a task by ID and toggles its current status
void Project::UpdateTaskStatus(int taskId)
{ // Check if the task exists in the map
    if (tasks.count(taskId))
    {
        tasks[taskId].ChangeStatus(); // Call Task's method to update status
        cout << indent << "Status updated successfully.\n";
    }
    else
        cout << indent << "Task not found.\n";
}