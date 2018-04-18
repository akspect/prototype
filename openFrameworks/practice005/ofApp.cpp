#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(1280, 720);
    verticalNum = 6;
    horizontalNum = 10;
    
    distance = 100;
    objSize = 30;
    
    ofBackground(0);

    for (int k = 0; k< verticalNum; k++){

        for (int i = 0; i< horizontalNum; i++){
            
            posX.push_back(i*distance);
            posY.push_back(k*distance);
            posZ.push_back(0);
            
            boxes.push_back(Box(10 * posZ.size()));
            
        }
    }
    
    for (int j = 0; j< boxes.size(); j++){
        boxes[j].setup(posX[j], posY[j], posZ[j], objSize);
    }
    cam.setPosition(ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 550));
    cam.lookAt(ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0));



}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i< boxes.size(); i++){
        
        boxes[i].update();
    }
    
    
//    for (int k = 0; k< horizontalNum; k++ ){
//        for (int i = 0; i< verticalNum; i++){
//         boxes[i + horizontalNum*k ].progress();
//        }
//    }

    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofSetColor(0,0,0,40);//透明度のある、黒っぽい長方形を描画
//    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);//重なりあった色の暗い部分を強調する
//    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
//
//    ofEnableBlendMode(OF_BLENDMODE_ADD);//色を重ねるほど明るくなる
    
    ofPushMatrix();
    cam.begin();

    float distWidth = ofGetWidth() - (horizontalNum-1)*(distance);
    float distHeight = ofGetHeight() - (verticalNum-1)*(distance);
    ofTranslate(distWidth/2, distHeight/2);
    
   for (int i = 0; i< boxes.size(); i++){
       boxes[i].draw();
    }


    cam.end();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
