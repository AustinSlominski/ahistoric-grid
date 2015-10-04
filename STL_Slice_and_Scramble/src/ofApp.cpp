#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    model.loadModel("stalin.stl",true);
    model.calculateDimensions();
    //model.setPosition(ofGetWidth()/2,ofGetHeight()/2,0);
    mMesh = model.getMesh(0);
    
    
    //Generate Bounding Box
    ofVec3f gridCenter = model.getSceneCenter();
    ofVec3f gridMin = (model.getSceneMin(true)*model.getNormalizedScale())+gridCenter;
    ofVec3f gridMax = (model.getSceneMax(true)*model.getNormalizedScale())+gridCenter;
    
    ofPoint g1 = ofPoint(gridMin.x,0,0);
    ofPoint g2 = ofPoint(gridMax.x,0,0);
    ofPoint g3 = ofPoint(0,-gridMin.y,0);
    ofPoint g4 = ofPoint(0,-gridMax.y,0);
    ofPoint g5 = ofPoint(0,0,gridMin.z);
    ofPoint g6 = ofPoint(0,0,gridMax.z);
    
    grid.addVertex(gridCenter);
    grid.addVertex(g1);
    grid.addVertex(g2);
    grid.addVertex(g3);
    grid.addVertex(g4);
    grid.addVertex(g5);
    grid.addVertex(g6);
    
    grid.setMode(OF_PRIMITIVE_POINTS);
    
    modMesh = model.getMesh(0);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(15);
}

//--------------------------------------------------------------
void ofApp::update(){
    model.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);//sets blendmode for drawing
    
    //Model lighting and shading
        //glShadeModel(GL_SMOOTH);
        //light.enable();
        //ofEnableSeparateSpecularLight();
    
    //Model and mesh drawing
    ofSetColor(ofColor(100,200,240));
    
    cam.begin();
        grid.draw();
        ofSetColor(100);
        model.drawWireframe();
    cam.end();
    ofxAssimpMeshHelper & meshHelper = model.getMeshHelper(0); //seems to provide more information about loaded model

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
