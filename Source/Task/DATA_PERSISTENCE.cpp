#include "../Header/Task.h"
#include <iomanip>
#include <limits>
using namespace std;
// Saves a single task's data to the file stream using a pipe delimiter
void Task::Save(std::ostream &outFile) const
{
    outFile << Id << "|" << title << "|" << description << "|"
            << static_cast<int>(status) << "|" << priority << endl;
}


// Loads a task's data from a file stream and reconstructs the object
Task Task::Load(std::istream &inFile)
{
    string line;
    getline(inFile, line);
    stringstream ss(line);
    string idStr, t, d, sStr, pStr;

    // Parsing data using the pipe '|' delimiter
    getline(ss, idStr, '|');
    getline(ss, t, '|');
    getline(ss, d, '|');
    getline(ss, sStr, '|');
    getline(ss, pStr, '|');

    // Create the task object and manually set the status
    Task task(stoi(idStr), t, d, stoi(pStr));
    task.status = (Status)stoi(sStr);
    return task;
}