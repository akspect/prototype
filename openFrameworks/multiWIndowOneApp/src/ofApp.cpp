#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	posX = 0;
	posY = 0;

	ofSetLogLevel(OF_LOG_NOTICE);
	ofLogToConsole();

	filename.push_back("black.mp4");
	filename.push_back("red.mp4");
	filename.push_back("green.mp4");
	filename.push_back("blue.mp4");

	fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
	for (int i = 0; i < filename.size(); i++) {
		players.push_back(ofVideoPlayer());
		players.back().load(filename[i]);
		if (i != 0)	players[i].setLoopState(OF_LOOP_NONE);
		players[i].play();
	}
}

void ofApp::setupSelector() {

}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < filename.size(); i++) {
		players[i].update();
	}

	if (contentsKind != wait && players[contentsKind].getIsMovieDone()) {
		// ‘Ò‹@‰æ–ÊˆÈŠO‚ÅÅŒã‚Ü‚ÅÄ¶‚µ‚½‚ç‘Ò‹@‰æ–Ê‚É–ß‚é
		contentsKind = wait;
		playMedia(contentsKind);
	}


	fbo.begin();
	ofClear(ofColor(0));

	// draw media
	players[contentsKind].draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	fbo.end();
}

void ofApp::updateSelector(ofEventArgs & args) {

}

//--------------------------------------------------------------
void ofApp::draw() {
	fbo.draw(0, 0, ofGetWindowWidth(), ofGetHeight());
}

void ofApp::drawSelector(ofEventArgs & args){
	ofSetColor(10, 10, 10);
	ofDrawRectangle(0, 0, 100, 100);

	ofSetColor(255, 0, 0);
	ofDrawRectangle(0, 0, 300, ofGetHeight());

	ofSetColor(0, 255, 0);
	ofDrawRectangle(300, 0, 300, ofGetHeight());

	ofSetColor(0, 0, 255);
	ofDrawRectangle(600, 0, 300, ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(ofMouseEventArgs & touch) {
	
}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch) {
	touchMap[touch.id] = touch;
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch) {
	touchMap[touch.id] = touch;
}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch) {
	touchMap.erase(touch.id);
}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch) {

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch) {
	touchMap.erase(touch.id);
}


void ofApp::playMedia(ContentsKind contentskind) {

	players[contentsKind].setPosition(0);
	players[contentsKind].play();
}

void ofApp::getTouchPosition(ofMouseEventArgs & args) {

	posX = args.x;
	posY = args.y;

	// change media
	if (posX < 300 && contentsKind != red) {
		contentsKind = red;
		playMedia(contentsKind);
		ofLogNotice() << "red : " << posX;
	}
	else if (posX >= 300 && posX < 600 && contentsKind != green) {
		contentsKind = green;
		playMedia(contentsKind);
		ofLogNotice() << "green : " << posX;
	}
	else if (posX >= 600 && contentsKind != blue) {
		contentsKind = blue;
		playMedia(contentsKind);
		ofLogNotice() << "blue : " << posX;
	}

}