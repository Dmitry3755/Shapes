#pragma once
#include "point.h"
#include <vector>

using namespace std;

class shape {
	point center;
public:
	point getCenter() { return center; }
	void setCenter(point newCenter) { center = newCenter; }

	virtual void draw(point to, vector<string>& buffer) = 0;
	virtual void rotate(int) = 0;

	virtual ~shape() = default;
};