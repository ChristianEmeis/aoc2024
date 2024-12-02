#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

bool isSafe(const std::vector<int>& row) {
    if (row.size() < 2) return true;

    bool increasing = true, decreasing = true;

    for (int i = 1; i < row.size(); ++i) {
        int diff = row[i] - row[i - 1];

        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false;
        }

        if (diff > 0) decreasing = false;
        if (diff < 0) increasing = false;
    }

    return increasing || decreasing;
}

bool isSafeWithOneRemoval(std::vector<int> row) {
    for (int i = 0; i < row.size(); ++i) {
        std::vector<int> modifiedRow = row;
        modifiedRow.erase(modifiedRow.begin() + i);
        
        if (isSafe(modifiedRow)) {
            return true;
        }
    }
    return false;
}

int part1(const std::vector<std::vector<int>>& matrix) {
    int safeCount = 0;
    for (const auto& row : matrix) {
        if (isSafe(row)) {
            safeCount++;
        }
    }
    return safeCount;
}

int part2(const std::vector<std::vector<int>>& matrix) {
    int safeCount = 0;
    for (const auto& row : matrix) {
        if (isSafe(row) || isSafeWithOneRemoval(row)) {
            safeCount++;
        }
    }
    return safeCount;
}

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> matrix;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) break;

        std::vector<int> row;
        std::stringstream ss(line);
        int num;

        while (ss >> num) {
            row.push_back(num);
        }

        matrix.push_back(row);
    }

    fprintf(stdout, "Part 1: %d\n", part1(matrix));
    fprintf(stdout, "Part 2: %d\n", part2(matrix));
    return 0;
}
