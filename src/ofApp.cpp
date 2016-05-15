#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(1280, 960);

	gui.glue(&socket);
	gui.glue(&cubeGrid);

	vision.setup();
	socket.setup();
	gui.setup();
	cubeGrid.setup();

	ofBackground(0);
	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update()
{
	vision.update();
	gui.update();
	socket.update();
	cubeGrid.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(ofColor::black);

	cubeGrid.draw();
	vision.draw();
	socket.draw();
	gui.draw();
	
}

void ofApp::exit()
{
	vision.exit();
	gui.exit();
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
	cubeGrid.mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	cubeGrid.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	cubeGrid.mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	gui.windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}