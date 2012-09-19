#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(30,30,30);
    
    // counter to toggle between positions A/B
	clickTog = 1;
	
	// set the "a" and "b" positions of the rectangle...
	
	myRectangle.posa.x = 100;
	myRectangle.posa.y = ofGetHeight()/2;
	myRectangle.posb.x = 500;
	myRectangle.posb.y = ofGetHeight()/2;
	
	
	myRectangle.radiusa = 30;
	myRectangle.radiusb = 200;
	
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter...
} 

//--------------------------------------------------------------
void testApp::update(){

	// here we change the posA posB positions whenever we have mouseRel = true
    if (mouseRel == true) {
        
        if (clickTog % 2 == 0) {            // using modulo to toggle between A/B
            myRectangle.posb.x = mouseX;    
            myRectangle.posb.y = mouseY;
            posA_orB = false;
        } else {
            myRectangle.posa.x = mouseX;
            myRectangle.posa.y = mouseY;
            posA_orB = true;
        }
        
        mouseRel = false;                   // reset the mouseRel to false
    }
	
	pct = (float) mouseY / (float) ofGetHeight();
	
	//printf("%f \n", pct);
	
	//pct = pct + 0.01;
	//	if (pct > 1){
	//		pct = 0;	
	//	}
	
	myRectangle.interpolateByPct(pct);
	
}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
	
	// Sending the report to see the (x,y) coordinates
    ofSetColor(255,0,255);
    stringstream report;
    report 
    << "posA.x: " << myRectangle.posa.x << endl
    << "posA.y: " << myRectangle.posa.y << endl
    << endl
    << "posB.x: " << myRectangle.posb.x << endl
    << "posB.y: " << myRectangle.posb.y << endl
    << "Mouse: " << posA_orB << endl;
    ofDrawBitmapString(report.str(), 20, 30);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
	// set pct based on mouseY....
	//pct = (float)  y /  (float) ofGetHeight();
//	if (pct < 0) pct = 0;
//	if (pct > 1) pct = 1;
//	myRectangle.interpolateByPct(pct);		// go between pta and ptb
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
    
    mouseRel = true;
    clickTog++;
}
