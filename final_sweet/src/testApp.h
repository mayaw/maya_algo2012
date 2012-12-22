#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

#include "particle.h"

class testApp : public ofSimpleApp{
	
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
		vector <particle> particles;
        vector < ofPoint > points;
        vector <ofPoint> spirPoints;
    
        ofImage gummyImage;
        ofImage star;
        ofImage sun;
        ofImage blur;
        ofImage spiral;
        ofImage explosion;
    
    
         	
};

#endif
	
