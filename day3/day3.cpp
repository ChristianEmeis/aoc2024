#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cctype>

int part1(const char* input) {
    int sum = 0;
    const char* ptr = input;

    while (*ptr) {
        // Look for "mul("
        if (strncmp(ptr, "mul(", 4) == 0) {
            ptr += 4; // Skip "mul("

            // Parse the first number (NUM1)
            char* end;
            int num1 = strtol(ptr, &end, 10);
            if (end == ptr || *end != ',') { // Check if valid integer followed by ','
                ptr++;
                continue;
            }
            ptr = end + 1; 

            // Parse the second number (NUM2)
            int num2 = strtol(ptr, &end, 10);
            if (end == ptr || *end != ')') { // Check if valid integer followed by ')'
                ptr++; // Skip invalid part
                continue;
            }
            ptr = end + 1; // Move past ')'

            sum += num1 * num2;
        } else {
            ptr++; // Skip invalid characters
        }
    }

    return sum;
}


int part2(const char* input) {
    int sum = 0;
    const char* ptr = input;
    bool enabled = true;

    while (*ptr) {

        if (strncmp(ptr, "do()", 4) == 0) {
            enabled = true;
            ptr += 4;
        } else if (strncmp(ptr, "don't()", 7) == 0) {
            enabled = false;
            ptr += 7;
        }

        // Look for "mul("
        if (strncmp(ptr, "mul(", 4) == 0) {
            ptr += 4; // Skip "mul("

            // Parse the first number (NUM1)
            char* end;
            int num1 = strtol(ptr, &end, 10);
            if (end == ptr || *end != ',') { // Check if valid integer followed by ','
                ptr++;
                continue;
            }
            ptr = end + 1; 

            // Parse the second number (NUM2)
            int num2 = strtol(ptr, &end, 10);
            if (end == ptr || *end != ')') { // Check if valid integer followed by ')'
                ptr++; // Skip invalid part
                continue;
            }
            ptr = end + 1; // Move past ')'

            if (enabled) {
                sum += num1 * num2;
            }
        } else {
            ptr++; // Skip invalid characters
        }
    }

    return sum;
}

int main() {
    std::string input, line;

    while (std::getline(std::cin, line)) {
        input += line; 
    }

    fprintf(stdout, "Part 1: %d\n", part1(input.c_str()));
    fprintf(stdout, "Part 2: %d\n", part2(input.c_str()));
    return 0;
}
