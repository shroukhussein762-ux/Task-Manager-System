#include "../Header/TaskManager.h"
#include <string>
#include <limits>
using namespace std;

// Creates a new project for a user and offers an immediate task-adding loop
void TaskManager::CreateProject(int userId)
{
    system("cls");

    string name;
    if (userId == -1)
    {
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << indent << "Enter user ID: ";
        if (!(cin >> userId))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << indent << "Invalid ID format!" << endl;
            return;
        }
    }
    else
    {
        cout << endl
             << endl
             << endl
             << endl;
    }

    if (users.count(userId))
    {
        cout << endl
             << indent << "Enter project name: ";
        cin >> ws;
        getline(cin, name);

        // Logic: Project is created inside the User object
        users[userId].CreateProject(name);

        // Optimization: Get the ID of the project we just created
        // Note: Make sure users[userId].GetLatestProjectId() exists or use a similar logic
        int idToUse = users[userId].GetId();
        cout << indent << "Project '" << name << "' added successfully! | Project ID: " << idToUse << endl;

        int choice;
        bool firstTask = true;

        while (true)
        {
            if (firstTask)
                cout << "\n"
                     << indent << "Do you want to add tasks to this project?\n";
            else
                cout << "\n"
                     << indent << "Do you want to add another task?\n";

            cout << indent << "1. Yes  2. No : ";

            if (!(cin >> choice) || (choice < 1 || choice > 2))
            {

                cout << "\n\n"
                     << indent << "Error: Please enter a valid number (1, 2)!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << indent << "Press Enter to try again...";
                cin.get();
                system("cls");
                continue;
            }

            if (choice == 1)
            {
                AddTask(userId, idToUse);
                firstTask = false;
                continue;
            }
            else
            {
                break;
            }
        }
    }
    else
        cout << indent << "User not found!\n";
}