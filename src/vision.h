#pragma once

#include "ofMain.h"
#include "ofxRSSDKv2.h"

class Vision {

public:
	void setup();
	void update();
	void draw();
	void exit();

private:
	// realsense sensor
	ofxRSSDK::RSDevicePtr mRSSDK;
	ofTexture mTexRgb, mTexDepth;

	// temp video grabber
	bool bVideoSetup;
	ofVideoGrabber video;

	// viz
	//std::vector<ofPolyline> lines;
	//std::vector<ofPath> paths;
};
