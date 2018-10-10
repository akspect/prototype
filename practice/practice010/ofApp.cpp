#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(1280, 720);    
    
    //頂点を結ぶ最大距離
    diameter = 70;
    
    //円の数
    num = 300;
    
    for(int i=0; i<num; i++){
        nodesVector.push_back(NodeManager());
        nodesVector[i].setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-1, 1), ofRandom(-1, 1));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i<nodesVector.size(); i++){
        
        nodesVector[i].update();
        
    }

}


//--------------------------------------------------------------

//二点の距離が指定した距離よりも遠いか近いかをチェックする
bool ofApp::overlap(NodeManager node1, NodeManager node2){
    
    float distance = ofDist(node1._x, node1._y, node2._x, node2._y);
    
    if(distance < diameter){
        return true;
    }else{
        return false;
    }
}



//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    //ひとつのnodesVectorのxyと全てのnodesVectorのxyを比較
    for(int k=0; k<nodesVector.size(); k++){
    
        //+1することで、比較に重複をなくす
        for(int i = k+1; i<nodesVector.size(); i++){
            
            if(overlap(nodesVector[i], nodesVector[k])){
                
                //二点間の距離が近ければ、円と線を描画する
                ofSetColor(255,80);
                nodesVector[i].drawLine(nodesVector[k]._x, nodesVector[k]._y);
                
                ofSetColor(255);
                nodesVector[i].drawEllipse(nodesVector[k]._x, nodesVector[k]._y, 3);

            }
        }
    }
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    

        ofImage img;
        
img.save("myPic.jpg",OF_IMAGE_QUALITY_LOW);

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
