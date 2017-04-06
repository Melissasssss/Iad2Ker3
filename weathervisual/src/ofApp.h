#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp {

public:
	void setup();

	void update();

	void draw();

	void getData();

	string weather;
	float temp;
	float humi;
	ofImage graden;
	ofImage water;


private:

	ofxJSONElement json;

};