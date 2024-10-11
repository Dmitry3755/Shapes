#pragma once
#include <vector>
#include "Point3D.h"

using namespace std;

class shape {
	Point3D center;
public:
	Point3D getCenter() { return center; }
	void setCenter(Point3D newCenter) { center = newCenter; }

	virtual void draw2D(Point3D to, vector<string>& buffer) = 0;
	virtual void draw3D(Point3D to, vector<string>& buffer) = 0;
	virtual void rotate(float theta) = 0;
	virtual void drawLine(int x0, int y0, int x1, int y1, vector<string>& buffer) = 0;

	virtual ~shape() = default;
};