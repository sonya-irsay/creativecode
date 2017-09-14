#pragma once

#include "CoolLine.h"

void CoolLine::setup() {
	pos = ofPoint(ofRandom(1024), ofRandom(768));
	y = 100;
}

void CoolLine::update() {

}

void CoolLine::draw() {
	ofSetColor(255, 255, 0);
	//ofDrawCircle(pos, y);
	line.draw();
}

void CoolLine::mouseDragged(int x, int y, int button) {
	ofPoint pt;
	pt.set(x, y);
	line.addVertex(pt);
}

void CoolLine::mousePressed(int x, int y, int button) {
	line.clear();
}