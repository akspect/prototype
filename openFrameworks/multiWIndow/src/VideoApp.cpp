#include "VideoApp.h"

//--------------------------------------------------------------
void VideoApp::setup() {
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
		if(i != 0)	players[i].setLoopState(OF_LOOP_NONE);
		players[i].play();
	}

}

//--------------------------------------------------------------
void VideoApp::update() {


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
	players[contentsKind].draw(0 , 0, ofGetWindowWidth(), ofGetWindowHeight());

	fbo.end();

}


//--------------------------------------------------------------
void VideoApp::draw() {
	fbo.draw(0, 0, ofGetWindowWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void VideoApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void VideoApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void VideoApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void VideoApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void VideoApp::dragEvent(ofDragInfo dragInfo) {

}

void VideoApp::playMedia(ContentsKind contentskind) {

	players[contentsKind].setPosition(0);
	players[contentsKind].play();
}

void VideoApp::getTouchPosition(ofMouseEventArgs & args) {

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