#include "../Header/Task.h"

// Constructor: Initializes a task with basic details and sets default status to TODO
Task::Task(int id, const std::string &title, const std::string &description, int priority)
    : Id(id), title(title), description(description), status(TODO), priority(priority)
{
}