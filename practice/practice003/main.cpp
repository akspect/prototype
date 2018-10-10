#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//--------------------------------------------------------------
int main()
{
	ofAppGLFWWindow window;
	//ofSetupOpenGL(1920, 1080, OF_FULLSCREEN);
    ofGLFWWindowSettings settings;
    
    settings.width = 1280;
    settings.height = 720;
    settings.decorated = false;
    settings.windowMode = OF_WINDOW;

    ofCreateWindow(settings);
	ofRunApp(new ofApp);
}
