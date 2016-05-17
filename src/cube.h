#pragma once

#include "ofMain.h"

class Cube {

public:
	void setup(int size, ofVec3f position);
	void update();
	void draw();
	void mouseMoved(int x, int y, ofCamera * cam);

	ofBoxPrimitive box;
	ofQuaternion targetRotation;
	ofImage image;
	ofTexture texture;

	ofPlanePrimitive plane;

	ofVboMesh mesh;
	ofVboMesh front;

	int gridWidth;
	int gridHeight;
	ofVec3f boxPosition;
	int boxSize;
	int gapSize;
	bool isRotating;
	float curRotation;
	float rotateSpeed;
};
