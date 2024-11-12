#include "Leaderboard.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void Leaderboard::addEntry(const std::string& studentID, int marks) {
    LeaderboardEntry entry = { studentID, marks };
    entries.push_back(entry);
}

void Leaderboard::displayLeaderboard() const {
    std::cout << "Leaderboard:\n";
    std::cout << std::setw(15) << "Student ID" << std::setw(10) << "Marks\n";
    for (const auto& entry : entries) {
        std::cout << std::setw(15) << entry.studentID
                  << std::setw(10) << entry.marks << "\n";
    }
}

void Leaderboard::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening leaderboard file.\n";
        return;
    }
    for (const auto& entry : entries) {
        outFile << entry.studentID << "," << entry.marks << "\n";
    }
    outFile.close();
}

void Leaderboard::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening leaderboard file.\n";
        return;
    }
    std::string studentID;
    int marks;
    while (inFile >> studentID >> marks) {
        entries.push_back({ studentID, marks });
    }
    inFile.close();
}
