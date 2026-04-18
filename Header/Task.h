#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
// Definition of available task statuses
enum Status
{
    TODO,
    IN_PROGRESS,
    DONE
};
extern std::string indent; // Used for formatting output indentation
class Task
{
private:
    int Id;
    std::string title, description;
    Status status;
    int priority;

public:
    // Constructors
    Task() {};
    Task(int Id, const std::string &title, const std::string &description, int priority);
    // Getters
    int GetId() const;
    std::string GetTitle() const;
    std::string GetStatus() const;
    std::string GetDescription() const;
    // Operations
    void ChangeStatus();
    void Display() const;
    void SetId(int Id);

    // File I/O operations
    void Save(std::ostream &outFile) const;
    static Task Load(std::istream &inFile);
};
#endif
