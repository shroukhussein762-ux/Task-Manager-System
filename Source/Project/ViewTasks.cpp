#include "../Header/Project.h"
#include <iomanip>
using namespace std;

// Displays all tasks in the project in a formatted table

void Project::ViewTasks() const
{ // Check if there are any tasks to display
     if (tasks.empty())
     {
          cout << "\n"
               << indent << "[!] No tasks in this project." << endl;
          return;
     }
     // Print Table Header
     cout << "\n"
          << indent << string(85, '=') << endl;
     cout << indent << "                   PROJECT TASKS LIST" << endl;
     cout << indent << string(85, '=') << endl;

     cout << indent << left << setw(6) << "ID"
          << " | " << setw(15) << "Status"
          << " | " << setw(20) << "Title"
          << " | " << "Description" << endl;
     cout << indent << string(85, '-') << endl;
     // Iterate through the tasks map and display each task's details
     for (auto const &t : tasks)
     {
          cout << indent << left << setw(6) << t.first
               << " | " << setw(15) << t.second.GetStatus()
               << " | " << setw(20) << t.second.GetTitle()
               << " | " << t.second.GetDescription() << endl;
     }
     cout << indent << string(85, '=') << endl;
}