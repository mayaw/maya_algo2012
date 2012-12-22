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
    candyImage.loadImage("candy.png");
	
	ofBackground(255,255,255);
    
    spirRadius = 50;
	


	for (int i = 0; i < 100; i ++) {
        particle myParticle;
        float vx = ofRandom(-4, 100);
        float vy = ofRandom(-4,100);
        myParticle.setInitialCondition(ofRandom(ofGetWidth(), 100), ofRandom(ofGetHeight(), 100), 0, 0);
        myParticle.candy = &candyImage;
        particles.push_back(myParticle);  // push_back adds elements to the array
    }

    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
    spirRadius = spirRadius + 0.1;



    for(int i = 0; i < particles.size(); i ++){
        particles[i].resetForce();
        float dx = cos( i + ofGetElapsedTimef());
        float dy = sin( i + ofGetElapsedTimef());
        particles[i].addForce(dx * 0.08,dy * 0.08);
        particles[i].addDampingForce();
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
    //blur.draw(ofNoise(ofRandom(ofGetElapsedTimef(), 50)) * ofGetWidth(), ofNoise(ofGetElapsedTimef()) * ofGetHeight(), 100);
    blur.draw(ofNoise(ofGetElapsedTimef())*ofGetWidth(), ofNoise(ofGetElapsedTimef()+10000)*ofGetHeight(),100);
	
    
    
    //---------------------------------------------
    
    
	ofEnableAlphaBlending();
    ofEnableSmoothing();
	ofSetRectMode(OF_RECTMODE_CENTER);
	for (int i = 0; i < particles.size(); i++){
        //ofSetColor(255, 255, 170);
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
