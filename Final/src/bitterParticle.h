//
//  bitterParticle.h
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#ifndef Final_bitterParticle_h
#define Final_bitterParticle_h

#include "ofMain.h"

class bitterParticle
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    bitterParticle();
    virtual ~bitterParticle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
	
    void bounceOffWalls();
    
    ofPolyline trail;
	
    float damping;
    
protected:
private:
};

#endif
