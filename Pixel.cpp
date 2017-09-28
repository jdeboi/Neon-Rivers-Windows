//
//  Pixel.cpp
//  ledInstall
//
//  Created by Jenna deBoisblanc on 7/6/17.
//
//

#include "Pixel.h"
#include <stdio.h>

Pixel::Pixel(){}

Pixel::Pixel(vector<ofPoint> p){
    diodes = p;
	c = 0;
}

void Pixel::draw(ofColor c){
    ofSetColor(c);
	this->c = c;
    for (int i = 0; i < diodes.size(); i++) {
        ofPoint vert = diodes[i];
        ofDrawEllipse(vert, 5, 5);
    }
}

void Pixel::setColor(ofColor col) {
	c = col;
}

unsigned char Pixel::getRed() {
	return c.r;
}

unsigned char Pixel::getGreen() {
	return c.g;
}

unsigned char Pixel::getBlue() {
	return c.b;
}

bool Pixel::inRadius(float x2, float y2, float r) {
	float x1 = diodes[0].x;
	float y1 = diodes[0].y;
	float dx = (x2 - x1)*(x2 - x1);
	float dy = (y2 - y1) * (y2 - y1);
	return (sqrt(dx + dy) < r);
}