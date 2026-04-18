#include "../Header/TaskManager.h"
#include <string>
#include <limits>
#include <stdlib.h>
#include <iomanip>
using namespace std;
void TaskManager::run()
{
    system("cls");
    int choice;
    while (true)
    {
        system("cls");
        cout << "\n"
             << indent << "============================================" << endl;
        cout << indent << "        TASK MANAGEMENT SYSTEM v1.0         " << endl;
        cout << indent << "============================================" << endl;

        cout << "\n"
             << indent << " [ USER MANAGEMENT ]" << endl;
        cout << indent << "  1. Create New User" << endl;
        cout << indent << "  2. View All Users" << endl;
        cout << indent << "  3. Delete User" << endl;

        cout << "\n"
             << indent << " [ PROJECT MANAGEMENT ]" << endl;
        cout << indent << "  4. Create New Project" << endl;
        cout << indent << "  5. View User Projects" << endl;
        cout << indent << "  6. Delete Project" << endl;

        cout << "\n"
             << indent << " [ TASK MANAGEMENT ]" << endl;
        cout << indent << "  7. Add Task to Project" << endl;
        cout << indent << "  8. Update Task Status" << endl;
        cout << indent << "  9. View All Tasks" << endl;
        cout << indent << "  10. Filter Tasks By Status" << endl;
        cout << indent << "  11. Delete Task" << endl;

        cout << "\n"
             << indent << " --------------------------------------------" << endl;
        cout << indent << "  0. Exit & Save Changes" << endl;
        cout << indent << " --------------------------------------------" << endl;
        cout << "\n"
             << indent << " Enter choice: ";
        if (!(cin >> choice))
        {
            cout << indent << "Error: Please enter a valid number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << indent << "Press Enter to continue...";
            cin.get();

            continue;
        }

        if (choice == 0)
        {
            saveData();
            exit(0);
        }

        switch (choice)
        {
        case 1:
            CreateUser();
            break;
        case 2:
            ViewUsers(true);
            break;
        case 3:
            DeleteUser();
            break;
        case 4:
            CreateProject(-1);
            break;
        case 5:
            ViewUserProjects();
            break;
        case 6:
            DeleteProject();
            break;
        case 7:
            AddTask(-1,-1);
            break;
        case 8:
            UpdateTaskStatus();
            break;
        case 9:
            ViewTasks();
            break;
        case 10:
            ViewFilteredTasks();
            break;
        case 11:
            DeleteTask();
            break;
        default:
            cout << indent << "Invalid choice!\n";
            break;
        }

        if (choice != 0)
        {
            cout << "\n"
                 << indent << "Press Enter to continue...";
            cin.ignore();
           cin.get();
            system("cls");
        }
    }
}