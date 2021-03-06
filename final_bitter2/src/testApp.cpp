#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 200; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());
	VF.randomizeField(2.0);
	
	drawingStyle = 0;
	bFade = false;

}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		
		// get the force from the vector field: 
		ofVec2f frc;
		frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
		particles[i].addForce(frc.x, frc.y);
		particles[i].addDampingForce();
        VF.addClockwiseCircle(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 50, 0.1f);
        VF.addCounterClockwiseCircle(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 50, 0.1f);
       

		particles[i].update();
	}
	
	
	if (bFade == true) VF.fadeField(0.99f);

}

//--------------------------------------------------------------
void testApp::draw(){
	
    
    
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	VF.draw();
	
	ofSetColor(0,0,0);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
}
//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
