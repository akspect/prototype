#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofEasyCam cam;

		//�`�悷��e�~�̔��a
		int radius[10];

		//�`�悷��J�n�p�x�ƏI���p�x�̐ݒ�
		int startDeg[10], endDeg[10];
};
