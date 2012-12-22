//
//  bitterScene.h
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#ifndef Final_bitterScene_h
#define Final_bitterScene_h

#include "ofMain.h"
#include "bitterParticle.h"
#include "bitterVF.h"
#include "baseScene.h"

class bitterTestApp : public baseScene {
	
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
    vector <bitterParticle> particles;
    vectorField VF;
	
    int drawingStyle;
    bool bFade;
    
    bool bSavePdf;
    
	
};


#endif
