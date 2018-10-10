#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("practice001");
	cam.setPosition(ofVec3f(0, -2000, 2000));
	cam.setTarget(ofVec3f(0, 300, 0));

	//•`‰æ‚·‚é‰~‚ÌŒÂ”‚ğİ’è
	for (int i = 0; i < 10; i++) {
		radius[i] = ofRandom(100,200);
		startDeg[i] = int(ofNoise(ofRandom(i)) * 10) + i * 180;
		endDeg[i] = int(ofNoise(ofRandom(i)) * 360) + i * 180;
	}
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	float x, y, z;
	float posX, posY, posZ;
	ofVec3f point, pos_point;
	


	cam.begin();

	//•`‰æ‚·‚é‰~‚ÌŒÂ”‚ğİ’è
	for (int i = 0; i < 10; i++) {


		//Šp“x•ª‚¾‚¯•`‰æ‚·‚é
		for (int deg = startDeg[i]; deg < endDeg[i]; deg++) {


			x = radius[i] * cos(deg*DEG_TO_RAD);
			y = radius[i] * sin(deg*DEG_TO_RAD);
			z = ofNoise(ofRandom(deg)) * 100 + i * 50;


			if ( deg != startDeg[i]) {

				//F‚ğ‚Â‚¯‚é
				ofColor circleColor;
				circleColor = ofColor(255, 255, 255);

				switch (i % 3)
				{
				case 1:
					circleColor.g = 0;
					break;

				case 2:
					circleColor.b = 0;
					break;

				default:
					circleColor.r = 0;
					break;
				}
				ofSetColor(circleColor, 255 - i * 10);


				point = ofVec3f(x, y, z);
				pos_point = ofVec3f(posX, posY, posZ);
				ofSetLineWidth(1);
				ofDrawLine(point, pos_point);
			}

			posX = x;
			posY = y;
			posZ = z;

		}
	}

	cam.end();
}