#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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

	//base data types
	//int: integer(-1, 0, 1, 2);
	//float: decimals (-2.003, .0003)
	//string: text("hello world")
	//bool: true/false

	float x;
	float y;

	int cx;
	int cy;

	float angle2;
	bool m_mousePressed;

	ofxFloatSlider radius;
	ofxPanel gui;
};
