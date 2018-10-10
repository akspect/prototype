//
//  LineManager.cpp
//  practice009
//
//  Created by SerinaAkashi on 2018/05/01.
//

#include "LineManager.hpp"


LineManager::LineManager(){
    
    _x = ofRandom(ofGetWidth());
    _y = ofRandom(ofGetHeight());
    
    ofSetLineWidth(1.5);
    
}

void LineManager::update(){
    
    //現在地、_xと_yに加えたいもの
    float addX = cos(ofRandom(360) * DEG_TO_RAD) * ofRandom(50);
    float addY = sin(ofRandom(360) * DEG_TO_RAD) * ofRandom(50);
    
    //最終地点の座標を設定
    float directionX = _x + addX;
    float directionY = _y + addY;
    
    
    if(directionX > 0 && directionX < ofGetWidth()&& directionY > 0 && directionY < ofGetHeight()){
        
        //画面内に頂点座標が収まっている場合
        //頂点座標を保存
        points.push_back(PointData());
        points[points.size()-1].x = directionX;
        points[points.size()-1].y = directionY;
        
        _x = directionX;
        _y = directionY;
        
        
    }
    
    for(int i=0; i<points.size(); i++){
        points[i].x += ofRandom(ofNoise(5));
        points[i].y += ofRandom(ofNoise(5));
        
    }
    
    
}

void LineManager::draw(){
    
    for(int i=1; i<points.size(); i++){
        
        ofDrawLine(points[i-1].x, points[i-1].y, points[i].x, points[i].y);
        
    }
}
