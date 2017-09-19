#pragma once

#include "ofMain.h"
#include "CoolLine.h"
//HAVE TO INCLUDE HEADER OF COOLBALL

//define length of array (can never be changed)
//practice of all Caps, no semicolon
#define NUMBALLS 100

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

	//same structure as int x;
	//type name of instance of the class(we make up)
	CoolLine coolerLine;

	//1. creating an array**
	CoolLine lotsOfLines[NUMBALLS];

	//2. using a vector**
	vector<CoolLine> moreLines;

};
