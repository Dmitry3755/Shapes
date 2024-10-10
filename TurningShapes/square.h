#pragma once
#include "shape.h"
#include <string>
#include <vector>

class square : public shape {
	int radius;
public:
	square(int radius = 0) : radius(radius) {};
	void draw(point to, vector<string>& buffer) override {
		for (float y = -radius + 1; y <= radius - 1; y++) {
			for (float x = (-2 * radius) + 1; x <= (2 * radius) - 1; x++) {
				if ((x / 2) * (x / 2) + y * y <= radius * radius) {

					int bufferX = to.x + static_cast<int>(x);
					int bufferY = to.y + static_cast<int>(y);

					if (bufferY >= 0 && bufferY < buffer.size() && bufferX >= 0 && bufferX < buffer[0].size()) {
						buffer[bufferY][bufferX] = '@';
					}
				}

			}
		}
	};
	void rotate(int to) override {};
};