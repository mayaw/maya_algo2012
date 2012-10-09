//
//  particle.h
//  fireworks
//
//  Created by Maya Weinstein on 10/5/12.
//
//

#ifndef fireworks_particle_h
#define fireworks_particle_h

#include "ofMain.h"


class particle {
    
public:
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    particle();
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce(float dx, float dy);
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    float damping;

protected:
private:


};







#endif
