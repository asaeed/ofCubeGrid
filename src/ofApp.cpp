#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(1280, 960);

	gui.glue(&socket);
	gui.glue(&cubes);

	vision.setup();
	socket.setup();
	gui.setup();
	cubes.setup();

	ofBackground(0);
	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update()
{
	vision.update();
	gui.update();
	socket.update();
	cubes.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(ofColor::black);

	cubes.draw();
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
	cubes.mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	cubes.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	cubes.mouseReleased(x, y, button);
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