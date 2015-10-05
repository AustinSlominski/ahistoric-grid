#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    model.loadModel("stalin.stl",true);
    model.calculateDimensions();
    //model.setPosition(ofGetWidth()/2,ofGetHeight()/2,0);
    mMesh = model.getMesh(0);
    grid.setupIndicesAuto();
    
    
    //Generate Bounding Box
    ofVec3f gridCenter = model.getSceneCenter();
    ofVec3f gridMin = (model.getSceneMin(true)*model.getNormalizedScale())+gridCenter;
    ofVec3f gridMax = (model.getSceneMax(true)*model.getNormalizedScale())+gridCenter;
    
    ofPoint g1 = ofPoint(gridMax.x,-gridMax.y,gridMin.z);
    ofPoint g2 = ofPoint(gridMax.x,-gridMax.y,gridMax.z);
    ofPoint g3 = ofPoint(gridMin.x,-gridMax.y,gridMax.z);
    ofPoint g4 = ofPoint(gridMin.x,-gridMax.y,gridMin.z);
    ofPoint g5 = ofPoint(gridMax.x,-gridMin.y,gridMin.z);
    ofPoint g6 = ofPoint(gridMax.x,-gridMin.y,gridMax.z);
    ofPoint g7 = ofPoint(gridMin.x,-gridMin.y,gridMax.z);
    ofPoint g8 = ofPoint(gridMin.x,-gridMin.y,gridMin.z);
    
    grid.addVertex(gridCenter);
    grid.addVertex(g1);
    grid.addVertex(g2);
    grid.addVertex(g3);
    grid.addVertex(g4);
    grid.addVertex(g5);
    grid.addVertex(g6);
    grid.addVertex(g7);
    grid.addVertex(g8);
    
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
