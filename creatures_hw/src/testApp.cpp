#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
    ofBackgroundGradient(ofColor(247,246,233),ofColor(226,222,180));
    //ofBackground(255, 255, 255, 170);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    muscle.loadImage("muscle.png");
	
	
	
//	particle myParticle;
//	myParticle.setInitialCondition(400,400,0,0);
//	particles.push_back(myParticle);
//	
//	myParticle.setInitialCondition(400,500,0,0);
//	particles.push_back(myParticle);
//	
//	myParticle.setInitialCondition(500,500,0,0);
//	particles.push_back(myParticle);
//	
//	myParticle.setInitialCondition(500,400,0,0);
//	particles.push_back(myParticle);
    
    for (int i = 0; i < 20; i++){
        particle myParticle;
        myParticle.setInitialCondition(ofRandom(400, 500), ofRandom(400,500),0, 0);
        myParticle.img = &muscle;
        particles.push_back(myParticle);
    }
	
	spring mySpring;
		
	for (int i = 0; i < particles.size(); i++){
		
		mySpring.distance		= ofRandom(50,100);
		mySpring.springiness	= 0.2f;
		mySpring.particleA = & (particles[i  ]);
		mySpring.particleB = & (particles[(i+1) % particles.size()]);
		springs.push_back(mySpring);
	}
	

	mySpring.distance		= (particles[0].pos-particles[2].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (particles[2]);
	springs.push_back(mySpring);
	
	mySpring.distance		= (particles[1].pos-particles[3].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (particles[3]);
	springs.push_back(mySpring);
    
    
    
    
    mySpring.distance		= (particles[4].pos-particles[6].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[4]);
	mySpring.particleB = & (particles[6]);
	springs.push_back(mySpring);
	
	mySpring.distance		= (particles[5].pos-particles[7].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[5]);
	mySpring.particleB = & (particles[7]);
	springs.push_back(mySpring);
    
    
    mySpring.distance		= (particles[8].pos-particles[10].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[8]);
	mySpring.particleB = & (particles[10]);
	springs.push_back(mySpring);
    
    
    mySpring.distance		= (particles[9].pos-particles[11].pos).length();
	mySpring.springiness	= 0.4f;
	mySpring.particleA = & (particles[9]);
	mySpring.particleB = & (particles[11]);
	springs.push_back(mySpring);

	

    
    mySpring.distance		= (particles[12].pos-particles[14].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[12]);
	mySpring.particleB = & (particles[14]);
	springs.push_back(mySpring);
	
	mySpring.distance		= (particles[13].pos-particles[15].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[13]);
	mySpring.particleB = & (particles[15]);
	springs.push_back(mySpring);
    
    
    
    
    mySpring.distance		= (particles[16].pos-particles[18].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[16]);
	mySpring.particleB = & (particles[18]);
	springs.push_back(mySpring);
	
	mySpring.distance		= (particles[17].pos-particles[19].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[17]);
	mySpring.particleB = & (particles[19]);
	springs.push_back(mySpring);

    
    
    
    
	
		
	
		
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
//	springs[0].distance = 100 + 50 * sin(ofGetElapsedTimef()*8);
//	springs[2].distance = 100 + 50 * sin(ofGetElapsedTimef()*8 + PI);
    
    for(int i = 0; i < springs.size(); i++){
        mySpring.distance = 100 + 50 * sin(ofGetElapsedTimef()*2);
    }
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addForce(0,0.1f);
		particles[i].addRepulsionForce(mouseX, mouseY, 300, 0.7f);
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}
    
    drawingStyle = 0;
	bFade = false;
    bSavePdf = false;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    if (bSavePdf == true){
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
    }
	
    //background.draw(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), ofGetHeight());
	
    ofBackgroundGradient(ofColor(247,246,233),ofColor(226,222,180));
    ofEnableAlphaBlending();
	//ofSetColor(0,130,130, 200);
	
	//ofSetColor(255,255,255,80);
    
    ofSetColor(92, 4, 182, 40);
    for(int i = 0; i < ofGetWidth() +5; i+=25){
        for(int j = 0; j < ofGetHeight() + 5; j+=25){
            ofEllipse(i,j, 3, 3);
            ofTriangle(i, j + 20, i + 10, j, i + 20, j + 20);
}
    }
    
    
	
	ofSetRectMode(OF_RECTMODE_CENTER);

	ofSetColor(141,124,68);
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
    ofSetColor(137,18,24);
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}
    
    if( bSavePdf ){
		ofEndSaveScreenAsPDF();
        bSavePdf = false;
	}


}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
	}
	if (key == 'p'){
        
        bSavePdf = true;
    
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	particles[0].pos.set(mouseX, mouseY);
	/*particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);*/
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
	particles[0].bFixed = false;
}

