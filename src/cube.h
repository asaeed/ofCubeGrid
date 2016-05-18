#pragma once

#include "ofMain.h"
#include "ofxEasing.h"

class Cube {

public:
	void setup(int size, ofVec3f position, ofMaterial * mat);
	void update();
	void draw(ofLight * light);
	void mouseMoved(int x, int y, ofCamera * cam);

	ofBoxPrimitive box;
	ofPlanePrimitive plane;
	ofMaterial * material;
	ofImage image;

	//ofVboMesh mesh;
	//ofVboMesh front;

	int gridWidth;
	int gridHeight;
	ofVec3f boxPosition;
	ofVec3f axis;
	int boxSize;
	int gapSize;

	bool isRotating;
	bool logoShown;
	float initRotation;
	float targetRotation;
	float lastRotation;

	float initTime;
	float duration;
};
