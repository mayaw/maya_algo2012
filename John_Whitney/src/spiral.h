//
//  spiral.h
//  5_sinExample_multiCircles
//
//  Created by Maya Weinstein on 9/26/12.
//
//

#ifndef __sinExample_multiCircles_spiral_h
#define __sinExample_multiCircles_spiral_h

#include "ofMain.h"

class spiral_left {
    
public:
    
    spiral_left();
    void draw();
    float   xorig;
    float   yorig;

};

class spiral_right {
public:
    spiral_right();
    void draw();
    float xorig;
    float yorig;
    
    
};

class spiral_left_bottom {
public:
    spiral_left_bottom();
    void draw();
    float xorig;
    float yorig;

};

class spiral_left_top {
public:
    spiral_left_top();
    void draw();
    float xorig;
    float yorig();
    
};

class spiral_right_top{
public:
    spiral_right_top();
    void draw();
    float xorig();
    float yorig();
    
};

class spiral_right_bottom {
public:
    spiral_right_bottom();
    void draw();
    float xorig();
    float yorig();
    
};







#endif
