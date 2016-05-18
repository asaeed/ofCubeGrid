#include "cubeGrid.h"

//--------------------------------------------------------------
void CubeGrid::setup()
{
	boxSize = 100;
	gapSize = 16;
	
	gridWidth = ofGetWindowWidth() / (boxSize + gapSize);
	gridHeight = ofGetWindowHeight() / (boxSize + gapSize);
	//gridWidth = 20;
	//gridHeight = 20;

	cam.setPosition(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 1000);
	cam.enableOrtho();

	light.setup();
	light.setDirectional();
	light.rotate(180, 1, 0, 0);

	lightBehind.setup();
	lightBehind.setDirectional();

	materials.push_back(ofMaterial());
	materials.back().setDiffuseColor(ofFloatColor::blue);
	materials.push_back(ofMaterial());
	materials.back().setDiffuseColor(ofFloatColor::green);
	materials.push_back(ofMaterial());
	materials.back().setDiffuseColor(ofFloatColor::yellow);

	boxes.reserve(gridWidth * gridHeight);

	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			int random = ofRandom(3);
			boxes.push_back(Cube());
			boxes[y + x*gridHeight].setup(boxSize, ofVec3f(x*boxSize + x*gapSize, y*boxSize + y*gapSize, 0), &materials[random]);
		}
	}
}

//--------------------------------------------------------------
void CubeGrid::update()
{
	for (int i = 0; i < boxes.size(); i++) {
		boxes[i].update();
	}
}

//--------------------------------------------------------------
void CubeGrid::draw()
{
	ofEnableDepthTest();
	cam.begin();
	ofEnableLighting();
	light.enable();
	lightBehind.enable();

	material.begin();
	for (int i = 0; i < boxes.size(); i++) {
		boxes[i].draw(&light);
	}
	material.end();

	light.disable();
	lightBehind.disable();
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