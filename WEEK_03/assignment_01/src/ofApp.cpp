#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundAuto(false);
	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();
	ofSetFrameRate(150);

	moreLines.push_back(CoolLine());
	moreLines[0].setup();

}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < moreLines.size(); i++) {
		moreLines[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	//ofEnableAlphaBlending();
	//ofSetBackgroundColor(40, 40, 40, 140);
	//loop through the maount that has been added to this vector, and draw each one:
	for (int i = 0; i < moreLines.size(); i++) {
		moreLines[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

		moreLines.push_back(CoolLine());
		moreLines[moreLines.size() - 1].setup();

	switch (key) {
	case 'c':
		ofSetColor(255, 255, 0, 20);
		break;
	case ' ':
		ofSetColor(255, 255, 255, 20);
		break;
	case 'v':
		ofSetColor(0, 0, 0, 20);
		break;
	case OF_KEY_UP:
		ofLog() << "key up!";
		break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
