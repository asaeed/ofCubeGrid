#pragma once

#include "ofMain.h"
#include "ofxLibwebsockets.h"

#define NUM_MESSAGES 20

class Socket {

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

		// events
		void onConnect(ofxLibwebsockets::Event& args);
		void onOpen(ofxLibwebsockets::Event& args);
		void onClose(ofxLibwebsockets::Event& args);
		void onIdle(ofxLibwebsockets::Event& args);
		void onMessage(ofxLibwebsockets::Event& args);
		void onBroadcast(ofxLibwebsockets::Event& args);

	private:
		ofxLibwebsockets::Server server;
		bool bSetup;
		vector<string> messages;
		string toSend;
};
