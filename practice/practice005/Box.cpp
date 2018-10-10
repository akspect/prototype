//
//  Box.cpp
//  practice005
//
//  Created by SerinaAkashi on 2018/03/20.
//

#include "Box.hpp"

Box::Box(int _time){
    
    box.setResolution(1);
    rotate = 5;
    scale = 0.5;
    time = _time;
    degree = 0;
    isRotate = false;
    isColor = false;
    
}

void Box::setup(float _x, float _y, float _z, float size){
    x = _x;
    y = _y;
    z = _z;
    
    box.set(size);
    box.setPosition(x, y, z);
    
}

void Box::update(){
    
    
    if(time%250 == 0 ){
        isRotate = true;
    }
    
    if (isRotate){
        
        //回転するときは拡大する
        box.rotate(rotate, 0, 1.0, 0);
        degree += rotate;
        scale += 0.05;
        isColor = true;
        
        //1回転したら回転を辞める
        if(degree >= 360){
            isRotate = false;
            degree = 0;
        }
    }else{
        
        //大きさを元に戻す
        if(scale > 0.5){
            scale -= 0.05;
            isColor = true;
        }else{
            scale = 0.5;
            isColor = false;
        }
        
    }
    
    int maxTime = 400; //4で割れる数字
    int timeDivision = time%maxTime;
    
    if(timeDivision < maxTime/4){
        x -= 0.1;
    }else if(timeDivision >= maxTime/4 &&timeDivision < maxTime/4*2){
        y -= 0.1;
    }else if(timeDivision >= maxTime/4*2 &&timeDivision < maxTime/4*3){
        x += 0.1;
    }else{
        y+=0.1;
    }

    box.setPosition(x, y, z);
    box.setScale(scale);
    time++;
}

void Box::draw(){
    
    ofColor color;
    
   if (isColor){
       
       //回転している間
       //色のついたボックスを描画
       color.setHsb(ofGetFrameNum()%255, 255, 255,30);
       setColor(color);
       box.draw();
       
       //ワイヤーフレームを描画
       color.setHsb(255, 0, 255);
       setColor(color);
       box.drawWireframe();
       

   }else{
       color.setHsb(255, 0, 255);
       setColor(color);
       box.drawWireframe();
   }
}

//色の設定をする
void Box::setColor(ofColor color){
    box.setSideColor(box.SIDE_FRONT, color);
    box.setSideColor(box.SIDE_BACK, color);
    box.setSideColor(box.SIDE_TOP, color);
    box.setSideColor(box.SIDE_BOTTOM, color);
    box.setSideColor(box.SIDE_LEFT, color);
    box.setSideColor(box.SIDE_RIGHT, color);
}

