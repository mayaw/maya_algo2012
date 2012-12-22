//
//  sourParticle.h
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#ifndef Final_sourParticle_h
#define Final_sourParticle_h

#include "ofMain.h"

class sourParticle
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    sourParticle();
    virtual ~sourParticle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
	
    void addRepulsionForce( float px, float py, float radius, float strength);
    void addAttractionForce( float px, float py, float radius, float strength);
    void addClockwiseForce( float px, float py, float radius, float strength);
    void addCounterClockwiseForce( float px, float py, float radius, float strength);
	
	
    float damping;
    
protected:
private:
};


#endif
