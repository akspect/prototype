#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {

	ofBackground(255);
	ofSetWindowTitle("practice002");

	camDeg = 0;
	ofSetLineWidth(3);
	ofSetVerticalSync(true);

	ofSetFrameRate(30);
	//ofSetBackgroundAuto(false);
	ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::update(){

	if (camDeg >= 360) {
		camDeg = 0;
	}

	camDeg++;


	for (int i = circles.size() - 1; i > -1; i--) {

		circles[i].update();

		if (circles[i].isDead()) {

			circles.erase(circles.begin() + i);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofGradientMode mode = OF_GRADIENT_CIRCULAR;
	ofColor back_color;
	back_color.setHsb(ofGetFrameNum() % 255, 50, 255, 0);
	ofBackgroundGradient(back_color, ofColor(255, 255 , 255), mode);

	camY = sin(camDeg * DEG_TO_RAD)*500;
	camZ = cos(camDeg * DEG_TO_RAD)*500;


	ofVec3f upVector;
	upVector.set(0, 1, 0);

	cam.setPosition(0, camY, camZ);
	cam.lookAt(ofVec3f(0, 0, 0), upVector);

	cam.begin();

	ofColor body_color;
	body_color.setHsb(ofGetFrameNum() % 255, 255, 255, 100);

	ofFill();
	ofSetColor(body_color);

	if (ofNoise(ofGetFrameNum() * 0.05) > 0.5) {
		this->circles.push_back(Circle(body_color, ofRandom(0)));
	}

	for (Circle r : this->circles) {
		r.draw();
	}

	cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
