//
//  sweetParticle.cpp
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#include "sweetParticle.h"
#include "ofMain.h"


//------------------------------------------------------------
sweetParticle::sweetParticle(){
	setInitialCondition(0,0,0,0);
	damping = 0.01f;
}

//------------------------------------------------------------
void sweetParticle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void sweetParticle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void sweetParticle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity
	// damping is a force operating in the oposite direction of the
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void sweetParticle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void sweetParticle::update(){
	vel = vel + frc;
	pos = pos + vel;
}

//------------------------------------------------------------
void sweetParticle::draw(){
    //ofCircle(pos.x, pos.y, 3);
    
    candy->draw(pos.x, pos.y, 60, 40);
    
}


