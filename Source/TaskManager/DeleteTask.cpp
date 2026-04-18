#include "../Header/TaskManager.h"
#include <string>
#include <limits>
#include <iostream>
using namespace std;

// Navigates the hierarchy (User -> Project) to delete a specific task
void TaskManager::DeleteTask()
{
    system("cls");
    int userId, projectId, taskId;
    cout << endl
         << endl
         << endl
         << endl
         << indent << "User ID: ";
    while (true)
    {
        if (!(cin >> userId))
        {

            cout << "\n"
                 << indent << "Error: Please enter a valid number !" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << indent << "Press Enter to try again...";
            cin.get();
            system("cls");
            continue;
        }
        if (users.count(userId))
        {
            cout << indent << "Project ID: ";
            cin >> projectId;
            Project *p = users[userId].GetProjectById(projectId);
            if (p)
            {
                cout << indent << "Task ID to delete: ";
                cin >> taskId;
                p->DeleteTask(taskId);
            }
            else
                cout << indent << "Project not found!\n";
        }
        else
            cout << indent << "User not found!\n";
        break;
    }
}