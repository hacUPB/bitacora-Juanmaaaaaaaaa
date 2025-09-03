#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void mouseMoved(int x, int y);
	void mousePressed(int x, int y, int button);

private:
	vector<ofVec2f> particles;
	ofColor particleColor;
};
