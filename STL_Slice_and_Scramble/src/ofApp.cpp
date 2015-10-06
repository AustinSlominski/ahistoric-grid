#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    model.loadModel("statue_head.obj",true);
    model.calculateDimensions();
    model.optimizeScene();
    model.setPosition(0,0,0);
    mMesh = model.getMesh(0);
    grid.setupIndicesAuto();
    
    //ofVec3f gridCenter = model.getSceneCenter(); //IS actually center
    
    ofVec3f gridMin    = model.getSceneMin()*model.getNormalizedScale();
    ofVec3f gridMax    = model.getSceneMax()*model.getNormalizedScale();
    //ofVec3f gridCenter = (gridMax+gridMin))/2;
    
    mBox.push_back(ofPoint(gridMax.x,gridMax.y-gridCenter.y,gridMin.z));
    mBox.push_back(ofPoint(gridMax.x,gridMax.y-gridCenter.y,gridMax.z));
    mBox.push_back(ofPoint(gridMin.x,gridMax.y-gridCenter.y,gridMax.z));
    mBox.push_back(ofPoint(gridMin.x,gridMax.y-gridCenter.y,gridMin.z));
    mBox.push_back(ofPoint(gridMax.x,gridMin.y,gridMin.z));//problem at gridMin
    mBox.push_back(ofPoint(gridMax.x,gridMin.y,gridMax.z));
    mBox.push_back(ofPoint(gridMin.x,gridMin.y,gridMax.z));
    mBox.push_back(ofPoint(gridMin.x,gridMin.y,gridMin.z));
    
    grid.addVertex(gridCenter );
    grid.addVertices(mBox);
    grid.setMode(OF_PRIMITIVE_POINTS);
    
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
        grid.drawWireframe();
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
