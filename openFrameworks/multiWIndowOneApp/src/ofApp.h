#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

	enum ContentsKind {
		wait,
		red,
		green,
		blue
	};


public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void setupSelector();
	void updateSelector(ofEventArgs & args);
	void drawSelector(ofEventArgs & args);


	/* Touches */
	void mousePressed(ofMouseEventArgs & mouse);
	void touchDown(ofTouchEventArgs & touch);
	void touchMoved(ofTouchEventArgs & touch);
	void touchUp(ofTouchEventArgs & touch);
	void touchDoubleTap(ofTouchEventArgs & touch);
	void touchCancelled(ofTouchEventArgs & touch);

	map<int, ofTouchEventArgs> touchMap;

	void getTouchPosition(ofMouseEventArgs & args);
	void playMedia(ContentsKind contentsKind);

	int posX, posY;

	ofFbo fbo;
	vector<ofVideoPlayer> players;
	vector<ofImage> images;

	ContentsKind contentsKind = wait;
	vector<string> filename;

};