#pragma once

#include "ofMain.h"

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
	int boxSize;
	int gapSize;
	bool isRotating;
	float curRotation;
	float rotateSpeed;
	float targetRotation;
	bool logoShown;
};
