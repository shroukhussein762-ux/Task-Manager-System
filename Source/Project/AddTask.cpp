#include "../Header/Project.h"
#include <iomanip>
#include <limits>
using namespace std;
// Adds a new task to the project with priority validation
void Project::AddTask(const string &title, const string &description)
{
    int prio;
    // Loop until a valid priority (1-3) is entered
    while (true)
    {
        cout << '\n'
             << indent << "Enter Priority (1: High, 2: Medium, 3: Low): ";
        if (!(cin >> prio) || (prio < 1 || prio > 3))
        {
            cout << "\n"
                 << indent << "Error: Please enter a valid number (1, 2, or 3)!" << endl;

            // Clear error flags and skip invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << indent << "Press Enter to try again...";
            cin.get();
            system("cls"); // Clears the screen for better UI
            continue;
        }
        break;
    }
    // Assign a unique ID and store the task
    int idToUse = GetNextAvailableTaskId();
    tasks[idToUse] = Task(idToUse, title, description, prio);

    cout << indent << "Task added successfully with ID: " << idToUse << endl;
}