#include "cube.h"

//--------------------------------------------------------------
void Cube::setup(int size, ofVec3f position, ofMaterial * mat)
{
	// because of cam.worldToScreen, it gets pushed away from z:0
	//position.z = 0.0f;  // removed worldToScreen

	boxSize = size;
	boxPosition = position;
	material = mat;

	box.setResolution(1);
	box.set(size);
	box.setPosition(position);
	//box.setSideColor(ofBoxPrimitive::SIDE_RIGHT, ofColor::black);  // this doesn't do anything

	//plane.setResolution(1, 1);  // this seems to break rendering of the image
	plane.set(size, size);
	plane.setPosition(position);
	plane.move(0, 0, boxSize/2 + 0.2f);  // put it just in front of the cube

	//ofDisableArbTex();  // this is needed if mapTexCoords not used below
	image.loadImage("logo-black.jpg");
	//plane.mapTexCoordsFromTexture(image.getTextureReference());
	ofVec4f texCoords = plane.getTexCoords();
	plane.mapTexCoords(208.0f, 208.0f, 0, 0);  // reverse these to flip image
	
	// some initial values
	isRotating = false;
	logoShown = true;
	initRotation = 0.0f;
	targetRotation = 0.0f;
	axis = ofVec3f(-1.0f, 1.0f, 0.0f);

	lastRotation = 0.0f;
	initTime = 0.0f;
	duration = 0.7f;  // in seconds
}

//--------------------------------------------------------------
void Cube::update()
{	
	
	auto now = ofGetElapsedTimef();
	
	if (isRotating) {
		auto endTime = initTime + duration;
		auto currentRotation = ofxeasing::map_clamp(now, initTime, endTime, initRotation, targetRotation, &ofxeasing::linear::easeIn);
		auto diffRotation = currentRotation - lastRotation;
		box.setOrientation(ofQuaternion(currentRotation, axis));
		plane.setOrientation(ofQuaternion(currentRotation, axis));
		plane.rotateAround(diffRotation, axis, ofVec3f(boxPosition.x, boxPosition.y, 0));

		lastRotation = currentRotation;

		if (currentRotation == targetRotation) {
			isRotating = false;
			logoShown = targetRotation != 180.0f;
		}
	}
}

//--------------------------------------------------------------
void Cube::draw(ofLight * light)
{
	material->begin();
	box.draw();
	material->end();

	image.getTextureReference().bind();
	plane.draw();
	image.getTextureReference().unbind();
}

void Cube::mouseMoved(int x, int y, ofCamera * cam) {
	if (isRotating) return;

	ofVec3f pos = box.getPosition();
	pos.y = ofGetWindowHeight() - pos.y;
	//ofVec3f pos = cam->worldToScreen(box.getPosition());
	float size = box.getWidth();

	// this does not seem accurate, hit area is off
	if (x >= pos.x && x <= pos.x + size && y >= pos.y && y <= pos.y + size) {
		//cout << "  (" << posOrig.x << ", " << posOrig.y << ", " << posOrig.z << ") --> (" << pos.x << ", " << pos.y << ", " << pos.z << ") " << endl;
		if (logoShown) {
			initRotation = 0.0f;
			targetRotation = 180.0f;
		} else {
			initRotation = 180.0f;
			targetRotation = 0.0f;
		}
		isRotating = true;
		initTime = ofGetElapsedTimef();
	}
}