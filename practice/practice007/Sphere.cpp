#include "Sphere.hpp"


Sphere::Sphere(){
    
    
    
}

void Sphere::setup(float radius, float center, int num, ofColor color){
    
    _radius = radius;
    _center = center;
    addDegree0 = addDegree1 = 0;
    
    
    while(addDegree0 <= 360){

        addDegree0 += 5;
        mesh.addColor(ofFloatColor(1.0,1.0,1.0));
    
    }
    
    
    addDegree0 = addDegree1 = 0;
    
    substruct = 0;
        mesh.setMode(OF_PRIMITIVE_TRIANGLES_ADJACENCY);
    
}


void Sphere::update(){
    
    mesh.clearVertices();
        printf("%s%f","\n update : ", addDegree1);

    
    if(substruct > 360){
        substruct = 0;
    }
    
    substruct += 0.05;
    
 
    while(addDegree0 <= 360){
        
        addDegree1 += sin(substruct * DEG_TO_RAD)*10;
        addDegree0 += 5;

        
        float rad0 = addDegree0 * DEG_TO_RAD;
        float rad1 = addDegree1 * DEG_TO_RAD;
        
        float y = cos(rad0) * _radius + _center;
        float x = sin(rad0) * sin(rad1) *_radius + _center;
        float z = sin(rad0) * cos(rad1) *_radius + _center;
        
        ofPoint pos = ofVec3f(x,y,z);
        
        printf("%s%f%s%f","\n==================rad1: ", rad0, " rad2: ", rad1);
        printf("%s%f%s%f%s%f", "\n x: ", x, " y: ", y ," z: ", z);

        
        mesh.addVertex(pos);
        
    }
    
        addDegree0 = 0;

}


void Sphere::draw(){
    glPointSize(4.0);
    glEnable(GL_POINT_SMOOTH);
    mesh.draw();
    
}
