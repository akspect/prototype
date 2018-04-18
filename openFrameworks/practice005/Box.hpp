//
//  Box.hpp
//  practice005
//
//  Created by SerinaAkashi on 2018/03/20.
//

//#ifndef Box_hpp
//#define Box_hpp

#include <stdio.h>
#include "ofMain.h"


class Box : public ofBaseApp{
    
public:
    
    Box(int _time);
    void setup(float _x, float _y, float _z, float _size);
    void update();
    void draw();
    void setColor(ofColor _color);
    void progress();
    
   ofBoxPrimitive box;
    float x, y, z;
    float rotate;
    float degree;
    float scale;
    int time;
    bool isRotate, isColor;
    
};
