#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1920, 1080, OF_WINDOW);			// <-------- setup the GL context

	ofGLFWWindowSettings settings;
	settings.multiMonitorFullScreen = true;
	settings.width = 5440;
	settings.height = 1800;
	//settings.windowMode = OF_FULLSCREEN;  // instead of this, ofApp allows 'f' to toggle fullscreen
	ofCreateWindow(settings);

	ofRunApp(new ofApp());
}
