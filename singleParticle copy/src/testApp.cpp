#include "testApp.h"
//you know how to position things in a circle using the formula: x = x_orig + radius * cos (angle); y = y_orig + radius * sin (angle)

//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofBackground(255, 255, 255);
	
	//p.setInitialCondition(300,300,ofRandom(-1,1), ofRandom(-1,1));
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	p.resetForce();
	p.addForce(0, 0.1);
	p.addDampingForce();
	p.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    float x_orig = ofGetWidth()/2;
    float y_orig = ofGetHeight()/2;
    float angle = ofGetElapsedTimef()*2;
    float radius = 20;
    float x = x_orig + radius * cos(angle);
    float y = y_orig + radius * -sin(angle);
    
    p.setInitialCondition(x, y, 50, 50);
	ofSetColor(0x000000);
	p.draw();


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
