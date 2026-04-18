#include "../Header/Project.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
// Filters and displays tasks based on a specific status
void Project::ViewTasksByStatus() const
{

    if (tasks.empty())
    {
        cout << "\n"
             << indent << "[!] No tasks found in this project.\n";
        return;
    }
    // Display status selection menu
    cout << "\n"
         << indent << "Filter by status:" << endl;
    cout << indent << "  1. To Do" << endl;
    cout << indent << "  2. In Progress" << endl;
    cout << indent << "  3. Done" << endl;
    cout << indent << "  Choice: ";

    int choice;
    string targetStatus;

    // Input validation loop
    while (true)
    {
        if (!(cin >> choice) || (choice < 1 || choice > 3))
        {

            cout << "\n"
                 << indent << "Error: Please enter a valid number (1, 2, or 3)!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << indent << "Press Enter to try again...";
            cin.get();
            continue;
        }
        if (choice == 1)
            targetStatus = "To Do";
        else if (choice == 2)
            targetStatus = "In Progress";
        else if (choice == 3)
            targetStatus = "Done";
        else
            return;
        break;
    }
    // Header for the filtered table
    bool found = false;
    cout << "\n"
         << indent << string(85, '=') << endl;
    cout << "\n"
         << indent + "           " << "--- Showing Tasks with Status: [" << targetStatus << "] ---" << endl
         << endl;
    cout << indent << string(85, '=') << endl;

    cout << indent << left << setw(6) << "ID"
         << " | " << setw(15) << "Status"
         << " | " << setw(20) << "Title"
         << " | " << "Description" << endl;
    cout << indent << string(85, '-') << endl;
    for (const auto &t : tasks)
    {
        if (t.second.GetStatus() == targetStatus)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << indent << "[!] No tasks currently in this status.\n";
        return;
    }
    // Iterate through tasks and display only those matching the status
    for (const auto &t : tasks)
    {
        if (t.second.GetStatus() == targetStatus)
        {
            cout << indent << left << setw(6) << t.first
                 << " | " << setw(15) << t.second.GetStatus()
                 << " | " << setw(20) << t.second.GetTitle()
                 << " | " << t.second.GetDescription() << endl;
            found = true;
        }
    }

    cout << indent << string(85, '=') << endl;
}