#include "../Header/Task.h"
#include <iomanip>
#include <limits>
using namespace std;
// Allows the user to manually update the task's current status
void Task::ChangeStatus()
{
    int choice;
    while (true)
    {
        cout << indent << "--------------------------------------" << endl;
        cout << "\n"
             << indent << "Select New Status for this Task:" << endl;
        cout << indent << "  1. To Do" << endl;
        cout << indent << "  2. In Progress" << endl;
        cout << indent << "  3. Done" << endl;
        cout << indent << "  Choice: ";

       // Validate that the input is a number between 1 and 3
        if (!(cin >> choice) || (choice < 1 || choice > 3))
        {
            cout << "\n"
                 << indent << "Error: Please enter a valid number (1, 2, or 3)!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << indent << "Press Enter to try again...";
            cin.get();
            system("cls");
            continue;
        }
       
        break;
    }

  // Convert the integer choice back to the Status enum
    status = static_cast<Status>(choice - 1);
}