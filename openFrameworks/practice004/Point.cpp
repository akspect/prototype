#include "Point.h"

//頂点を生成するクラス

Point::Point() {



	radius = ofGetWindowHeight()/2;

	radian = ofNoise(ofRandom(10)) * 360;
	randomWidth = ofNoise(ofRandom(10)) * ofGetWindowWidth();
	randomHeight = ofNoise(ofRandom(10)) * ofGetWindowHeight();

	//x,y座標の設定
	point.x = cos(radian * DEG_TO_RAD)*radius + randomWidth;
	point.y = sin(radian * DEG_TO_RAD)*radius + randomHeight;

	if (point.x > ofGetWindowWidth()) {
		point.x = ofGetWindowWidth();
	}

	if(point.y > ofGetWindowHeight()) {
		point.y = ofGetWindowHeight();
	}
	
	//スピードの設定
	speed = ofNoise(ofRandom(20)/100)*ofRandom(-1,1)*4;
	if (speed == 0) { 
		speed = 0.5;
	}

}



void Point::update() {
	radian = radian + speed;

	if (radian < -360 || radian >360) {

		radian = 0;
	}


	//x,y座標の設定
	point.x = cos(radian * DEG_TO_RAD)*radius + randomWidth;
	point.y = sin(radian * DEG_TO_RAD)*radius + randomHeight;
}



void Point::draw() {

	//ofDrawCircle(point, 10);
	
}