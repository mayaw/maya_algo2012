//
//  saltyParticle.cpp
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#include "saltyParticle.h"
#include "ofMain.h"


//------------------------------------------------------------
saltyParticle::saltyParticle(){
	setInitialCondition(0,0,0,0);
	damping = 0.01f;
}

//------------------------------------------------------------
void saltyParticle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void saltyParticle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void saltyParticle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity
	// damping is a force operating in the oposite direction of the
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void saltyParticle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void saltyParticle::update(){
	vel = vel + frc;
	pos = pos + vel;
}

//------------------------------------------------------------
void saltyParticle::draw(){
    img->draw(pos.x, pos.y, 100, 100);
}


//------------------------------------------------------------
void saltyParticle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit... for now, we don't
	bool bDampedOnCollision = false;
	bool bDidICollide = false;
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
	if (pos.x > maxx){
		pos.x = maxx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	} else if (pos.x < minx){
		pos.x = minx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (pos.y > maxy){
		pos.y = maxy; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	} else if (pos.y < miny){
		pos.y = miny; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	}
	
	if (bDidICollide == true && bDampedOnCollision == true){
		vel *= 0.9;
	}
	
}
