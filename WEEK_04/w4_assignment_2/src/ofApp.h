#pragma once

#include "ofMain.h"
#include "ofxGui.h"

//STATE
enum gameState {
	//creating variables
	//clean way to manage dif states of game
	DEBUG = 0,
	PLAY_MODE,
	GAME_OVER
};

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofShader shader;
	//ofPlanePrimitive plane;
	ofSpherePrimitive sphere;
	ofFbo fboSphere;
	ofEasyCam cam;

	//SECOND SHADER
	ofShader scene2shader;
	ofImage img;
	ofPlanePrimitive plane;
	//ofEasyCam cam;

	//SOUND
	void audioIn(float * input, int bufferSize, int nChannels);

	vector <float> left;
	vector <float> right;
	vector <float> volHistory;

	int 	bufferCounter;
	int 	drawCounter;

	float smoothedVol;
	float scaledVol;

	ofSoundStream soundStream;

	ofxFloatSlider radius;
	ofxFloatSlider xdis;
	ofxPanel gui;

	//STATE
	gameState currentState;

};
