#include "../Header/TaskManager.h"
#include <string>
#include <limits>
#include <stdlib.h>
#include <iomanip>
using namespace std;
void TaskManager::ViewTasks()
{
    system("cls");
    int userId, projectId;

    cout << endl
         << endl
         << endl
         << endl
         << indent << "User ID: ";
    cin >> userId;
    if (!users.count(userId))
    {
        cout << indent << "User not found!\n";
        return;
    }
    cout << indent << "Project ID: ";
    cin >> projectId;
    Project *p = users[userId].GetProjectById(projectId);
    if (!p)
    {
        cout << indent << "Project not found!\n";
        return;
    }

    p->ViewTasks();
}