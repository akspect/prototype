//
//  LineManager.hpp
//  practice009
//
//  Created by SerinaAkashi on 2018/05/01.
//

#include "ofMain.h"
#include "PointData.cpp"

class LineManager : public ofBaseApp{
    
public:
    
    LineManager();
    void update();
    void draw();
    
    vector<PointData> points;
    float _x,_y;
    
};


