#include "cubeGrid.h"

//--------------------------------------------------------------
void CubeGrid::setup()
{
	boxSize = 50;
	gapSize = 5;
	
	gridWidth = ofGetWindowWidth() / (boxSize + gapSize);
	gridHeight = ofGetWindowHeight() / (boxSize + gapSize);
	//gridWidth = 2;
	//gridHeight = 2;

	cam.setPosition(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 100);
	cam.enableOrtho();

	light.setup();
	light.setDirectional();
	light.rotate(180, 1, 0, 0);

	lightBehind.setup();
	lightBehind.setDirectional();

	material.setDiffuseColor(ofFloatColor::red);
	material.setShininess(100);

	boxes.reserve(gridWidth * gridHeight);

	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			boxes.push_back(Cube());
			boxes[y + x*gridHeight].setup(boxSize, cam.worldToScreen( ofVec3f(x*boxSize + x*gapSize, y*boxSize + y*gapSize, 0)));
		}
	}

	
}

//--------------------------------------------------------------
void CubeGrid::update()
{
	for (int i = 0; i < boxes.size(); i++) {
		boxes[i].update();
	}
	//box.rotate(1, 1.0, 0.0, 0.0);
	//box.rotate(2, 0, 1.0, 0.0);
}

//--------------------------------------------------------------
void CubeGrid::draw()
{
	ofEnableDepthTest();
	cam.begin();
	ofEnableLighting();
	light.enable();
	//lightBehind.enable();

	material.begin();
	for (int i = 0; i < boxes.size(); i++) {
		boxes[i].draw();
	}
	material.end();

	light.disable();
	//lightBehind.disable();
	ofDisableLighting();
	cam.end();
	ofDisableDepthTest();
}

//--------------------------------------------------------------
void CubeGrid::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void CubeGrid::mouseReleased(int x, int y, int button) {

}

void CubeGrid::mouseMoved(int x, int y) {
	for (int i = 0; i < boxes.size(); i++) {
		boxes[i].mouseMoved(x, y, &cam);
	}
}