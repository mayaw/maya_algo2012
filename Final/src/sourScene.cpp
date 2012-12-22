//
//  sourScene.cpp
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#include "sourScene.h"
//--------------------------------------------------------------
void sourTestApp::setup(){
    
    ofBackground(255, 255, 255);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 1000; i++){
		sourParticle myParticle;
		myParticle.setInitialCondition(ofRandom(0,1000),ofRandom(0,1000),0,0);
		// more interesting with diversity :)
		// uncomment this:
		//myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
	
}

//--------------------------------------------------------------
void sourTestApp::update(){
    
	// on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		
		
		particles[i].addAttractionForce(ofRandom(ofGetWidth()/2, 500), ofRandom(500, ofGetHeight()/2), 1000, 0.1);
		particles[i].addRepulsionForce(ofRandom(ofGetWidth()/2, 500), ofRandom(500, ofGetHeight()/2), 10, 25);
		
		
		//particles[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 0.1);
		//particles[i].addClockwiseForce(mouseX, mouseY, 200, 1);
		
		particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}
    
}

//--------------------------------------------------------------
void sourTestApp::draw(){
    
	ofSetColor(250, 252, 80, 50);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    
}

//--------------------------------------------------------------
void sourTestApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void sourTestApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void sourTestApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void sourTestApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void sourTestApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void sourTestApp::mouseReleased(){
}
