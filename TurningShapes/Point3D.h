#pragma once

#include <windows.h>

struct Point3D
{
	float x, y, z;
	Point3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {};

public:
	void calculateCenter(CONSOLE_SCREEN_BUFFER_INFO sizes) {
		x = (sizes.srWindow.Right - sizes.srWindow.Left + 1) / 2;
		y = (sizes.srWindow.Bottom - sizes.srWindow.Top + 1) / 2;
	};

	Point3D getCenter() { return Point3D(x, y); };

	COORD pointToCoordConverter() {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		return coord;
	}

	COORD pointToCoordConverter(float stepsX, float stepsY) {
		COORD coord;
		coord.X = stepsX;
		coord.Y = stepsY;
		return coord;
	}
};