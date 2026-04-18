#include "../Header/TaskManager.h"
#include <string>
#include <limits>
#include <stdlib.h>
#include <iomanip>
using namespace std;
void TaskManager::ViewUsers(bool cls) const
{
    if (cls)
        system("cls");
    if (users.empty())
    {
        cout << "\n"
             << indent << "[!] No users exist in the system.\n";
    }
    else
    {
        cout << "\n"
             << indent << "============================================" << endl;
        cout << indent << "             REGISTERED USERS               " << endl;
        cout << indent << "============================================" << endl;

        cout << indent << left << setw(10) << "User ID" << " | " << "User Name" << endl;
        cout << indent << "--------------------------------------------" << endl;

        for (auto const &u : users)
        {
            cout << indent << left << setw(10) << u.second.GetId()
                 << " | " << u.second.GetName() << endl;
        }
        cout << indent << "============================================" << endl;
    }
}