#include "../Header/TaskManager.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;
// Creates a new user with ID reuse logic and an optional project creation flow
void TaskManager::CreateUser()
{
    system("cls");
    string name;
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << indent << "Enter user name: ";
    cin >> ws;
    getline(cin, name);
    // Check for duplicate usernames to maintain data integrity
    for (auto const &[id, user] : users)
    {
        if (user.GetName() == name)
        {
            cout << indent << "Error: User name '" << name << "' already exists!" << endl;
            return;
        }
    }
    // Logic: Reuse a deleted ID or increment the counter
    int idToUse;
    if (!availableIdsForUser.empty())
    {
        idToUse = *availableIdsForUser.begin();
        availableIdsForUser.erase(availableIdsForUser.begin());
    }
    else
    {
        idToUse = UserCounter++;
    }

    // Initialize the new User object
    users[idToUse] = User(idToUse, name);
    cout << indent << "User created successfully! | User ID: " << idToUse << endl;
    int choice;
    // Input validation loop for optional project creationn
    while (true)
    {
        cout << "\n\n\n"
             << indent << "Do you want to add a project for this user?\n"
             << indent << " 1. Yes  2. No : ";

        if (!(cin >> choice) || (choice < 1 || choice > 2))
        {

            cout << "\n"
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
            CreateProject(idToUse);
        }

        break;
    }
}