#include "cube.h"

//--------------------------------------------------------------
void Cube::setup(int size, ofVec3f position)
{
	boxSize = size;
	boxPosition = position;

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

	//bot
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

	box.setResolution(1);
	box.set(size);
	box.setPosition(position);
	//box.setSideColor(ofBoxPrimitive::SIDE_RIGHT, ofColor::black);


	//plane.resizeToTexture();
	//plane.set(size, size);
	//plane.setPosition(position);

	ofDisableArbTex();
	//image.loadImage("logo-green.png");
	image.loadImage("logo-black.jpg");
	//plane.mapTexCoordsFromTexture(image.getTextureReference());

	ofMesh boxBackMesh = box.getSideMesh(ofBoxPrimitive::SIDE_BACK);
	vector<ofPoint> boxBackPoints = boxBackMesh.getVertices();
	//boxBackMesh.enableNormals();
	//boxBackMesh.enableTextures();

	vector<ofVec2f> texCoords = boxBackMesh.getTexCoords();
	//boxBackMesh.addTexCoord(ofVec2f(boxBackPoints[0].x, boxBackPoints[0].y));
	//boxBackMesh.addTexCoord(ofVec2f(boxBackPoints[1].x, boxBackPoints[1].y));
	//boxBackMesh.addTexCoord(ofVec2f(boxBackPoints[2].x, boxBackPoints[2].y));
	//boxBackMesh.addTexCoord(ofVec2f(boxBackPoints[3].x, boxBackPoints[3].y));
	
	
	//boxBackMesh.setTexCoord()
	//boxBackMesh.addTexCoord(texture.getCoordFromPercent(0, 0));
	//boxBackMesh.addTexCoord(texture.getCoordFromPercent(1, 0));
	//boxBackMesh.addTexCoord(texture.getCoordFromPercent(0, 1));
	//boxBackMesh.addTexCoord(texture.getCoordFromPercent(1, 1));
	
	
	targetRotation = box.getOrientationQuat();
	isRotating = false;
	curRotation = 0.0f;
	rotateSpeed = 4.0f;
}

//--------------------------------------------------------------
void Cube::update()
{
	if (box.getGlobalOrientation() != targetRotation)
		box.rotate(rotateSpeed, -1.0f, 1.0f, 0.0f);

	//if (mesh.getGlobalOrientation() != targetRotation)
	//	box.rotate(rotateSpeed, -1.0f, 1.0f, 0.0f);
}

//--------------------------------------------------------------
void Cube::draw()
{
	//box.draw();

	//image.getTextureReference().bind();
	//plane.draw();
	//image.getTextureReference().unbind();

	//box.getSideMesh(ofBoxPrimitive::SIDE_FRONT).drawWireframe();
	//box.draw();

	ofPushMatrix();
	//ofTranslate(boxPosition.x, boxPosition.y);

	if (isRotating) {
		curRotation += rotateSpeed;
		ofRotate(curRotation, boxPosition.x + boxSize/2, boxPosition.y + boxSize / 2, boxPosition.z - boxSize / 2);
		//ofRotateX(curRotation);
	}

	mesh.draw();

	image.getTextureReference().bind();
	front.draw();
	image.getTextureReference().unbind();
	
	ofPopMatrix();
}

void Cube::mouseMoved(int x, int y, ofCamera * cam) {
	ofVec3f posOrig = box.getPosition();
	ofVec3f pos = cam->worldToScreen(box.getPosition());
	float size = box.getWidth();

	// this does not seem accurate
	if (x >= pos.x && x <= pos.x + size && y >= pos.y && y <= pos.y + size) {
		cout << "  (" << posOrig.x << ", " << posOrig.y << ", " << posOrig.z << ") --> (" << pos.x << ", " << pos.y << ", " << pos.z << ") " << endl;
		targetRotation.makeRotate(180.0f, ofVec3f(1.0f, 1.0f));
		isRotating = true;
	}
}