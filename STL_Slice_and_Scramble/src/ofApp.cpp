#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    model.loadModel("stalin.stl",true);
    model.calculateDimensions();
    
    model.setPosition(ofGetWidth()/2,ofGetHeight()/2,0);
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
    
    //create mesh based on a variable grid width.
    //model.width / gridWidth
    
        //grid.addVertex(ofPoint());
    
    //Model lighting and shading
        glShadeModel(GL_SMOOTH);
        light.enable();
        ofEnableSeparateSpecularLight();
    
    //Model and mesh drawing
    grid.draw();
    model.drawWireframe();
    
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
