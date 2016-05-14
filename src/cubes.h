#pragma once

#include "ofMain.h"

class Cubes {

public:
	void setup();
	void update();
	void draw();

	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

	ofCamera cam;
	ofLight light;
	ofMaterial material;
	ofBoxPrimitive box;

	int boxSize;
	int gapSize;
	int gridWidth;
	int gridHeight;
	vector<ofBoxPrimitive> boxes;
};
