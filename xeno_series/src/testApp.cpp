#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofEnableAlphaBlending();
	ofBackground(30,30,30);
	
	
	// set the position of the rectangle:
	for (int i = 0; i < 5; i ++){
    myRectangles[0].pos.x = 150;
    myRectangles[0].pos.y = 75;
    myRectangles[1].pos.x = 100;
    myRectangles[1].pos.y = 50;
    myRectangles[2].pos.x = 25;
    myRectangles[2].pos.y = 25;
    myRectangles[3].pos.x = 30;
    myRectangles[3].pos.y = 90;
    myRectangles[4].pos.x = 2;
    myRectangles[4].pos.y = 20;
   // myRectangles[i].xenoToPoint(0, 0);
        
        
        
    //myRectangles[i].pos.x = 100;
	//myRectangles[i].pos.y = 50;
        
    }
    
    myRectangles[0].catchUpSpeed += 0.005f;
    myRectangles[1].catchUpSpeed +=0.01f;
    myRectangles[2].catchUpSpeed +=0.00004f;
    myRectangles[3].catchUpSpeed += 0.5f;
    myRectangles[4].catchUpSpeed +=0.000009f;
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int j = 0; j < 5; j ++){
    
    if (catchUpSpeed > 1) catchUpSpeed = 0;
    myRectangles[j].xenoToPoint(mouseX, mouseY);
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i = 0; i < 5; i ++){
        if (i == 0) ofSetColor(200, 100, 200);
        if (i == 1) ofSetColor(255, 0, 0);
        if (i == 2) ofSetColor(0, 255, 0);
        if (i == 3) ofSetColor(0, 0, 255);
        if (i == 4) ofSetColor(100, 100, 20);
	myRectangles[i].draw();
        
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
