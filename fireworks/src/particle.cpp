//
//  particle.cpp
//  fireworks
//
//  Created by Maya Weinstein on 10/5/12.
//
//

#include "particle.h"
#include "ofMain.h"

//-----------------------------------------------------------
particle::particle(){
    
    //called when object is created
    
    setInitialCondition(0, 0, 0, 0);
    damping = 0.01f;
}
//-------------------------------------------------------------
void particle::resetForce(){
    
    //clears all the forces, every frame
    
    frc.set(0,0);
}
//--------------------------------------------------------------
void particle::addForce(float x, float y){
    
    //adds a force
    //force = mass * acceleration
    
    //float angle = ofGetElapsedTimef() * ofRandom(5);
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}
//-------------------------------------------------------------
void particle::addDampingForce(){

    //adds a force in the opposite direction the particle is moving
    //damping is the force in the particles direction
    
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
    
}
//-----------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    
    //starting point, direction the particle is moving
    //velocity = velocity + acceleration
    //position = position + velocity
    
    pos.set(px, py);
    vel.set(vx, vy);
    
}
//-------------------------------------------------------------------
void particle::update(){
	vel = vel + frc;
	pos = pos + vel;
}
//------------------------------------------------------------
void particle::draw(){
    
    ofCircle(pos.x, pos.y, 3);
}

