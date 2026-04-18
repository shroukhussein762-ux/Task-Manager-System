#include "../Header/Project.h"
using namespace std;
// Constructor: Initializes a project with an ID, name, and resets the task counter
Project::Project(int id, const std::string &name) 
    : Id(id), name(name), taskCounter(1) 
{
    // The taskCounter starts at 1 for every new project
}