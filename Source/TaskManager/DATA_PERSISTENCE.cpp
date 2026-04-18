#include "../Header/TaskManager.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
// Saves the entire system state (all users and their projects/tasks) to a file
void TaskManager::saveData()
{
    std::ofstream outFile("database.txt");
    if (!outFile)
    {
        cout << "Error opening file for saving!\n";
        return;
    }
    // Write the total number of users first
    outFile << users.size() << endl;
    for (auto const &[uId, user] : users)
    {
        user.Save(outFile); // Recursive save: User -> Project -> Task
    }
    outFile.close();
}

// Loads the system state from the file and reconstructs the user map
void TaskManager::loadData()
{
    ifstream inFile("database.txt");
    if (!inFile) // If file doesn't exist, start with a fresh system
        return;
    string sizeStr;
    if (!getline(inFile, sizeStr))
        return;
    int size = stoi(sizeStr);
    users.clear();
    UserCounter = 1;

    for (int i = 0; i < size; i++)
    {
        User u = User::Load(inFile);
        // Assigning current ID and maintaining the global UserCounter
        int newId = UserCounter++;
        u.SetId(newId);

        users[newId] = u;
    }
    inFile.close();
}