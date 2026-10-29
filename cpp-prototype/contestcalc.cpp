#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
 
// ---------- POINT RULES (edit these to change the contest) ----------
const int NEW_GROSS_PER_1000  = 5;
const int USED_GROSS_PER_1000 = 8;
 

 
// ---------- HELPERS ----------
int newGrossPoints(double gross) {
    if (gross < 0) return 0;                 // no points for a loss
    int thousands = static_cast<int>(gross / 1000); // whole thousands only
    return thousands * NEW_GROSS_PER_1000;
}
 
int usedGrossPoints(double gross) {
    if (gross < 0) return 0;
    int thousands = static_cast<int>(gross / 1000);
    return thousands * USED_GROSS_PER_1000;
}
 
int newAgePoints(int age) {
    if (age < 25)  return 5;
    if (age < 50)  return 10;
    if (age < 75)  return 15;
    if (age < 100) return 20;
    if (age < 125) return 25;
    if (age < 150) return 35;
    if (age < 175) return 45;
    return 65;
}
 
int usedAgePoints(int age) {
    if (age < 20) return 5;
    if (age < 30) return 10;
    if (age < 40) return 20;
    if (age < 50) return 30;
    if (age < 60) return 40;
    if (age < 70) return 50;
    return 60;
}
 
// Reads a whole line so names with spaces work and bad input can't break cin
std::string readLine(const std::string& prompt) {
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}
 
bool askYesNo(const std::string& prompt) {
    while (true) {
        std::string s = readLine(prompt + " (y/n): ");
        if (!s.empty()) {
            char c = std::tolower(static_cast<unsigned char>(s[0]));
            if (c == 'y') return true;
            if (c == 'n') return false;
        }
        std::cout << "Please enter y or n.\n";
    }
}
 
// Accepts "2,700", "$2,700.50", "2700", etc.
double askNumber(const std::string& prompt) {
    while (true) {
        std::string s = readLine(prompt);
        s.erase(std::remove_if(s.begin(), s.end(),
                [](char c) { return c == ',' || c == '$' || c == ' '; }), s.end());
        try {
            size_t used = 0;
            double v = std::stod(s, &used);
            if (used == s.size()) return v;
        } catch (...) {}
        std::cout << "Please enter a valid number.\n";
    }
}
 
std::string askNewOrUsed() {
    while (true) {
        std::string s = readLine("Is the vehicle new or used? (n/u): ");
        if (!s.empty()) {
            char c = std::tolower(static_cast<unsigned char>(s[0]));
            if (c == 'n') return "new";
            if (c == 'u') return "used";
        }
        std::cout << "Please enter n or u.\n";
    }
}
 
// ---------- MAIN FEATURES ----------
void addDeal(std::map<std::string, double>& scores) {
    std::string sp1 = readLine("Enter salesperson name: ");
    std::string sp2;
    bool split = askYesNo("Is there a 2nd salesperson?");
    if (split) sp2 = readLine("Enter 2nd salesperson name: ");
 
    std::string condition = askNewOrUsed();
    bool lease = false;
    if (condition == "new") lease = askYesNo("Is it a lease?");
 
    double gross = askNumber("Enter total gross: ");
    int age = static_cast<int>(askNumber("Enter vehicle age: "));
 
    int grossPts, agePts;
    if (condition == "new") {
        grossPts = newGrossPoints(gross);
        agePts   = newAgePoints(age);
    } else {
        grossPts = usedGrossPoints(gross);
        agePts   = usedAgePoints(age);
    }
 
    double total = grossPts + agePts;
    if (lease) total *= 2;
    if (split) total /= 2;
 
    std::cout << "\n--- Deal Summary ---\n";
    std::cout << "Gross points: " << grossPts << "\n";
    std::cout << "Age points:   " << agePts << "\n";
    if (lease) std::cout << "Lease:        x2\n";
    if (split) std::cout << "Split:        /2\n";
 
    scores[sp1] += total;
    std::cout << sp1 << " receives " << total << " points\n";
    if (split) {
        scores[sp2] += total;
        std::cout << sp2 << " receives " << total << " points\n";
    }
    std::cout << "\n";
}
 
void showLeaderboard(const std::map<std::string, double>& scores) {
    if (scores.empty()) {
        std::cout << "\nNo deals entered yet.\n\n";
        return;
    }
    std::vector<std::pair<std::string, double>> sorted(scores.begin(), scores.end());
    std::sort(sorted.begin(), sorted.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });
 
    std::cout << "\n=== LEADERBOARD ===\n";
    int rank = 1;
    for (const auto& entry : sorted) {
        std::cout << rank++ << ". " << std::left << std::setw(20) << entry.first
                  << entry.second << " pts\n";
    }
    std::cout << "\n";
}
 
int main() {
    std::map<std::string, double> scores;
 
    while (true) {
        std::cout << "=== DEALERSHIP CONTEST SYSTEM ===\n"
                  << "1. Add New Deal Entry\n"
                  << "2. View Current Leaderboard\n"
                  << "3. Exit\n";
        std::string choice = readLine("Select an option: ");
 
        if (choice == "1")      addDeal(scores);
        else if (choice == "2") showLeaderboard(scores);
        else if (choice == "3") break;
        else                    std::cout << "Invalid option.\n\n";
    }
    return 0;
}