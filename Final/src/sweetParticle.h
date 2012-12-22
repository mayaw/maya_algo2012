//
//  sweetParticle.h
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#ifndef Final_sweetParticle_h
#define Final_sweetParticle_h

#include "ofMain.h"

class sweetParticle
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    sweetParticle();
    virtual ~sweetParticle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
	
    void bounceOffWalls();
	
	
    float damping;
    
    ofImage * candy;
    
protected:
private:
};


#endif
