#pragma once

#include "ofMain.h"

class Cube {

public:
	void setup(int size, ofVec3f position);
	void update();
	void draw();
	void mouseMoved(int x, int y, ofCamera * cam);

	ofBoxPrimitive box;

	int boxSize;
	int gapSize;
	int gridWidth;
	int gridHeight;
};
