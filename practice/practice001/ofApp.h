#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofEasyCam cam;

		//•`‰æ‚·‚éŠe‰~‚Ì”¼Œa
		int radius[10];

		//•`‰æ‚·‚éŠJnŠp“x‚ÆI—¹Šp“x‚Ìİ’è
		int startDeg[10], endDeg[10];
};
