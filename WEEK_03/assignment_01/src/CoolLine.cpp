#pragma once

#include "CoolLine.h"

//tells that the function belongs to coolball
//you have to call this setup, draw, update in the ofApp - else, it doesnt get called ever
void CoolLine::setup() {
	pos = ofPoint(ofRandom(1024), ofRandom(768));
	vel = ofVec2f(ofRandom(-5, 5), ofRandom(-5, 5));
	radius = ofRandom(30, 400);
	r = ofRandom(50, 255);
}

void CoolLine::update() {
	pos += vel; //add velocity to pos = good way to create movement
	vel *= .99; //multiply by some value = quick way to create some friction
}

void CoolLine::draw() {
	//you can send in x, y individ. or send in pos*
	//same as (pos.x, pos.y, 40);
	ofRotate(80, 0.5, 1, 0);
	//ofSetColor(r, r, r);
	ofDrawRectRounded(pos, radius, 10, 5);
}

void CoolLine::keyPressed(int key) {
	switch (key) {
	case 'c':
		break;
	case ' ':
		break;
	case 'v':
		break;
	case OF_KEY_UP:
		ofLog() << "key up!";
		break;
	}
}