#include "cube.h"

//--------------------------------------------------------------
void Cube::setup(int size, ofVec3f position)
{
	box.set(size);
	box.setPosition(position);
}

//--------------------------------------------------------------
void Cube::update()
{

}

//--------------------------------------------------------------
void Cube::draw()
{
	box.draw();
}

void Cube::mouseMoved(int x, int y, ofCamera * cam) {
	ofVec3f posOrig = box.getPosition();
	ofVec3f pos = cam->worldToScreen(box.getPosition());
	float size = box.getWidth();

	cout << "(" << x << ", " << y << ")" << endl;
	cout << "  (" << posOrig.x << ", " << posOrig.y << ", " << posOrig.z << ") --> (" << pos.x << ", " << pos.y << ", " << pos.z << ") " << endl;
	// this doesn't work, need raytracing
	if (x >= pos.x && x <= pos.x + size && y >= pos.y && y <= pos.y + size) {
		
	}
}