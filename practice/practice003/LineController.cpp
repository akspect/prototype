//
//  LineController.cpp
//  example
//
//  Created by SerinaAkashi on 2018/02/22.
//

#include "LineController.hpp"

LineController::LineController(int radian){
    
    _radian = radian;
    speed = 8;
    pauseTime = 0;
    stopTime = 0;
    
    _endRadius = 100;
    _startRadius = _endRadius;
    _maxRadius = 600;
}

LineController::~LineController(){
    
    
}

void LineController::update(){
    //_radian += 40;
    
}
void LineController::draw(){
    
    ofSetLineWidth(10);
    
    
    if( _startRadius == _endRadius &&  pauseTime != 0){
        //線の動きが一旦終了したら
        stopTime ++;
        
        if(stopTime >= 10){
            
            stopTime = 0;
            pauseTime = 0;
            isDeleateflag = true;
        }
        
        
    }else if(_startRadius > _maxRadius){
        
        //線が消えていく場合
        
        if(pauseTime >= 40){
            
            //停止する時間が終わったら処理を開始する
            _endRadius += speed;
            
        }else{
            
            //一旦停止
            pauseTime++;
        }
        
        
    }else{
        
        //線がひかれていく
        _startRadius += speed;
        
    }
    
    
    x1= _startRadius*sin(ofDegToRad(_radian));
    y1= _startRadius*cos(ofDegToRad(_radian));
    
    x2= _endRadius*sin(ofDegToRad(_radian));
    y2= _endRadius*cos(ofDegToRad(_radian));
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    
    ofDrawLine(x1,y1,x2,y2);
    ofPopMatrix();
    
    
}

