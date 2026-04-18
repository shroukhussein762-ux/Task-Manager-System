#include "../Header/TaskManager.h"

// Constructor: Initializes the user counter and automatically loads existing data
TaskManager::TaskManager()
{
    UserCounter = 1; // Starts counting users from 1
    loadData();      // Reconstructs the system state from saved files
}