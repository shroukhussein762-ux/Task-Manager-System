#include "../Header/TaskManager.h"
#include <string>
#include <limits>
#include <iostream>
using namespace std;
// Handles the deletion of a specific project for a given user
void TaskManager::DeleteProject()
{
    system("cls");
    int userId, projectId;
    cout << endl
         << endl
         << endl
         << endl
         << indent << "Enter User ID: ";
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
            cout << indent << "Enter Project ID to delete: ";
            cin >> projectId;
            users[userId].DeleteProject(projectId);
        }
        else
            cout << indent << "User not found!\n";
        break;
    }
}