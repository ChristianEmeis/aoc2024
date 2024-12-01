#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>

int part1(std::vector<int> &l1, std::vector<int> &l2) {
	int res = 0;
	for (int i = 0; i < l1.size(); ++i) {
		res += abs(l1[i] - l2[i]);
	}
	return res;
}


int countOfN(int n, std::vector<int> &l2) {
	int count = 0;
	for(int i = 0; i < l2.size(); ++i) {
		if (l2[i] == n) {
			count++;
		}
	}
	return count;
}

int part2(std::vector<int> &l1, std::vector<int> &l2) {
	int res = 0;
	for(int i = 0; i < l2.size(); ++i) {
		res += l1[i] * countOfN(l1[i], l2);
	}
	return res;
}


int main (int argc, char *argv[]) {
	std::vector<int> l1, l2;
	int num1, num2;

	while (std::cin >> num1 >> num2) {
		l1.push_back(num1);
		l2.push_back(num2);
	}

	std::sort(l1.begin(), l1.end());
	std::sort(l2.begin(), l2.end());

	fprintf(stdout, "Part 1: %d\n", part1(l1, l2));
	fprintf(stdout, "Part 2: %d\n", part2(l1, l2));
	return 0;
}

