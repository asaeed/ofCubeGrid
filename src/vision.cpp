#include "vision.h"

//--------------------------------------------------------------
void Vision::setup()
{
	mRSSDK = ofxRSSDK::RSDevice::createUniquePtr();
	if (!mRSSDK->init())
	{
		ofLogError("Unable to create ofxRSSDK object");
		exit();
	}
	else
	{
		mRSSDK->initDepth(ofxRSSDK::DepthRes::R200_SD, 30, true);
		mRSSDK->initRgb(ofxRSSDK::RGBRes::SM, 30);
		mTexRgb.allocate(mRSSDK->getRgbWidth(), mRSSDK->getRgbHeight(), GL_RGBA);
		mTexDepth.allocate(mRSSDK->getDepthWidth(), mRSSDK->getDepthHeight(), GL_RGBA);
		mRSSDK->enableBlobTracking();
		mRSSDK->setMirrored(true);
		mRSSDK->start();
	}

	////////////////////////////////////////////
	//video.listDevices();
	////video.setDeviceID(3);
	//bVideoSetup = video.initGrabber(320, 240);

	//lines.reserve(4);
}

//--------------------------------------------------------------
void Vision::update()
{
	mRSSDK->update();
	mTexRgb.loadData(mRSSDK->getRgbFrame(), GL_BGRA);
	mTexDepth.loadData(mRSSDK->getDepth8uFrame());

	std::vector<std::vector<PXCPointI32*>> blobs = mRSSDK->getBlobs();
	std::vector<std::vector<int>> blobContourSizes = mRSSDK->getBlobContourSizes();
	//cout << "# of blobs: " << blobs.size() << endl;

	// clear prior contours
	for (int i = 0; i < 4; i++) lines[i].clear();

	// draw first contour of each blob
	for (int i = 0; i < blobs.size(); i++) {
		PXCPointI32 * points = blobs[i][0];
		int numPoints = blobContourSizes[i][0];

		for (int j = 0; j < numPoints; j++) {
			lines[i].addVertex(points[j].x * 2.5, points[j].y * 2.5);
			//paths[i].lineTo(points[j].x, points[j].y);
		}
	}

	////////////////////////////////////
	//video.update();
	//if (bVideoSetup && video.isFrameNew()) {
	//}
}

//--------------------------------------------------------------
void Vision::draw()
{
	//ofClear(ofColor::black);

	mTexRgb.draw(0, 0);
	ofPushMatrix();
	ofTranslate(0, 240);
	mTexDepth.draw(0, 0, 320, 240);
	ofPopMatrix();

	for (int i = 0; i < 4; i++) {
		lines[i].draw();
		//paths[i].draw();
	}

	////////////////////////////////////
	//if (bVideoSetup) video.draw(0, 0);
}

void Vision::exit()
{
	mRSSDK->stop();
}