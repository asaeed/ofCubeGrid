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

void Cube::mouseMoved(int x, int y) {
	ofVec3f pos = box.getPosition();
	float size = box.getWidth();

	// this doesn't work, need raytracing
	if (x >= pos.x && x <= pos.x + size && y >= pos.y && y <= pos.y + size) {
		cout << "x: " << pos.x << ", y: " << pos.y << endl;
	}
}