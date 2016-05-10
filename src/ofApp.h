#pragma once

#include "ofMain.h"
#include "ofxRSSDKv2.h"
#include "socket.h"

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		// websockets
		Socket socket;

	private:
		ofTrueTypeFont font;

		// realsense sensor
		ofxRSSDK::RSDevicePtr mRSSDK;
		ofTexture mTexRgb, mTexDepth;

		// temp video grabber
		bool bVideoSetup;
		ofVideoGrabber video;
};
