#include "../Header/TaskManager.h"
#include <string>
#include <limits>
#include <stdlib.h>
#include <iomanip>
using namespace std;
// Deletes a user and recycles their ID for future use
void TaskManager::DeleteUser()
{
    system("cls");
    int userId;
    cout << endl
         << endl
         << endl
         << endl;
    cout << indent << "Enter User ID to delete: ";
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
        if (users.erase(userId))
        {
            availableIdsForUser.insert(userId);

            cout << endl
                 << indent << "---User and all their data deleted successfully.---\n";
        }
        else
        {
            cout << indent << "---User not found!---\n";
        }
        break;
    }
}