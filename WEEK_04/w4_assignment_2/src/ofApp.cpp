#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//STATE
	currentState = PLAY_MODE;
	//

	shader.load("shader.vert", "shader.frag");
	shader.load("scene2shader.vert", "scene2shader.frag");

	//plane.set(500, 500, 25, 25, OF_PRIMITIVE_TRIANGLES);
	img.load("diffuse_4.jpg");
	img.resize(50, 50);
	img.update();
	plane.set(500, 500, 50, 50, OF_PRIMITIVE_TRIANGLES);
	plane.mapTexCoordsFromTexture(img.getTexture());


	//sphere.setRadius(250);

	//ofSetBackgroundColor(255);

	//SOUND
	ofSetVerticalSync(true);

	soundStream.printDeviceList();

	int bufferSize = 256;


	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);

	bufferCounter = 0;
	drawCounter = 0;
	smoothedVol = 0.0;
	scaledVol = 0.0;

	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
	//

	//GUI
	gui.setup();
	gui.add(radius.setup("radius", 150, 40, 300));
	//
}

//--------------------------------------------------------------
void ofApp::update() {

	//GUI
	sphere.setRadius(radius);
	//

	//SOUND

	//scale vol up to 0-1 range
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);

	volHistory.push_back(scaledVol);

	if (volHistory.size() >= 400) {
		volHistory.erase(volHistory.begin(), volHistory.begin() + 1);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	if (currentState == DEBUG) {

	ofEnableDepthTest();
	ofSetBackgroundColor(0, 46, 167);

	cam.begin();

	shader.begin();
	ofSetColor(255);
	shader.setUniform1f("sound", smoothedVol*200.0);
	sphere.drawWireframe();
	//plane.drawWireframe();
	shader.end();

	cam.end();

	//GUI
	gui.draw();
	//
	}
	else if (currentState == PLAY_MODE) {
		ofSetBackgroundColor(225);

		ofEnableDepthTest();
		img.bind();

		cam.begin();
		shader.begin();
		shader.setUniform1f("time", smoothedVol*100);
		plane.drawWireframe();
		shader.end();
		cam.end();

		ofDisableDepthTest();
	}
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels) {

	float curVol = 0.0;

	// samples are "interleaved"
	int numCounted = 0;

	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
	for (int i = 0; i < bufferSize; i++) {
		left[i] = input[i * 2] * 0.5;
		right[i] = input[i * 2 + 1] * 0.5;

		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted += 2;
	}

	//this is how we get the mean of rms :) 
	curVol /= (float)numCounted;

	// this is how we get the root of rms :) 
	curVol = sqrt(curVol);

	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;

	bufferCounter++;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	switch (key) {
	case 'f':
		ofToggleFullscreen();
		break;
	case '1':
		currentState = PLAY_MODE;
		shader.load("scene2shader.vert", "scene2shader.frag");
		break;
	case '0':
		currentState = DEBUG;
		shader.load("shader.vert", "shader.frag");
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
