#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(VF.fieldWidth, VF.fieldHeight);
    ofSetVerticalSync(true);

	ofSetFrameRate(60);

	VF.setupField(102, 76,ofGetWidth(), ofGetHeight());
	VF.randomizeField(6.5);
}

//--------------------------------------------------------------
void testApp::update(){
	//VF.fadeField(0.99f);
    vidGrabber.grabFrame();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    int gridSquareWidth = ofGetWidth()/VF.fieldWidth;
    int gridSquareWidthThird = gridSquareWidth/3;
    int gridSquaereHeight = ofGetHeight()/VF.fieldHeight;
	
    unsigned char * pixels = vidGrabber.getPixels();
    int mappedValue;
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	VF.draw();
	ofDisableAlphaBlending();
    
    
    for (int i = 0; i < VF.fieldWidth; i++){
        for (int j = 0; j < VF.fieldHeight; j++){
            
            // pos in array
            int pos = j * VF.fieldWidth + i;

     int colorIndex = (j * VF.fieldWidth +i) * 3;
    
    
    for (int c=0; c< 3; c++){
        mappedValue = ofMap(pixels[colorIndex + c], 0, 255, 0, gridSquareWidth);
        if(c == 0)
            ofSetColor(pixels[colorIndex + 0],0, 0);
        else if(c==1)
            ofSetColor(0, pixels[colorIndex + 1], 0);
        else
            ofSetColor(0, 0, pixels[colorIndex + 2]);
        
        VF.addCounterClockwiseCircle(i * gridSquareWidth + gridSquareWidthThird * c, j * gridSquaereHeight + gridSquaereHeight, -mappedValue, 0.3);
   
        
    }
        }
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
//	if (button == 0){
//		VF.addOutwardCircle(x,y, 100, 0.3) ;
//	} else {
//		VF.addCounterClockwiseCircle(x, y, 200, 0.3);
//	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
