#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    for (int i = 0; i < 100; i ++) {
        particle myParticle;
        float vx = ofRandom(-4, 4);
        float vy = ofRandom(-10,20);
        myParticle.setInitialCondition(300, 300, vx, vy);
        myParticle.damping = ofRandom(0.01, 0.05);
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
        particles[i].addForce(0, 0.04);
        particles[i].addDampingForce();
        particles[i].update();
        
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0, 0, 0);
    
    for (int i = 0; i < particles.size(); i++) {
        float vx = ofRandom(-4, 4);
        float vy = ofRandom(-10,20);
        particles[i].draw();
        particles[i].setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, vx, vy);
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