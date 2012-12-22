//
//  saltyParticle.h
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#ifndef Final_saltyParticle_h
#define Final_saltyParticle_h

#include "ofMain.h"

class saltyParticle
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    saltyParticle();
    virtual ~saltyParticle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
	
    void bounceOffWalls();
	
	
    float damping;
    
    ofImage * img;
    
protected:
private:
};



#endif
