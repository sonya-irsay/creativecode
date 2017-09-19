#pragma once

#include "ofMain.h"

class CoolLine {

	//public = external
	//if private = can call internally //here we are defining the ingredients (what functions + variables the class has)
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	//can have any other functions we want in here:
	//can also add variables:
	//ofPoint is an object itself (intertangeable with ofVec)
	//convinient to keep an x, y value in one variable:
	ofPoint pos;
	ofVec2f vel;
	int radius;
	float r;

};