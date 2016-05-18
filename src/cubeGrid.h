#pragma once

#include "ofMain.h"
#include "cube.h"

class CubeGrid {

public:
	void setup();
	void update();
	void draw();

	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseMoved(int x, int y);

	ofCamera cam;
	ofLight light;
	ofLight lightBehind;
	ofMaterial material;
	vector<ofMaterial> materials;

	int boxSize;
	int gapSize;
	int gridWidth;
	int gridHeight;
	vector<Cube> boxes;
};
