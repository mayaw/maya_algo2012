//
//  spiral.cpp
//  5_sinExample_multiCircles
//
//  Created by Maya Weinstein on 9/26/12.
//
//

#include "spiral.h"

//----------------------------------------------------------------------------------------
spiral_left::spiral_left(){
    
    
}
//-----------------------------------------------------------------------------------------
void spiral_left::draw(){
    
    
    float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
	for (int i = 0; i < 20; i++){
        
		float radius = 50 + i * 10;
		float angle = ofGetElapsedTimef()/2 * (1 + i / 10.0);
		float x = xorig + radius * cos(angle*PI/2);
		float y = yorig + radius * -sin(angle*PI/2);
		
		//ofSetRectMode(OF_RECTMODE_CENTER);
		ofSetColor(ofMap(radius, 0, 255, 0, 255), 70);
		ofCircle(x,y,5,5);
        
	}
    
}
//------------------------------------------------------------------------------------------
spiral_right::spiral_right(){
    

}
//--------------------------------------------------------------------------------------------
void spiral_right::draw(){
    
    float xorig = ofGetWidth()/2;
    float yorig = ofGetHeight()/2;
    
    for(int i = 0; i < 50; i ++){
        
        float radius = 50 + i * 10;
        float angle = ofGetElapsedTimef() * (1 - i / 10.0);
        float x = xorig + radius * cos(angle/PI);
        float y = yorig + radius * sin(angle/PI);
        
        ofSetColor(255, 255, 255);
        ofRect(x, y, 5, 5);
    }
}
//-----------------------------------------------------------------------------------------------
spiral_left_bottom::spiral_left_bottom(){
    
}
//----------------------------------------------------------------------------------------------
void spiral_left_bottom::draw(){
    float xorig = 0;
    float yorig = ofGetHeight();

    
    for(int i = 0; i < 20; i ++){
        
        float radius = 50 + i * 10;
        float angle = ofGetElapsedTimef() * (1 + i / 10.0);
        float x = xorig + (i * 20) * cos(angle);
        float y = yorig + (i * 20) * -sin(angle);
        
        ofSetColor(255, 255, 255);
        ofCircle(x, y, 5, 5);
    }
}
//----------------------------------------------------------------------------------------------
spiral_left_top::spiral_left_top(){
    
}
//----------------------------------------------------------------------------------------------
void spiral_left_top::draw(){
    float xorig = 0;
    float yorig = 0;
    
    
    for(int i = 0; i < 20; i ++){
        
        float radius = 50 + i * 10;
        float angle = ofGetElapsedTimef() * (1 + i / 10.0);
        float x = xorig + (i * 20) * cos(angle);
        float y = yorig + (i * 20) * -sin(angle);
        
        ofSetColor(255, 255, 255);
        ofCircle(x, y, 5, 5);
    }

    
}

//----------------------------------------------------------------------------------------------
spiral_right_top::spiral_right_top(){
    
}
//----------------------------------------------------------------------------------------------
void spiral_right_top::draw(){
    float xorig = ofGetWidth();
    float yorig = 0;
    
    
    for(int i = 0; i < 20; i ++){
        
        float radius = 50 + i * 10;
        float angle = ofGetElapsedTimef() * (1 + i / 10.0);
        float x = xorig + (i * 20) * cos(angle);
        float y = yorig + (i * 20) * -sin(angle);
        
        ofSetColor(255, 255, 255);
        ofCircle(x, y, 5, 5);
    }
    
    
}
//----------------------------------------------------------------------------------------------
spiral_right_bottom::spiral_right_bottom(){
    
}
//----------------------------------------------------------------------------------------------
void spiral_right_bottom::draw(){
    float xorig = ofGetWidth();
    float yorig = ofGetHeight();
    
    
    for(int i = 0; i < 20; i ++){
        
        float radius = 50 + i * 10;
        float angle = ofGetElapsedTimef() * (1 + i / 10.0);
        float x = xorig + (i * 20) * cos(angle);
        float y = yorig + (i * 20) * -sin(angle);
        
        ofSetColor(255, 255, 255);
        ofCircle(x, y, 5, 5);
    }
    
    
}
















































