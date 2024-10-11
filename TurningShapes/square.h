#pragma once
#include "shape.h"
#include <string>
#include <vector>

class square : public shape {
	int radius;
public:
	square(int radius = 0) : radius(radius) {};

	void draw2D(Point3D to, vector<string>& buffer) override {
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
	void draw3D(Point3D to, vector<string>& buffer) override {};
	void rotate(float theta) override {};

	void drawLine(int x0, int y0, int x1, int y1, vector<string>& buffer) override {
		int dx = abs(x1 - x0);
		int dy = abs(y1 - y0);
		int sx = (x0 < x1) ? 1 : -1;
		int sy = (y0 < y1) ? 1 : -1;
		int err = dx - dy;

		while (true) {
			if (y0 >= 0 && y0 < buffer.size() && x0 >= 0 && x0 < buffer[0].size()) {
				buffer[y0][x0] = '@';
			}
			if (x0 == x1 && y0 == y1) break;
			int err2 = err * 2;
			if (err2 > -dy) {
				err -= dy;
				x0 += sx;
			}
			if (err2 < dx) {
				err += dx;
				y0 += sy;
			}
		}
	}
};