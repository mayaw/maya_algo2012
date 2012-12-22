//
//  umamiParticle.h
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#ifndef Final_umamiParticle_h
#define Final_umamiParticle_h
#include "ofMain.h"


// C style 80s :)

typedef struct{
	int			count;
	ofVec2f		sum;
	float		distance;
	float		strength;
} flockingForce;

class umamiParticle{
    
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    umamiParticle();
    virtual ~umamiParticle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addRepulsionForce(float x, float y, float radius, float scale);
    void addAttractionForce(float x, float y, float radius, float scale);
    
    void addRepulsionForce(umamiParticle &p, float radius, float scale);
    void addAttractionForce(umamiParticle &p, float radius, float scale);
    void addClockwiseForce(umamiParticle &p, float radius, float scale);
    void addCounterClockwiseForce(umamiParticle &p, float radius, float scale);
	
    void addDampingForce();
    
    void addForFlocking(umamiParticle &p);
    void addFlockingForce();
	
    flockingForce cohesion;
    flockingForce seperation;
    flockingForce alignment;
	
	
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
	
    void bounceOffWalls();
	
    float damping;
    
    ofImage * imgPtr;
    
    
    
protected:
private:
};



#endif
