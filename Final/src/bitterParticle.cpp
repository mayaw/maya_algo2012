//
//  bitterParticle.cpp
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#include "bitterParticle.h"
#include "ofMain.h"


//------------------------------------------------------------
bitterParticle::bitterParticle(){
	setInitialCondition(0,0,0,0);
	damping = 0.08f;
}

//------------------------------------------------------------
void bitterParticle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void bitterParticle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void bitterParticle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity
	// damping is a force operating in the oposite direction of the
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void bitterParticle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void bitterParticle::update(){
	vel = vel + frc;
	pos = pos + vel;
    
   trail.addVertex(pos);
    if (trail.size() > 140) trail.getVertices().erase(trail.getVertices().begin());
}

//------------------------------------------------------------
void bitterParticle::draw(){
    
    ofSetColor(200, 26, 0);
    //ofEllipse(pos.x, pos.y, 20, 40);
    trail.draw();
    
                      
    
}


//------------------------------------------------------------
void bitterParticle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit
	bool bDampedOnCollision = true;
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
		vel *= 0.3;
	}
	
}
