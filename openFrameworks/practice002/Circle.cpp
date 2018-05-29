#include "Circle.h"



Circle::Circle(ofColor body_color, float randomNum) {
	this->radius = 10;
	this->segment = 3;
	this->body_color = body_color;
	this->alpha = 100;
	this->addX = randomNum;
	this->addY = randomNum;
	this->addZ = randomNum;
}

void Circle::update() {

	if (segment >= 6) {
		segment = 3;
	}

	if (alpha >= 255) {
		alpha = 50;
	}

	radius += 3 * radius/10;
	segment++;
	alpha++;

}

void Circle::draw() {
	ofNoFill();
	ofSetColor(body_color, alpha);

	
	segmentDeg = 360 / segment;

	ofSetLineWidth(0.8*segment);

	// 1ƒT[ƒNƒ‹‚ğì‚é
	for (int degNum = 0; degNum <= 360; degNum += segmentDeg){


			obX = cos(degNum*DEG_TO_RAD)*radius;
			obY = sin(degNum*DEG_TO_RAD)*radius;

			if (degNum != 0) {


				ofDrawLine(obX, obY, addZ, posObX, posObY, addZ);
			}

			posObX = obX;
			posObY = obY;
	}


}


bool Circle::isDead(){
	return radius > ofGetWidth() || radius > ofGetHeight();
}