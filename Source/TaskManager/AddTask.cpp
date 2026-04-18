#include "../Header/TaskManager.h"
#include <string>
#include <limits>
#include <stdlib.h>
using namespace std;
// Facilitates adding a task by identifying the correct user and project
void TaskManager::AddTask(int userId, int projectId)
{
    system("cls");

    string title, desc;
    // Phase 1: Identify User
    if (userId == -1)
    {
        cout << endl
             << endl
             << endl
             << endl
             << indent << "User ID: ";
        if (!(cin >> userId))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << indent << "Invalid ID format!\n";
            return;
        }
    }
    if (!users.count(userId))
    {
        cout << indent << "User not found!\n";
        return;
    }
    // Phase 2: Identify Project
    if (projectId == -1)
    {
        cout << indent << "Project ID: ";
        if (!(cin >> projectId))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << indent << "Invalid ID format!\n";
            return;
        }
    }
    else
    {
        cout << "\n\n\n\n\n";
    }
    // Phase 3: Access Project and Add Task
    Project *p = users[userId].GetProjectById(projectId);
    if (!p)
    {
        cout << indent << "Project not found!\n";
        return;
    }
    // Phase 4: Collect Task Details
    cout << indent << "Task title: ";
    cin >> ws;
    getline(cin, title);
    cout << indent << "Description: ";
    getline(cin, desc);
    // Call the project's internal AddTask method
    p->AddTask(title, desc);
}
