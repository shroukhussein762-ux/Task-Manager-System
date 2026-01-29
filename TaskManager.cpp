#include "TaskManager.h"
#include <string>
TaskManager::TaskManager()
{
    UserCounter = 1;
}

void TaskManager::CreateUser()
{
    string name;
    cout << "Enter user name: ";
    cin.ignore();
    getline(cin, name);
    for (auto const &[id, user] : users)
    {
        if (user.GetName() == name)
        {
            cout << "Error: User name '" << name << "' already exists!" << endl;
            return;
        }
    }
    users[UserCounter] = User(UserCounter, name);
    cout << "User created successfully! | User ID: " << UserCounter << endl;
    UserCounter++;
}

void TaskManager::ViewUsers()
{
    for (auto &u : users)
    {
        cout << "User ID: " << u.second.GetId()
             << " | Name: " << u.second.GetName() << endl;
    }
}

void TaskManager::CreateProject()
{
    int userId;
    string name;

    cout << "Enter user ID: ";
    cin >> userId;
    cout << "Enter project name: ";
    cin.ignore();
    getline(cin, name);
    if (users.count(userId))
    {
        users[userId].CreateProject(name);
    }
    else
        cout << "User not found!\n";
}

void TaskManager::AddTask()
{
    int userId, projectId;
    string title, desc;

    cout << "User ID: ";
    cin >> userId;
    cout << "Project ID: ";
    cin >> projectId;

    if (!users.count(userId))
    {
        cout << "User not found!\n";
        return;
    }

    Project *p = users[userId].GetProjectById(projectId);
    if (!p)
    {
        cout << "Project not found!\n";
        return;
    }

    cout << "Task title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Description: ";
    getline(cin, desc);

    p->AddTask(title, desc);
    cout << "Task added successfully.\n";
}

void TaskManager::UpdateTaskStatus()
{
    int userId, projectId, taskId;
    string status;

    cout << "User ID: ";
    cin >> userId;
    cout << "Project ID: ";
    cin >> projectId;
    cout << "Task ID: ";
    cin >> taskId;
    cout << "New Status: ";
    cin.ignore();
    getline(cin, status);
    if (!users.count(userId))
    {
        cout << "User not found!\n";
        return;
    }

    Project *p = users[userId].GetProjectById(projectId);
    if (!p)
    {
        cout << "Project not found!\n";
        return;
    }
    p->UpdateTaskStatus(taskId);
    cout << "Task Status Update successfully.\n";
}

void TaskManager::ViewTasks()
{
    int userId, projectId;

    cout << "User ID: ";
    cin >> userId;
    cout << "Project ID: ";
    cin >> projectId;

    if (!users.count(userId))
    {
        cout << "User not found!\n";
        return;
    }

    Project *p = users[userId].GetProjectById(projectId);
    if (!p)
    {
        cout << "Project not found!\n";
        return;
    }

    p->ViewTasks();
}

void TaskManager::ViewFilteredTasks()
{
    int userId, projectId;
    cout << "User ID: ";
    cin >> userId;
    cout << "Project ID: ";
    cin >> projectId;

    if (users.count(userId))
    {
        Project *p = users[userId].GetProjectById(projectId);
        if (p)
            p->ViewTasksByStatus();
        else
            cout << "Project not found!\n";
    }
    else
        cout << "User not found!\n";
}

void TaskManager::run()
{
    int choice;

    cout << "\n--- Task Management System ---\n";
    while (true)
    {
        cout << "\n--------------------------------------\n";
        cout << "1. Create User\n";
        cout << "2. View Users\n";
        cout << "3. Create Project\n";
        cout << "4. Add Task\n";
        cout << "5. Update Task Status\n";
        cout << "6. View Tasks\n";
        cout << "7. View Tasks by Status (Filter)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            CreateUser();
            break;
        case 2:
            ViewUsers();
            break;
        case 3:
            CreateProject();
            break;
        case 4:
            AddTask();
            break;
        case 5:
            UpdateTaskStatus();
            break;
        case 6:
            ViewTasks();
            break;
        case 7:
            ViewFilteredTasks();
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
}