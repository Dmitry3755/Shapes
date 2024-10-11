#pragma once
#include "shape.h"
#include <string>
#include <vector>
#include "Point3D.h"

class rectangle : public shape {

	float radius;
	vector<Point3D> cubeVertices = {
		{-radius, -radius, -radius}, {radius, -radius, -radius}, {radius, radius, -radius}, {-radius, radius, -radius},
		{-radius, -radius, radius},  {radius, -radius, radius},  {radius, radius, radius},  {-radius, radius, radius}
	};
	vector<pair<int, int>> edges = {
		{0, 1}, {1, 2}, {2, 3}, {3, 0},
		{4, 5}, {5, 6}, {6, 7}, {7, 4},
		{0, 4}, {1, 5}, {2, 6}, {3, 7}
	};

public:
	rectangle(int radius = 0) : radius(radius) {};

	void draw2D(Point3D to, vector<string>& buffer) override {
		for (float y = -radius + 1; y <= radius - 1; y++) {
			for (float x = (-2 * radius) + 1; x <= (2 * radius) - 1; x++) {
				std::pair<float, float> point = calculateCoord(to, x, y);
				if (point.second >= 0 && point.second < buffer.size() && point.first >= 0 && point.first < buffer[0].size()) {
					buffer[point.second][point.first] = '@';
				}
			}
		}
	};

	void draw3D(Point3D to, vector<string>& buffer) override {
		for (const auto& edge : edges) {
			std::pair<float, float> point0 = calculateCoord(cubeVertices[edge.first], to, edge.first, edge.second, false);
			std::pair<float, float> point1 = calculateCoord(cubeVertices[edge.second], to, edge.first, edge.second, true);
			drawLine(point0.first, point0.second, point1.first, point1.second, buffer);
		}
	}

	pair<int, int> calculateCoord(Point3D point, Point3D to, int edgeFirst, int eadgeSecond, bool passSecond) {
		int projectedX = 0;
		int projectedY = 0;
		if (edgeFirst >= 4) {
			projectedX = static_cast<int>(to.x + (point.x * 2.0f) + point.z);
			projectedY = static_cast<int>(to.y - point.y - (point.z / 2));
		}
		else if ((eadgeSecond >= 4 && edgeFirst <= 4) && passSecond) {
			projectedX = static_cast<int>(to.x + (point.x * 2.0f) + point.z);
			projectedY = static_cast<int>(to.y - point.y - (point.z / 2));
		}
		else {
			projectedX = static_cast<int>(to.x + (point.x * 2.0f));
			projectedY = static_cast<int>(to.y - point.y);
		}
		return { projectedX, projectedY };
	}

	pair<int, int> calculateCoord(Point3D to, float x, float y) {
		return { to.x + static_cast<int>(x) ,to.y + static_cast<int>(y) };
	}

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