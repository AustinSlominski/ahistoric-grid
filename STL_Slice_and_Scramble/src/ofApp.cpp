#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    model.loadModel("statue_head.obj",true);
    model.calculateDimensions();
    model.optimizeScene();
    mCentroid = model.getSceneCenter()*model.getNormalizedScale();
    model.setPosition(mCentroid.x,mCentroid.y,mCentroid.z);
    
    mMin = model.getSceneMin(true)*model.getNormalizedScale();
    mMax = model.getSceneMax(true)*model.getNormalizedScale();
    mDim = mMax-mMin;
    
    /*
    mBox.addVertex(ofPoint(mDim.x,mDim.y,-mDim.z));
    mBox.addVertex(ofPoint(mDim.x,mDim.y,mDim.z));
    mBox.addVertex(ofPoint(-mDim.x,mDim.y,mDim.z));
    mBox.addVertex(ofPoint(-mDim.x,mDim.y,-mDim.z));
    mBox.addVertex(ofPoint(mDim.x,-mDim.y,-mDim.z));
    mBox.addVertex(ofPoint(mDim.x,-mDim.y,mDim.z));
    mBox.addVertex(ofPoint(-mDim.x,-mDim.y,mDim.z));
    mBox.addVertex(ofPoint(-mDim.x,-mDim.y,-mDim.z));
    */
     
    gridUnit = 6;
    gridDivision = mDim/gridUnit;
    
    for(int i=0;i<gridUnit;i++){
        
    }
    
    mBox.setupIndicesAuto();
    grid.setupIndicesAuto();
    mBox.setMode(OF_PRIMITIVE_LINE_STRIP);
    grid.setMode(OF_PRIMITIVE_POINTS);
    //euler lines
    /*
    euler.addVertex(ofPoint(-300,0,0));
    euler.addVertex(ofPoint(300,0,0));
    euler.addVertex(ofPoint(0,-300,0));
    euler.addVertex(ofPoint(0,300,0));
    euler.addVertex(ofPoint(0,0,-300));
    euler.addVertex(ofPoint(0,0,300));
    
    euler.setMode(OF_PRIMITIVE_LINES);
    */
    
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
        //euler.draw();
        grid.draw();
        ofSetColor(ofColor(100,200,240));
        mBox.draw();
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
