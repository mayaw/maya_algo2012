#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.06f;
	
	pos.set(0,0);
	prevPos.set(0,0);
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(255, 255, 255, 100);
    
    float sinOfTime = sin(ofGetElapsedTimef());
    float sinOfTimeMapped = ofMap(sinOfTime, -1, 1, 60, 80);
	
	ofPushMatrix();
		ofTranslate(pos.x, pos.y, 0);
		ofRotateZ(angle * RAD_TO_DEG);
    for(int i = 0; i < 20; i ++){
		myCircles[i]( 0,0, sinOfTimeMapped/4);
        ofSetColor(248,138,175);
    }
		ofCircle(15,0,3,3);
	
	
	ofPopMatrix();
	
	
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	
	
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 

	float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
	
	angle = atan2(dy, dx);

	prevPos.x = pos.x;
	prevPos.y = pos.y;
	

}
