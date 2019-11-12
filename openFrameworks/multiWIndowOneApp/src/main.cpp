#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// multi window
	ofGLFWWindowSettings settings;
	settings.decorated = false;
	settings.setSize(800, 600);
	settings.setPosition(ofVec2f(0, 0));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> videoWindow = ofCreateWindow(settings);
	videoWindow->setVerticalSync(false);

	settings.setSize(900, 200);
	settings.setPosition(ofVec2f(videoWindow->getWidth(), 0));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> touchWindow = ofCreateWindow(settings);

	// setup
	shared_ptr<ofApp> mainApp(new ofApp);
	mainApp->setupSelector();

	//touchWindowのイベントでofAppのメソッド（引数にofEventArgsをとる）を呼ぶ
	ofAddListener(touchWindow->events().update, mainApp.get(), &ofApp::updateSelector);
	ofAddListener(touchWindow->events().draw, mainApp.get(), &ofApp::drawSelector);
	ofAddListener(touchWindow->events().mousePressed, mainApp.get(), &ofApp::getTouchPosition);

	ofRunApp(videoWindow, mainApp);
	ofRunMainLoop();
}
