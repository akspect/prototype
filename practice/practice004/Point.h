#pragma once
#include "ofMain.h"


#pragma once


class Point {

public:
	Point();
	void update();
	void draw();
	ofPoint point;

private:
	float radius;
	float speed;
	float radian;
	float randomWidth, randomHeight;
};
