#pragma once
#include "ofMain.h"

class Circle
{
public:

	Circle(ofColor body_color, float randomNum);

	void update();
	void draw();
	bool isDead();

private:

	//circle property
	float radius;
	int segment, segmentDeg;
	float addX, addY, addZ;
	float obX,obY ,obZ, posObX, posObY, posObZ;
	ofColor body_color;
	int alpha;
};

