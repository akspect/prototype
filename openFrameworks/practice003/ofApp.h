#pragma once

#include "ofMain.h"
#include "LineController.hpp"


class ofApp : public ofBaseApp
{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
private:
    int time,posTime;
    bool isFitstTime;
    int radian0,radian1;
    vector<int> timesVector;
    vector<LineController> lineControllerVector0;
    vector<LineController> lineControllerVector1;
    
};
