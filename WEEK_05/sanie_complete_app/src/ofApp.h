#pragma once

#include "ofMain.h"
#include "ofxGui.h"

//STATES
enum gameState {
	//creating variables
	//clean way to manage dif states of game
	START = 0,
	LEVEL_1,
	LEVEL_2,
	LEVEL_3
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

	//FIRST SHADER
	ofShader shader;
	ofImage img;
	ofSpherePrimitive sphere;
	ofEasyCam cam;

	//SECOND SHADER
	ofShader scene2shader;
	ofImage img2;
	ofPlanePrimitive plane;

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
	//

	//GUI
	ofxFloatSlider radius;
	ofxFloatSlider myVolume;
	ofxPanel gui;

	//volume gui
	ofSoundPlayer mySound;

	//STATES
	gameState currentState;

	//TYPE
	ofTrueTypeFont	verdana30;
	bool bFirst;
	string typeStr;

	//TIMER
	float myTimeKeeper;
	string instStr;

	//SCENE 3
	float w, h;
	ofVideoGrabber vid;
};
