#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    for (int i = 0; i < 100; i ++) {
        particle myParticle;
        float vx = ofRandom(PI, 100);
        float vy = ofRandom(PI,20);
        myParticle.setInitialCondition(ofRandom(0,300),ofRandom(0,300), 0,0);
        myParticle.damping = 0.02;
        particles.push_back(myParticle);  // push_back adds elements to the array
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    //every frame we reset the forces
    //add forces on particle
    //perform damping
    //update
    
    for(int i = 0; i < particles.size(); i ++){
        
        
        particles[i].resetForce();
        
        float dx = cos( i + ofGetElapsedTimef());
        float dy = sin( i + ofGetElapsedTimef());
        particles[i].addForce(0,0.06);
        particles[i].addForce(dx*0.1, dy*0.1);
        
        
        
        particles[i].addDampingForce();
        particles[i].update();
        
    }

    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    ofSetColor(250, 7, 105);
    
    for (int i = 0; i < particles.size(); i++) {
        float vx = ofRandom(-4, 100);
        float vy = ofRandom(-10,201);
        particles[i].draw();
        //  particles[i].setInitialCondition(100, 100, vx, vy);  << this should not be called every frame
        
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    
    for (int i = 0; i < particles.size(); i++) {
        particles[i].setInitialCondition(mouseX, mouseY, 0,0);
        
    }
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}