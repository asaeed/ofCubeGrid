
#ifndef gui_h
#define gui_h

#include "ofMain.h"
#include "ofxGui.h"

class Socket;
class CubeGrid;

class Gui {


public:
	void setup();
	void update();
	void draw();
	void exit();
	void keyPressed(int key);
	bool mousePressed(int x, int y, int button);
	void windowResized(int w, int h);
	void mouseMoved(int x, int y);

	void glue(Socket * x);
	void glue(CubeGrid * x);
	Socket * socketPtr;
	CubeGrid * cubeGridPtr;

	void camPositionZChanged(int & camPositionZ);

	ofParameter<int> camPositionZ;
	ofxButton twoCircles;
	ofParameter<string> screenSize;
	ofParameter<string> mousePos;

	ofxPanel gui;
	bool bHide;
};


#endif