#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class buffer {
public:
	void clearBuffer(vector<string>& buffer, int height, int width) {
		for (int j = 0; j < height; j++) {
			buffer[j] = string(width, ' ');
		}

	}
	void drawBuffer(const vector<string>& buffer) {
		for (const auto& line : buffer) {
			cout << line << endl;
		}
	}
};