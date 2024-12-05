#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cctype>
#include <vector>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct {
    int x;
    int y;
} CustTuple;

int part1(vector<vector<char>> arr) {

    CustTuple directions[8] = {{1, 0}, {0, 1}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

    int found = 0;
    int rowIndex = 0;
    int colIndex = 0;
    while (rowIndex < arr.size()) {
        int rowCount = arr.size();
        colIndex = 0;
        while (colIndex < arr[rowIndex].size()){
            int colCount = arr[rowIndex].size();
            for (CustTuple direction : directions) {
                if ((colIndex < (rowCount - 3 * direction.y)) && (colIndex + direction.y * 3) >= 0 
                    && (rowIndex + direction.x * 3) >= 0 
                    && (rowIndex < (colCount - 3 * direction.x)) 
                    && arr[rowIndex][colIndex] == 'X' 
                    && arr[rowIndex + 1 * direction.x][colIndex + 1 * direction.y] == 'M' 
                    && arr[rowIndex + 2 * direction.x][colIndex + 2 * direction.y] == 'A' 
                    && arr[rowIndex + 3 * direction.x][colIndex + 3 * direction.y] == 'S') {
                    found++;
                }
            }
            colIndex++;
        }
        rowIndex++;
    }
    return found;
}


int part2(vector<vector<char>> arr) {
    return 0;
}

int main() {
    vector<vector<char>> arr;
    string line;

    while (getline(cin, line) && !line.empty()) {
        vector<char> row(line.begin(), line.end());
        arr.push_back(row);
    }

    
    for(int i = 0; i < arr[140].size(); i++) {
        printf("%c", arr[140][i]);
    }
    
    fprintf(stdout, "Part 1: %d\n", part1(arr));
    fprintf(stdout, "Part 2: %d\n", part2(arr));
    return 0;
}
