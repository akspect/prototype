#pragma once

#include "ofMain.h"
#include "Point.h"

class PointVector
{
public:
	PointVector(int count);
	void draw(float polyColor);
	void update();
	vector<Point> pointVector;


private:
	int pointCount;
	int polyNum;
	ofMesh mesh;
};

