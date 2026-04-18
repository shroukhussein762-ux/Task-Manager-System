#include "../Header/Task.h"
#include <string>
#include <iomanip>
#include <limits>
using namespace std;
// Displays all task details in a formatted "card" view
void Task::Display() const
{
    // Convert numerical priority to a readable string
    string pioName = (priority == 1) ? "High" : (priority == 2 ? "Medium" : "Low");

    cout << "\n"
         << indent << "--------------------------------------------------" << endl;
    cout << indent << "| TASK ID: " << left << setw(38) << Id << " |" << endl;
    cout << indent << "| Title  : " << left << setw(38) << title << " |" << endl;
    cout << indent << "| Status : " << left << setw(38) << GetStatus() << " |" << endl;
    cout << indent << "| Prio   : " << left << setw(38) << pioName << " |" << endl;
    cout << indent << "| Desc   : " << left << setw(38) << description << " |" << endl;
    cout << indent << "--------------------------------------------------" << endl;
}