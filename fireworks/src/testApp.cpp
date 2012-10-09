#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    for (int i = 0; i < 100; i ++) {
        particle myParticle;
        float vx = ofRandom(PI, 100);
        float vy = ofRandom(PI,20);
        myParticle.setInitialCondition(100, 100, vx, vy);
        myParticle.damping = ofRandom(-0.01, -0.08);
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
        float dx = cos(20);
        float dy = -sin(400);
        
        particles[i].addForce(0.2, 0.7);
        particles[i].addDampingForce(dx, dy);
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
        particles[i].setInitialCondition(100, 100, vx, vy);
        
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