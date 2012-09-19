#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    
    clickTog = 1;
    
    posA.x = 100;
    posA.y = ofGetHeight()/2;
    
    posA.x = 500;
    posA.y = ofGetHeight()/2;

}

//--------------------------------------------------------------
void testApp::update(){
    
    if (mouseRel == true) {
        
        if (clickTog % 2 == 0) {
            posB.x = mouseX;
            posB.y = mouseY;
            posA_orB = false;
        } else {
            posA.x = mouseX;
            posA.y = mouseY;
            posA_orB = true;
        }
        
        mouseRel = false;
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(30, 30, 30);
    
    ofSetColor(0, 255, 255);
    ofRect(posA.x, posA.y, 25, 25);
    
    ofSetColor(255, 255, 0);
    ofRect(posB.x, posB.y, 25, 25);
    
    
    // Sending the report to see the (x,y) coordinates
    ofSetColor(255,0,255);
    stringstream report;
    report 
    << "posA.x: " << posA.x << endl
    << "posA.y: " << posA.y << endl
    << endl
    << "posB.x: " << posB.x << endl
    << "posB.y: " << posB.y << endl
    << "Mouse: " << posA_orB << endl;
    ofDrawBitmapString(report.str(), 20, 30);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    mouseRel = true;
    clickTog++;

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}