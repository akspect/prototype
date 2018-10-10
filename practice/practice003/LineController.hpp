#pragma once
#include "ofMain.h"


class LineController : public ofBaseApp
{
    
public:
    LineController(int radian);
    ~LineController();
    
    void update();
    void draw();
    bool isDeleateflag = false;
    int stopTime;
        void setPosition();
private:
    
    vector<ofPoint> point;
    
    float _startRadius,_endRadius;
    float speed;
    float _minRadius, _maxRadius;
    int _radian;
    float x1,x2,y1,y2;
    float x,y;
    ofFbo linefbo;

    int pauseTime;

};
