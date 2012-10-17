#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0, 0, 0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 1000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,1000),ofRandom(0,1000),0,0);
		// more interesting with diversity :)
		// uncomment this: 
		myParticle.damping = ofRandom(0.01, 0.01);
		particles.push_back(myParticle);
	}
	
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
		
		
		particles[i].addAttractionForce(mouseX, mouseY, 1000, 0.1);
		particles[i].addRepulsionForce(mouseX, mouseY, 60, 1);
		
		
		//particles[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 0.1);
		//particles[i].addClockwiseForce(mouseX, mouseY, 200, 1);
		
		particles[i].addForce(0.01,0.02);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
        
        float dx = cos( i + ofGetElapsedTimef());
        float dy = sin( i + ofGetElapsedTimef());
        float angle = atan2(dy, dx);
        
        range = ofMap(angle, 0, 255, 0, 255);
        color.setHsb(range * 255, 255, 255);
        
	}

}

//--------------------------------------------------------------
void testApp::draw(){

	//ofSetColor(0x000000);
    ofSetColor(color.r, color.g, color.b);
	
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
