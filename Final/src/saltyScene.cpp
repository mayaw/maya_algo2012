//
//  saltyScene.cpp
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#include "saltyScene.h"

//--------------------------------------------------------------
void saltyTestApp::setup(){
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    seeds.loadImage("seeds.png");
    popcorn.loadImage("popcorn.png");
	
	ofBackground(255, 255, 255);
	
	for (int i = 0; i < 100; i++){
		saltyParticle myParticle;
		myParticle.setInitialCondition(ofGetWidth(), ofGetHeight(),ofRandom(-50,100), ofRandom(-50,100));
		myParticle.img = &popcorn;
        myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
	
}

//--------------------------------------------------------------
void saltyTestApp::update(){
    
	// on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	if (ofGetElapsedTimef() < 3) return;
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addForce(0.0, 0.28);
		particles[i].addDampingForce();
		particles[i].bounceOffWalls();
		particles[i].update();
	}
    
}

//--------------------------------------------------------------
void saltyTestApp::draw(){
    
    ofEnableAlphaBlending();
    ofSetColor(255);
    seeds.draw(ofGetWidth(), ofGetHeight()-100);
	
    
    
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    
}

//--------------------------------------------------------------
void saltyTestApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void saltyTestApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void saltyTestApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void saltyTestApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void saltyTestApp::mousePressed(int x, int y, int button){
    //	for (int i = 0; i < particles.size(); i++){
    //		particles[i].setInitialCondition(mouseX,mouseY,ofRandom(-10,10), ofRandom(-10,10));
    //	}
}

//--------------------------------------------------------------
void saltyTestApp::mouseReleased(){
}
