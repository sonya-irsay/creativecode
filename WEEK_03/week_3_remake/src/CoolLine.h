#pragma once
#include "ofMain.h"

class CoolLine {
	public:
		void setup();
		void update();
		void draw();

		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);

		ofPoint pos;
		int y;
		ofPolyline line;
};