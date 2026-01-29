#include "Task.h"

Task::Task( int id,const string& title, const string& description,int priority)
{
    this->id = id;
    this->title = title;
    this->description = description;
    this->priority=priority;
    this->status=TODO;

}

int Task::GetId(){
    return id;
}

string Task::GetTitle(){
    return title;
}

string Task::GetStatus(){
    switch (status) {
        case TODO: return "To Do";
        case IN_PROGRESS: return "In Progress";
        case DONE: return "Done";
        default: return "Unknown";
}
}

string Task::GetDescription(){
    return description;
}

void Task::ChangeStatus(int choice){
   if (choice == 1) status = TODO;
    else if (choice == 2) status = IN_PROGRESS;
    else if (choice == 3) status = DONE;
    else 
    cout<<"INVALID CHOICE\n";
}

void Task::Display(){
  string pioName = (priority == 1) ? "High" : (priority == 2 ? "Medium" : "Low");
    cout << "[" << id << "] " << title << " | Priority: " << pioName 
         << " | Status: " << GetStatus() << endl;
    cout << "   Description: " << description << endl;
}