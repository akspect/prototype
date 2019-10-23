#pragma once

#include "ofMain.h"

class VideoApp : public ofBaseApp {
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

	void getTouchPosition(ofMouseEventArgs & args);
	void playMedia(ContentsKind contentsKind);

	int posX, posY;

	ofFbo fbo;
	vector<ofVideoPlayer> players;
	vector<ofImage> images;

	ContentsKind contentsKind = wait;
	vector<string> filename;

};