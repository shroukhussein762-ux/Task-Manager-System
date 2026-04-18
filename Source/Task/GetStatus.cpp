#include "../Header/Task.h"
#include <string>
using namespace std;
string Task::GetStatus() const
{
    switch (status)
    {
    case TODO:
        return "To Do";
    case IN_PROGRESS:
        return "In Progress";
    case DONE:
        return "Done";
    default:
        return "Unknown";
    }
}