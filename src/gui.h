
#ifndef gui_h
#define gui_h

#include "ofMain.h"
#include "ofxGui.h"

class Socket;
class Cubes;

class Gui {


public:
	void setup();
	void update();
	void draw();
	void exit();
	void keyPressed(int key);
	bool mousePressed(int x, int y, int button);
	void windowResized(int w, int h);

	void glue(Socket * x);
	void glue(Cubes * x);
	Socket * socketPtr;
	Cubes * cubesPtr;

	void camPositionZChanged(int & camPositionZ);

	ofParameter<int> camPositionZ;
	ofxButton twoCircles;
	ofParameter<string> screenSize;

	ofxPanel gui;
	bool bHide;
};


#endif