#pragma once

#include "ofMain.h"

#include "gui.h"
#include "socket.h"
#include "vision.h"
#include "cubeGrid.h"

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// singleton, sort of - main passes single instance to others
		Gui gui;
		Socket socket;
		Vision vision;
		CubeGrid cubeGrid;

	private:

		
};
