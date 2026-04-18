#include "../Header/TaskManager.h"
#include <string>
#include <limits>
#include <stdlib.h>
#include <iomanip>
using namespace std;
void TaskManager::ViewUserProjects()
{
    system("cls");
    int userId;
    cout << endl
         << endl
         << endl
         << endl
         << indent << "Enter User ID to view their projects: ";
    cin >> userId;

    if (users.count(userId))
    {
        string name = users[userId].GetName();

        users[userId].ViewProjects(name);
    }
    else
    {
        cout << indent << "User not found!\n";
    }
}