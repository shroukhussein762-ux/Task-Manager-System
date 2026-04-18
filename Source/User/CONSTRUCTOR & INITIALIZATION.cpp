#include "../Header/User.h"
using namespace std;
User::User(int Id, const string &Name)
{
    this->Id = Id;
    this->Name = Name;
    this->ProjectCounter = 1;
}