#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    gummyImage.loadImage("gummy.png");
    star.loadImage("star.png");
    sun.loadImage("sun.png");
    blur.loadImage("blur.png");
    spiral.loadImage("spiral.png");
    explosion.loadImage("explosion.png");
	
	ofBackground(255,255,255);
    
    spirRadius = 50;
	
	for (int i = 0; i < 50; i++){
		particle myParticle;
		myParticle.setInitialCondition(300,300,ofRandom(-50,50), ofRandom(-10,10));
		// more interesting with diversity :)
		myParticle.damping = ofRandom(0.01, 0.01);
        myParticle.gummy = &gummyImage;
		particles.push_back(myParticle);
	}
	
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
    spirRadius = spirRadius + 0.1;

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addForce(0.0, 0.4);
		particles[i].addDampingForce();
		particles[i].bounceOffWalls();
		particles[i].update();
	}

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
	float xorig = ofRandom(500,500);
	float yorig = ofRandom(500,500);
	float angle = ofGetElapsedTimef()*3.5;
	float radius = 200;

    
    float x = ofRandom(cos(angle), ofGetWidth());
    float y = ofRandom(-sin(angle), ofGetHeight());
	
	ofPoint temp;
	temp.x = x;
	temp.y = y;
	points.push_back(temp);
	if (points.size() > 20){
		points.erase(points.begin());
	}
	
	ofNoFill();
    for (int i = 0; i < points.size(); i++){
    explosion.draw(points[i].x, points[i].y);
	}



    ofEnableAlphaBlending();
	//sun.draw(ofNoise(ofGetElapsedTimef())*ofGetWidth(), ofNoise(ofGetElapsedTimef()+10000)*ofGetHeight(),50);
    blur.draw(ofNoise(ofGetElapsedTimef())*ofGetWidth(), ofNoise(ofGetElapsedTimef()+10000)*ofGetHeight(),100);
	
    
    
    //---------------------------------------------
    
    
	ofEnableAlphaBlending();
    ofEnableSmoothing();
	ofSetRectMode(OF_RECTMODE_CENTER);
	for (int i = 0; i < particles.size(); i++){
        ofSetColor(255, 255, 170);
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
