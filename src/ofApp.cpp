#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	//ofSetWindowShape(1920, 480);

	gui.glue(&socket);

	vision.setup();
	socket.setup();
	gui.setup();

	ofBackground(0);
	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update()
{
	vision.update();
	gui.update();
	socket.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(ofColor::black);

	vision.draw();
	gui.draw();
	//socket.draw();
}

void ofApp::exit()
{
	vision.exit();
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