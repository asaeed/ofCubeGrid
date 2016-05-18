#include "cube.h"

//--------------------------------------------------------------
void Cube::setup(int size, ofVec3f position, ofMaterial * mat)
{
	// because of cam.worldToScreen, it gets pushed away from z:0
	position.z = 0.0f;

	boxSize = size;
	boxPosition = position;
	material = mat;

	/*
	mesh.addVertex(ofVec3f(0, 0, 0)*size + position);//0
	mesh.addVertex(ofVec3f(1, 0, 0)*size + position);//1
	mesh.addVertex(ofVec3f(1, 0, -1)*size + position);//2
	mesh.addVertex(ofVec3f(0, 0, -1)*size + position);//3
	//top face vertices
	mesh.addVertex(ofVec3f(0, 1, 0)*size + position);//4
	mesh.addVertex(ofVec3f(1, 1, 0)*size + position);//5
	mesh.addVertex(ofVec3f(1, 1, -1)*size + position);//6	
	mesh.addVertex(ofVec3f(0, 1, -1)*size + position);//7

	//front face vertices
	front.addVertex(ofVec3f(0, 0, 0)*size + position);//0
	front.addTexCoord(ofVec2f(0, 0));
	front.addVertex(ofVec3f(1, 0, 0)*size + position);//1
	front.addTexCoord(ofVec2f(0, 1));
	front.addVertex(ofVec3f(1, 1, 0)*size + position);//2
	front.addTexCoord(ofVec2f(1, 1));
	front.addVertex(ofVec3f(0, 1, 0)*size + position);//3
	front.addTexCoord(ofVec2f(1, 0));

	//front
	front.addTriangle(0, 1, 2);
	front.addTriangle(2, 3, 0);
	//bottom
	mesh.addTriangle(0, 1, 2);
	mesh.addTriangle(2, 3, 0);
	//top	
	mesh.addTriangle(4, 5, 6);
	mesh.addTriangle(6, 7, 4);
	//back
	mesh.addTriangle(3, 2, 6);
	mesh.addTriangle(6, 7, 3);
	//right
	mesh.addTriangle(1, 2, 6);
	mesh.addTriangle(6, 5, 1);
	//left
	mesh.addTriangle(0, 3, 7);
	mesh.addTriangle(7, 4, 0);
	*/

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
	plane.mapTexCoords(208.0f, 208.0f, 0, 0);
	
	// some initial values
	targetRotation = 0.0f;
	isRotating = false;
	curRotation = 0.0f;
	rotateSpeed = 6.0f;  // for now, this has to be a factor of 180.0f to stop after 1/2 rotation
	logoShown = true;
}

//--------------------------------------------------------------
void Cube::update()
{	
	if (isRotating) {
		float angle, x, y, z;
		box.getOrientationQuat().getRotate(angle, x, y, z);

		if (angle < targetRotation) {
			box.rotate(rotateSpeed, -1.0f, 1.0f, 0.0f);

			plane.rotateAround(rotateSpeed, ofVec3f(-1.0f, 1.0f, 0.0f), ofVec3f(boxPosition.x, boxPosition.y, 0));
			plane.rotate(rotateSpeed, -1.0f, 1.0f, 0.0f);
		}
		else {
			box.setOrientation(ofQuaternion(targetRotation, ofVec3f(x, y)));
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

	//box.getSideMesh(ofBoxPrimitive::SIDE_FRONT).drawWireframe();

	/*
	ofPushMatrix();
	//ofTranslate(boxPosition.x, boxPosition.y);

	if (isRotating) {
		curRotation += rotateSpeed;
		ofRotate(curRotation, boxPosition.x + boxSize/2, boxPosition.y + boxSize / 2, boxPosition.z - boxSize / 2);
	}

	mesh.draw();

	image.getTextureReference().bind();
	front.draw();
	image.getTextureReference().unbind();

	ofPopMatrix();
	*/
}

void Cube::mouseMoved(int x, int y, ofCamera * cam) {
	ofVec3f pos = box.getPosition();
	pos.y = ofGetWindowHeight() - pos.y;
	//ofVec3f pos = cam->worldToScreen(box.getPosition());
	float size = box.getWidth();

	// this does not seem accurate
	if (x >= pos.x && x <= pos.x + size && y >= pos.y && y <= pos.y + size) {
		//cout << "  (" << posOrig.x << ", " << posOrig.y << ", " << posOrig.z << ") --> (" << pos.x << ", " << pos.y << ", " << pos.z << ") " << endl;
		//targetRotation.makeRotate(180.0f, ofVec3f(1.0f, 1.0f));
		if (logoShown)
			targetRotation = 180.0f;
		else
			targetRotation = 0.0f;
		isRotating = true;
	}
}