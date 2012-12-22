//
//  sourScene.h
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#ifndef Final_sourScene_h
#define Final_sourScene_h

#include "ofMain.h"
#include "baseScene.h"
#include "sourParticle.h"

class sourTestApp : public baseScene{
	
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased (int key);
    
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased();
    
    // let's make a vector of them
    vector <sourParticle> particles;
	
	
};



#endif
