#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	
	//ofBackground(9, 0, 78);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ocean.loadImage("ocean1.png");
    
    for (int i = 0; i < 9; i++){
        ofImage temp;
        temp.loadImage("sushi/sushi_0" + ofToString(i) +".png");
        images.push_back(temp);
    }
    
	
	for (int i = 0; i < 60; i++){
		particle myParticle;
        
        int random = (int)ofRandom(0,9);
        
        myParticle.imgPtr = &(images[random]);
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
        
	}
	
	
}

//--------------------------------------------------------------
void testApp::update(){

	panel.update();
	
	for (int i = 0; i < particles.size(); i++){
		
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		for (int j = 0; j < particles.size(); j++){
			if (i != j){
				particles[i].addForFlocking(particles[j]);	
			}
		}
		
		
		
		// this was something we tried in class (partitcle move away from mouse...)
		//particles[i].addRepulsionForce(ofRandom(0, 100), ofRandom(0, 100), 40, 0.4);
        //particles[i].addAttractionForce(ofRandom(0, 100), ofRandom(0, 100), 60, 0.2);
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addFlockingForce();
		particles[i].addDampingForce();
		particles[i].update();
	}
	
	
	// wrap torroidally.
	for (int i = 0; i < particles.size(); i++){
		ofVec2f pos = particles[i].pos;
		if (pos.x < 0) pos.x = ofGetWidth();
		if (pos.x > ofGetWidth()) pos.x = 0;
		if (pos.y < 0) pos.y = ofGetHeight();
		if (pos.y > ofGetHeight()) pos.y = 0;
		particles[i].pos = pos;
	}

}

//--------------------------------------------------------------
void testApp::draw(){
    
	
    ocean.draw(0,0);
    
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	
	ofSetColor(0xffffff);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	panel.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
	if (x < 500){
		particles.erase(particles.begin());
		particle myParticle;
        
        
        int random = (int)ofRandom(0,9);
        
        myParticle.imgPtr = &(images[random]);

        
		float randomAngle = ofRandom(0, TWO_PI);
		myParticle.setInitialCondition(x,y,cos(randomAngle),sin(randomAngle));
		particles.push_back(myParticle);
	}
	
		
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
		
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
	}
