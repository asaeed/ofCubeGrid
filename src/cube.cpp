#include "cube.h"

//--------------------------------------------------------------
void Cube::setup(int size, ofVec3f position)
{
	box.set(size);
	box.setPosition(position);
	targetRotation = box.getOrientationQuat();
}

//--------------------------------------------------------------
void Cube::update()
{
	if (box.getOrientationQuat() != targetRotation)
		box.rotate(1.0f, 1.0f, 1.0f, 0.0f);
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

	// this does not seem accurate
	if (x >= pos.x && x <= pos.x + size && y >= pos.y && y <= pos.y + size) {
		cout << "  (" << posOrig.x << ", " << posOrig.y << ", " << posOrig.z << ") --> (" << pos.x << ", " << pos.y << ", " << pos.z << ") " << endl;
		targetRotation.makeRotate(180.0f, ofVec3f(1.0f, 1.0f));
	}
}