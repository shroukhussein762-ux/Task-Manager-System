<<<<<<< HEAD
#include "Task.h"

Task::Task( int id,const string& title, const string& description)
{
    this->id = id;
    this->title = title;
    this->description = description;
    status = "To Do";

}

int Task::GetId(){
    return id;
}

string Task::GetTitle(){
    return title;
}

string Task::GetStatus(){
    return status;
}

string Task::GetDescription(){
    return description;
}

void Task::ChangeStatus(const string& NewStatus){
    status=NewStatus;
}

void Task::Display(){
     cout << "----------------------\n";
    cout << "Task ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Status: " << status << endl;
    cout << "----------------------\n";
=======
#include "Task.h"

Task::Task( int id,const string& title, const string& description)
{
    this->id = id;
    this->title = title;
    this->description = description;
    status = "To Do";

}

int Task::GetId(){
    return id;
}

string Task::GetTitle(){
    return title;
}

string Task::GetStatus(){
    return status;
}

string Task::GetDescription(){
    return description;
}

void Task::ChangeStatus(const string& NewStatus){
    status=NewStatus;
}

void Task::Display(){
     cout << "----------------------\n";
    cout << "Task ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Status: " << status << endl;
    cout << "----------------------\n";
>>>>>>> 4d09b1b (Enhance task management with OOP principles and enums)
}