//
//  Sphere.hpp
//  practice006
//
//  Created by SerinaAkashi on 2018/04/04.
//


#include <stdio.h>
#include <ofMain.h>


class Sphere:ofBaseApp{
    
public:
    Sphere();
    void setup(float radius, float center, int num, ofColor color);
    void update();
    void draw();
    
private:

    ofMesh mesh;
    int w,h;
    
    float _radius, _center, _num;
    float addDegree0,addDegree1;
    float seed, goalPosition, position;
    float substruct;
    
    
    
};
