//
//  sweetScene.h
//  Final
//
//  Created by Maya Weinstein on 12/18/12.
//
//

#ifndef Final_sweetScene_h
#define Final_sweetScene_h

#include "ofMain.h"
#include "baseScene.h"
#include "sweetParticle.h"

class sweetTestApp : public baseScene{
	
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
    
    float spirRadius;
    
    // let's make a vector of them
    vector <sweetParticle> particles;
    vector < ofPoint > points;
    vector <ofPoint> spirPoints;
    
    ofImage gummyImage;
    ofImage star;
    ofImage sun;
    ofImage blur;
    ofImage spiral;
    ofImage explosion;
    ofImage candyImage;
    
    
    
};



#endif
