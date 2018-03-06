#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetWindowShape(1920, 1080);
	ofSetWindowTitle("practice004");
	ofSetCircleResolution(50);
	radius = ofGetWindowWidth()/5;
	speed0 = 45;
	speed1 = 45;
	polycount = 10;

	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	//â¡éZçáê¨
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	//âΩå¬çÏÇËÇΩÇ¢Ç©
	for (int i = 0; i < polycount; i++) {
		pointsVector.push_back(3);//ê∂ê¨Ç∑ÇÈÉ|ÉCÉìÉgÇÃêî
	}
}

//--------------------------------------------------------------
void ofApp::update(){


	for (int i = 0; i < polycount; i++) {
		pointsVector[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(80);


	for (int i = 0; i < polycount; i++) {
		
		ofColor polycolor = (255,0,0,20);
		pointsVector[i].draw(255/ polycount*i);
	}

	ofSetColor(255);

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
