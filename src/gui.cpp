//
//  gui.cpp
//  GrabDetector
//
//  Created by Ahmad Saeed on 1/29/16.
//
//

#include "gui.h"
#include "socket.h"
#include "cubeGrid.h"

#include "Gui.h"

void Gui::glue(Socket * x) {
	this->socketPtr = x;
}

void Gui::glue(CubeGrid * x) {
	this->cubeGridPtr = x;
}

//--------------------------------------------------------------
void Gui::setup() {
	ofSetVerticalSync(true);

	// we add this listener before setting up so the initial circle resolution is correct
	camPositionZ.addListener(this, &Gui::camPositionZChanged);

	gui.setup("panel", "settings.xml", 10, 640); // most of the time you don't need a name but don't forget to call setup
	gui.add(camPositionZ.set("circleRes", 1000, 100, 2000));
	gui.add(twoCircles.setup("twoCircles"));
	gui.add(screenSize.set("screenSize", ""));
	gui.add(mousePos.set("mousePos", ""));

	bHide = false;
}

//--------------------------------------------------------------
void Gui::exit() {
	camPositionZ.removeListener(this, &Gui::camPositionZChanged);
}

//--------------------------------------------------------------
void Gui::camPositionZChanged(int & camPositionZ) {
	ofVec3f pos = cubeGridPtr->cam.getPosition();
	pos.z = camPositionZ;
	cubeGridPtr->cam.setPosition(pos);
}

//--------------------------------------------------------------
void Gui::update() {
}

//--------------------------------------------------------------
void Gui::draw() {
	if (!bHide) {
		gui.draw();
	}
}

//--------------------------------------------------------------
void Gui::keyPressed(int key) {
	if (key == 'h') {
		bHide = !bHide;
	}
	if (key == 's') {
		gui.saveToFile("settings.xml");
	}
	if (key == 'l') {
		gui.loadFromFile("settings.xml");
	}
	if (key == ' ') {
		
	}
}

//--------------------------------------------------------------
bool Gui::mousePressed(int x, int y, int button) {
	return true;
}

void Gui::mouseMoved(int x, int y) {
	mousePos = ofToString(x) + ", " + ofToString(y);
}

//--------------------------------------------------------------
void Gui::windowResized(int w, int h) {
	screenSize = ofToString(w) + "x" + ofToString(h);
}
