#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "spiral.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

        spiral_left mySpiral;
        spiral_right mySpiral_right;
        spiral_left_bottom mySpiral_left_bottom;
        spiral_left_top mySpiral_left_top;
        spiral_right_top mySpiral_right_top;
        spiral_right_bottom mySpiral_right_bottom;
    

            
};

#endif
