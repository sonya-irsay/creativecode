#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	float offset = 50 + ofGetElapsedTimef();

	for (int x = 0; x <= ofGetWidth(); x += 50) {
		for (int y = 0; y <= ofGetHeight(); y += 50) {
			float xPos = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 25);
			float yPos = ofMap(sin(ofGetElapsedTimef()), -1, 1, 25, 0);
			float xSize = ofMap(cos(ofGetElapsedTimef()), -1, 1, 0, 70);
			float ySize = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 70);
			ofRect(x+ xPos, y - yPos, xSize, ySize);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
