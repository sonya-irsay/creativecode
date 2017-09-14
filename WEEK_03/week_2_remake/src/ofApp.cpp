#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	moreLines.push_back(CoolLine());
	moreLines[0].setup();

}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < moreLines.size(); i++) {
		moreLines[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i < moreLines.size(); i++) {
		moreLines[i].draw();
	}
	moreLines.push_back(CoolLine());
	moreLines[moreLines.size() - 1].setup();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//if (key == 'c') {
		//two ways to create a ball on keypress
		///A
		//moreLines.push_back(CoolLine());
		//moreLines[moreLines.size() - 1].setup();

		/////B
		//CoolLine tempLine;
		//tempLine.setup();
		//moreLines.push_back(tempBall);
	//}
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
