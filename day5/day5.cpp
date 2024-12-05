#include <cassert>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <iostream>
#include <cctype>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>

using namespace std;

set<pair<int, int>> readRules() {
    set<pair<int, int>> result;
    set<int> pages;

    string line;

    while(getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        int num1, num2;
        char verticalChar;
        ss >> num1 >> verticalChar >> num2;
        pages.insert(num1);
        pages.insert(num2);
        result.emplace(num1, num2);
    }

    return result;
}

int part1() {
    set<pair<int, int>> rules = readRules();
    auto before = [&](int num1, int num2) {return rules.find({num1, num2}) != rules.end();};
    string line;
    int result = 0;
    while (getline(cin, line)) {
        line.push_back(',');
        stringstream ss(line);
        vector<int> update;
        int num;
        char commaChar;
        while(ss >> num >> commaChar) {
            update.push_back(num);
        }

        bool correct = true;

        for(int i = 0; correct && i + 1 < update.size(); ++i) {
            if (!before(update[i], update[i+1])) {
                correct = false;
            }
        }
        if (correct) {
            result += update[update.size() / 2];
        }
    }

    return result;
}




int part2() {
    set<pair<int, int>> rules = readRules();
    auto before = [&](int num1, int num2) {return rules.find({num1, num2}) != rules.end();};
    string line;
    int result = 0;
    while (getline(cin, line)) {
        line.push_back(',');
        stringstream ss(line);
        vector<int> update;
        int num;
        char commaChar;
        while(ss >> num >> commaChar) {
            update.push_back(num);
        }

        bool correct = true;

        for(int i = 0; correct && i + 1 < update.size(); ++i) {
            if (!before(update[i], update[i+1])) {
                correct = false;
            }
        }
        if (!correct) {
            sort(update.begin(), update.end(), before);
            result += update[update.size() / 2];
        }
    }

    return result;
}

int main(int argc, char **argv) {
    if (argc == 2 && argv[1][0] == '1') {
        fprintf(stdout, "Part 1: %d\n", part1());
    } else if (argc == 2 && argv[1][0] == '2') {
        fprintf(stdout, "Part 2: %d\n", part2());
    }
    return 0;
}
