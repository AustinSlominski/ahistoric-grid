#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    //loadModel(file,bool optimize)
    model.loadModel("stalin.stl",true);
    model.setPosition(ofGetWidth()/2,ofGetHeight()/2,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    model.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofEnableDepthTest();
    
    glShadeModel(GL_SMOOTH);
    light.enable();
    ofEnableSeparateSpecularLight();
    model.drawWireframe();
    
    glEnable(GL_NORMALIZE);
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
