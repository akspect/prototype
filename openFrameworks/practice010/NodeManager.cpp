//
//  NodeManager.cpp
//  practice010
//
//  Created by SerinaAkashi on 2018/05/08.
//

#include "NodeManager.hpp"


NodeManager::NodeManager(){
    
}

void NodeManager::setup(float x, float y, float speedX, float speedY){
    
    if(speedX == 0){
        speedX = 0.1;
    }
    
    if(speedY == 0){
        speedY = 0.1;
    }
    
    _x = x;
    _y = y;
    _speedX = speedX;
    _speedY = speedY;
    
}

void NodeManager::update(){
    _x += _speedX;
    _y += _speedY;
    
    if( _x < 0 || _x > ofGetWidth() ){
        _speedX = _speedX * (-1);
    }
    
    if( _y < 0 || _y > ofGetHeight() ){
        _speedY = _speedY* (-1);
        
    }
}

void NodeManager::drawEllipse(float x, float y, float radius){
    ofDrawEllipse(_x, _y, radius, radius);
    ofDrawEllipse(x, y, radius, radius);
}

void NodeManager::drawLine(float x, float y){
    ofDrawLine(_x, _y, x, y);
}
