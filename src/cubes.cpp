#include "cubes.h"

//--------------------------------------------------------------
void Cubes::setup()
{
	cam.setPosition(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 900);
	//cam.enableOrtho();

	light.setup();
	light.setDirectional();
	light.rotate(180, 1, 0, 0);

	material.setDiffuseColor(ofFloatColor::red);
	material.setShininess(100);

	boxSize = 50;
	gapSize = 5;

	gridWidth = ofGetWindowWidth() / boxSize;
	gridHeight = ofGetWindowHeight() / boxSize;

	boxes.reserve(gridWidth * gridHeight);

	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			boxes.push_back(ofBoxPrimitive());
			boxes[y + x*gridHeight].set(boxSize);
			boxes[y + x*gridHeight].setPosition(x*boxSize + x*gapSize, y*boxSize + y*gapSize, 0);
		}
	}

	//box.set(50);
	//box.setPosition(ofGetWidth()*.5, ofGetHeight()*.25, 0);
	
	//ofEnableDepthTest();
}

//--------------------------------------------------------------
void Cubes::update()
{
	//box.rotate(1, 1.0, 0.0, 0.0);
	//box.rotate(2, 0, 1.0, 0.0);
}

//--------------------------------------------------------------
void Cubes::draw()
{
	ofEnableDepthTest();
	cam.begin();
	ofEnableLighting();
	light.enable();

	material.begin();
	for (int i = 0; i < boxes.size(); i++) {
		boxes[i].draw();
	}
	material.end();

	light.disable();
	ofDisableLighting();
	cam.end();
	ofDisableDepthTest();
}

//--------------------------------------------------------------
void Cubes::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void Cubes::mouseReleased(int x, int y, int button) {

}