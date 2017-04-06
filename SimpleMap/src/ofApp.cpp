#include "ofApp.h"

void ofApp::setup() {
    // statische kaart gegenereerd op http://staticmapmaker.com/google/
    mapImage.load("staticmap.png");

	bakkerijRif.resize(100,100);
	sistermoon.resize(100,100);
	//bakkerijRif.load("bakkerijrif");
	imgHotSpots[0].load("bakkerijrif.jpg");	
	imgHotSpots[1].load("sistermoon.jpg");
	imgHotSpots[3].load("bakkerijrif.jpg");
	imgHotSpots[4].load("sistermoon.jpg");

    hotSpots[0] = ofRectangle(841, 56, 50, 50);
    hotSpots[1] = ofRectangle(400, 100, 50, 150);
    hotSpots[2] = ofRectangle(300, 400, 150, 50);
    hotSpots[3] = ofRectangle(50, 500, 350, 50);
}

void ofApp::update() {

}

void ofApp::draw() {
    ofSetColor(ofColor::white);
    mapImage.draw(0, 0);

    ofSetColor(ofColor::black);
    ofDrawBitmapString("MouseX:" + ofToString(mouseX), 700, 20);
    ofDrawBitmapString("MouseY:" + ofToString(mouseY), 700, 40);

    if (drawHotspots) {
        ofNoFill();
        ofSetColor(ofColor::red);
        for (int i = 0; i < HOTSPOT_COUNT; i++) {
            ofDrawRectangle(hotSpots[i]);
        }
    }
	ofSetColor(ofColor::white); 
	for (int i = 0; i < HOTSPOT_COUNT; i++) {
		imgHotSpots[i].draw(hotSpots[i].x, hotSpots[i].y);
	}

    ofSetColor(ofColor::white);
    for (int i = 0; i < HOTSPOT_COUNT; i++) {
        if (hotSpots[i].inside(mouseX, mouseY)) {
            ofDrawBitmapString("Hotspot " + ofToString(i), 700, 100);
        }
    }
}

void ofApp::keyPressed(int key) {
    if (key == 'h') {
        drawHotspots = !drawHotspots;
    }
}

// 2e manier:
void ofApp::mouseMoved(int x, int y) {
    for (int i = 0; i < HOTSPOT_COUNT; i++) {
        if (hotSpots[i].inside(x, y)) {
            // doe iets met de hotspot
            ofLog() << "Hotspot " << i << endl;
        }
    }
}