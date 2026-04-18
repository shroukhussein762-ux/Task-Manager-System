#include "../Header/Project.h"
#include <sstream>
using namespace std;



// Saves project details and all its tasks to a file stream
void Project::Save(std::ostream &outFile) const
{ // Format: ID|Name|NumberOfTasks
    outFile << Id << "|" << name << "|" << tasks.size() << endl;
    for (auto const &[tId, task] : tasks)
    {
        task.Save(outFile); // Calls Task's own Save method
    }
}



// Loads a project and its tasks from a file stream
Project Project::Load(std::istream &inFile)
{
    string line;
    if (!getline(inFile, line) || line.empty())
        return Project(0, "");

    stringstream ss(line);
    string idStr, n, sizeStr;
    // Parsing the project header line
    getline(ss, idStr, '|');
    getline(ss, n, '|');
    getline(ss, sizeStr, '|');

    Project proj(stoi(idStr), n);
    int size = stoi(sizeStr);

    proj.tasks.clear();
    proj.taskCounter = 1;
    // Load each task and reconstruct the tasks map
    for (int i = 0; i < size; i++)
    {
        Task t = Task::Load(inFile);
        int newTaskId = proj.taskCounter++;
        t.SetId(newTaskId);
        proj.tasks[newTaskId] = t;
    }
    return proj;
}