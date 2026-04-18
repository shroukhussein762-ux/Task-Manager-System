#include "../Header/User.h"
using namespace std;
void User::Save(std::ostream &outFile) const
{
    outFile << Id << "|" << Name << "|" << projects.size() << endl;
    for (auto &p : projects)
    {
        p.second.Save(outFile);
    }
}
void User::SetId(int Id)
{
    this->Id = Id;
}
User User::Load(std::istream &inFile)
{
    string line;
    if (!getline(inFile, line) || line.empty())
        return User(0, "");

    stringstream ss(line);
    string idStr, n, sizeStr;

    getline(ss, idStr, '|');
    getline(ss, n, '|');
    getline(ss, sizeStr, '|');

    User user(stoi(idStr), n);
    int size = stoi(sizeStr);

    user.projects.clear();
    user.ProjectCounter = 1;

    for (int i = 0; i < size; i++)
    {
        Project p = Project::Load(inFile);
        int newProjectId = user.ProjectCounter++;
        user.projects[newProjectId] = p;
    }
    return user;
}