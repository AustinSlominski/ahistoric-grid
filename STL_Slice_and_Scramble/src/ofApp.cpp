#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    model.loadModel("statue_head.obj",true);
    model.calculateDimensions();
    model.optimizeScene();
    gridCentroid = model.getSceneCenter()*model.getNormalizedScale();
    model.setPosition(gridCentroid.x,gridCentroid.y,gridCentroid.z);
    
    gridMin = model.getSceneMin(true)*model.getNormalizedScale();
    gridMax = model.getSceneMax(true)*model.getNormalizedScale();
    
    gridDim = (gridMax-gridMin)/2;
    
    mBox.push_back(ofPoint(gridDim.x,gridDim.y,-gridDim.z));
    mBox.push_back(ofPoint(gridDim.x,gridDim.y,gridDim.z));
    mBox.push_back(ofPoint(-gridDim.x,gridDim.y,gridDim.z));
    mBox.push_back(ofPoint(-gridDim.x,gridDim.y,-gridDim.z));
    mBox.push_back(ofPoint(gridDim.x,-gridDim.y,-gridDim.z));//problem at gridMin
    mBox.push_back(ofPoint(gridDim.x,-gridDim.y,gridDim.z));
    mBox.push_back(ofPoint(-gridDim.x,-gridDim.y,gridDim.z));
    mBox.push_back(ofPoint(-gridDim.x,-gridDim.y,-gridDim.z));
    
    grid.setupIndicesAuto();
    grid.addVertices(mBox);
    grid.setMode(OF_PRIMITIVE_LINE_STRIP);
    
    //euler lines
    euler.addVertex(ofPoint(-300,0,0));
    euler.addVertex(ofPoint(300,0,0));
    euler.addVertex(ofPoint(0,-300,0));
    euler.addVertex(ofPoint(0,300,0));
    euler.addVertex(ofPoint(0,0,-300));
    euler.addVertex(ofPoint(0,0,300));
    
    euler.setMode(OF_PRIMITIVE_LINES);
    
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
    
    cam.begin();
        ofSetColor(ofColor(200,200,200));
        euler.draw();
        ofSetColor(ofColor(100,200,240));
        grid.drawFaces();
        ofSetColor(100);
        model.drawWireframe();
    cam.end();
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
