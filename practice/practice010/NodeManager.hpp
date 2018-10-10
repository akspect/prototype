//
//  NodeManager.hpp
//  practice010
//
//  Created by SerinaAkashi on 2018/05/08.
//

#pragma once
#include "ofMain.h"


class NodeManager : public ofBaseApp{
    
public:
    
    NodeManager();
    void setup(float x, float y, float speedX, float speedY);
    void update();
    void drawEllipse(float x, float y, float radius);
    void drawLine(float x, float y);
    
    float _x,_y;
    float _speedX, _speedY;
    
};
