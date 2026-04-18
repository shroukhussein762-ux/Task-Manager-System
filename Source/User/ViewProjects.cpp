#include "../Header/User.h"
#include <iomanip>
using namespace std;
void User::ViewProjects(const string name_project) const
{
    if (projects.empty())
    {
        cout << "\n"
             << indent << "[!] No projects found for this user." << endl;
        return;
    }
    cout << '\n'
         << indent << "          --- Projects for User: " << name_project << " ---\n";
    cout << "\n"
         << indent << "==================================================" << endl;
    cout << indent << "                USER PROJECTS                     " << endl;
    cout << indent << "==================================================" << endl;
    cout << indent << left << setw(12) << "Project ID" << " | " << "Project Name" << endl;
    cout << indent << "--------------------------------------------------" << endl;

    for (auto const &[id, proj] : projects)
    {
        cout << indent << left << setw(12) << id
             << " | " << proj.GetName() << endl;
    }

    cout << indent << "==================================================" << endl;
}
