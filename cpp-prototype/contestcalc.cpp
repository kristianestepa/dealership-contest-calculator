// Kristian Estepa
// 10/22/2026
// Description: A C++ CLI engine designed to automate point calculations for dealership monthly sales contests.

#include <iostream>
#include <vector>

// Function declaration
int mainMenu();

void calculatePoints();

int main() {

    // Main Menu
    mainMenu();
    
}

// Function definition
int mainMenu() {

    int menuChoice;

    std::cout << "=== DEALERSHIP CONTEST SYSTEM ===\n";
    std::cout << "1. Add New Deal Entry\n";
    std::cout << "2. View Current Leaderboard\n";
    std::cout << "3. Exit\n";
    std::cout << "Select an option: ";
    std::cin >> menuChoice;

    return menuChoice;
}