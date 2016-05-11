//
//  gui.cpp
//  GrabDetector
//
//  Created by Ahmad Saeed on 1/29/16.
//
//

#include "gui.h"
#include "socket.h"

void Gui::setup()
{
	datgui->setAssetPath("");
	datgui = new ofxDatGui(0, 0);
	datgui->addHeader(":: Drag ::");
	datgui->addFooter();

	sliderThreshold = datgui->addSlider("threshold", 0, 100, 20);
	cout << socketPtr->fpsReceive << endl;
	sliderThreshold->bind(socketPtr->fpsReceive);

	vector<string> options = { "ONE", "TWO", "THREE", "FOUR" };
	datgui->addDropdown("Detection Method", options);

	sliderThreshold->onSliderEvent(this, &Gui::onSliderEvent);
	ofParamFloat.addListener(this, &Gui::onParamFloatChanged);

}

void Gui::glue(Socket * x) {
	this->socketPtr = x;
}

void Gui::onParamFloatChanged(float & f)
{
	cout << "onParamFloatChanged " << f << endl;
}

void Gui::onSliderEvent(ofxDatGuiSliderEvent e)
{
	if (e.target == sliderThreshold) {
		ofSetBackgroundColor(ofColor::white*e.scale);
		cout << "value = " << e.value << " : scale = " << e.scale << endl;
	}
}

void Gui::update()
{
	datgui->update();
}

void Gui::draw()
{
	datgui->draw();
}

bool Gui::mousePressed(int x, int y, int button) {
	if (ofRectangle(datgui->getPosition(), datgui->getWidth(), datgui->getHeight()).inside(x, y)) {
		return true;
	}
	else {
		return false;
	}
}