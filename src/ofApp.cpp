#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(1280, 480);
	
	mRSSDK = ofxRSSDK::RSDevice::createUniquePtr();
	if (!mRSSDK->init())
	{
		ofLogError("Unable to create ofxRSSDK object");
		exit();
	}
	else
	{
		mRSSDK->initDepth(ofxRSSDK::DepthRes::R200_SD, 30, true);
		mRSSDK->initRgb(ofxRSSDK::RGBRes::VGA, 30);
		mTexRgb.allocate(mRSSDK->getRgbWidth(), mRSSDK->getRgbHeight(), GL_RGBA);
		mTexDepth.allocate(mRSSDK->getDepthWidth(), mRSSDK->getDepthHeight(), GL_RGBA);

		mRSSDK->enableBlobTracking();

		mRSSDK->start();
	}

	socket.setup();

	////////////////////////////////////////////
	//video.listDevices();
	////video.setDeviceID(3);
	//bVideoSetup = video.initGrabber(320, 240);

	ofBackground(0);
	ofSetFrameRate(30);
	//font.load("myriad.ttf", 20);
}

//--------------------------------------------------------------
void ofApp::update()
{
	mRSSDK->update();
	mTexRgb.loadData(mRSSDK->getRgbFrame(), GL_BGRA);
	mTexDepth.loadData(mRSSDK->getDepth8uFrame());

	std::vector<std::vector<PXCPointI32*>> blobs = mRSSDK->getBlobs();
	//cout << "# of blobs: " << blobs.size() << "  " << mRSSDK->getValidNumBlobs()  << endl;

	socket.update();

	////////////////////////////////////
	//video.update();
	//if (bVideoSetup && video.isFrameNew()) {
	//}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(ofColor::black);

	mTexRgb.draw(0, 0);
	ofPushMatrix();
	ofTranslate(640, 0);
	mTexDepth.draw(0, 0, 640, 480);
	ofPopMatrix();

	//socket.draw();

	////////////////////////////////////
	//if (bVideoSetup) video.draw(0, 0);
}

void ofApp::exit()
{
	mRSSDK->stop();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	socket.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}