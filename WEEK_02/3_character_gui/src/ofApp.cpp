#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	gui.setup();
	gui.add(radius.setup("radius", 178, 91, 300));

	ofSetBackgroundColor(212,212,212,10);
	//circle biger = higher res, circle smaller = lower res; be concious + efficient
	ofSetCircleResolution(50);

	m_mousePressed = false;
}

//--------------------------------------------------------------
void ofApp::update() {
	x = .99 * x + (1 - .99) * mouseX;
	y = .99 * y + (1 - .99) * mouseY;

	cy = 100 * sin(angle2);
	cx = 100 * cos(angle2);
}

//--------------------------------------------------------------
void ofApp::draw() {
	//set sin fill color
	float r = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 255);
	float g = ofMap(sin(ofGetElapsedTimef() * .25), -1, 1, 0, 255);
	float b = ofMap(sin(ofGetElapsedTimef() * .5), -1, 1, 0, 255);
	ofSetColor(r, g, b);

	float angle = atan2(mouseY - y, mouseX - x);
	angle = ofRadToDeg(angle);

	ofSetRectMode(OF_RECTMODE_CENTER);

	ofPushMatrix();
	//translate the whole x,y "grid"
	ofTranslate(x, y);
	//rotate should come after translate, rotate the whole "grid"
	ofRotate(angle);
	//draw face
	ofDrawRectangle(0, 0, radius, radius);
	//draw eyes:
	ofSetColor(53, 244, 211);
	ofDrawRectangle(radius/5, 15, radius/3.5, radius/3.5);
	ofDrawRectangle(-radius/5, 15, radius/3.5, radius/3.5);
	if (m_mousePressed) {
	//draw mouth open
		ofDrawCircle(0, -radius /4, 20);
	}
	//draw mouth closed
	else {
		ofDrawRectangle(0, -radius / 4, 38, 10);
	}

	ofPopMatrix();

	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
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
	m_mousePressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	m_mousePressed = false;
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
