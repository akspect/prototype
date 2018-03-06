#include "PointVector.h"

//頂点を引数分生成して、それらを結ぶクラス

PointVector::PointVector(int count){
	pointCount = count;

	for (int y = 0; y < pointCount; y++) {
		pointVector.push_back(Point());
	}

	polyNum = 0;

}

void PointVector::update() {
	
	for (int i = 0; i < pointCount; i++) {
		pointVector[i].update();
	}

}


void PointVector::draw( float polyColor) {
	

	//ofSetColor(polyColor);
	
	ofSetColor(ofColor::fromHsb(polyColor, 255, 255));

	ofFill();

	//それぞれの頂点を結ぶ
	ofBeginShape();

	for (int y = 0; y < pointCount; y++) {

		ofVertex(pointVector[y].point);
	}
	ofEndShape();


	for (int i = 0; i < pointCount; i++) {
		pointVector[i].draw();
	}
}

