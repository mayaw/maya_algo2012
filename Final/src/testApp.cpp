#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    scenes[0] = new bitterTestApp();
    scenes[1] = new sweetTestApp();
    scenes[2] = new umamiTestApp();
    scenes[3] = new saltyTestApp();
    scenes[4] = new sourTestApp();
    
    currentScene = -1;
    
    for(int i = 0; i < 5; i ++){
        scenes[i] -> setup();
    }
}

//--------------------------------------------------------------
void testApp::update(){

    if (currentScene >= 0)
    scenes[currentScene] -> update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(255);
    
    if (currentScene >=0)
    scenes[currentScene] ->draw();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    

  
    if (key == ' '){
        currentScene = 0;
    }
    
    if (key == OF_KEY_UP){
        currentScene = 1;
    }
    
    if (key == OF_KEY_RIGHT){
        currentScene = 2;
    }
    if (key == OF_KEY_DOWN){
        currentScene = 3;
    }
    if (key == OF_KEY_LEFT){
        currentScene = 4;
    }

   // currentScene++;
//	currentScene %= 5;
	
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