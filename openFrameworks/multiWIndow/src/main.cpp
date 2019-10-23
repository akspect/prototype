#include "ofMain.h"
#include "ofApp.h"
#include "VideoApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	ofGLFWWindowSettings setting;
	setting.decorated = false;
	setting.setSize(800, 600);
	setting.setPosition(ofVec2f(0, 0));
	setting.resizable = true;
	shared_ptr<ofAppBaseWindow> videoWindow = ofCreateWindow(setting);
	videoWindow->setVerticalSync(false);

	setting.setSize(900, 200);
	setting.setPosition(ofVec2f(videoWindow->getWidth(), 0));
	setting.resizable = true;
	shared_ptr<ofAppBaseWindow> touchWindow = ofCreateWindow(setting);

	shared_ptr<VideoApp> videoApp(new VideoApp);
	shared_ptr<ofApp> touchApp(new ofApp);

	//mousePressed‚ÌƒCƒxƒ“ƒg‚ÅgetTouchPosition‚ðŒÄ‚Ô
	ofAddListener(touchWindow->events().mousePressed, videoApp.get(), &VideoApp::getTouchPosition);

	ofRunApp(touchWindow, touchApp);
	ofRunApp(videoWindow, videoApp);

	ofRunMainLoop();
}
