#include "ofApp.h"

void ofApp::setup() {
	graden.load("temperature.png");
	water.load("drop.png");

	getData();
}

void ofApp::update() {


}

void ofApp::getData() {


	string url = "http://api.openweathermap.org/data/2.5/weather?q=utrecht,nl&appid=37f584c9d170b496e7abe382b2237a5a&units=metric}";
	//string url = "api.openweathermap.org/data/2.5/weather?id=2745912";
	bool succes = json.open(url);
	if (succes) {
		int temperature = json["main"]["temp"].asInt();
		ofLogNotice("ofApp::setup") << json.getRawString();
	}
	else {
		ofLogNotice("ofApp::setup") << "Failed to parse JSON" << endl;
	}

	if (succes) {
			ofLog()<< json["main"]["temp"] << endl;
		}
	else {
		ofLog() << "Oops. No data!" << endl;
	}

}

void ofApp::draw() {
	ofBackground(0);
	ofSetColor(ofColor::antiqueWhite);
	graden.draw(100,100);
	water.draw(200,100);

	temp = json["main"]["temp"].asInt();
	ofDrawRectangle(100,200,50,temp);

	humi = json["main"]["humidity"].asInt();
	ofDrawRectangle(200, 200, 50, humi);


	ofDrawBitmapString("vandaag weer", 90, 90);

	weather = json["weather"][0]["main"].asString();//variable is now not used but is ready for future use
	temp = 34;

	ofDrawBitmapString(weather, 500, 500);

//	ofLog() << weather << " weerok" << endl;

}