#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    seeds.loadImage("seeds.png");
    popcorn.loadImage("popcorn.png");
	
	ofBackground(255, 255, 255);
	
	for (int i = 0; i < 100; i++){
		particle myParticle;
		myParticle.setInitialCondition(500,700,ofRandom(-50,100), ofRandom(-50,100));
		myParticle.img = &popcorn;
        myParticle.damping = ofRandom(0.01, 0.05);
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
void testApp::draw(){
    
    ofEnableAlphaBlending();
    seeds.draw(0, 707);
	
    
    	
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
//	for (int i = 0; i < particles.size(); i++){
//		particles[i].setInitialCondition(mouseX,mouseY,ofRandom(-10,10), ofRandom(-10,10));
//	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
