#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	setupGui();
}

void ofApp::setupGui() {

	bFullScreen.addListener(this, &ofApp::fullScreenToggleChanged);

	gui.setup();
	gui.add(bFullScreen.setup("Full Screen", false));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::white, ofColor::gray);
	if (!guiHide) { gui.draw(); }
}

void ofApp::fullScreenToggleChanged(bool &toggle) {
	ofSetFullscreen(toggle);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	ofToggleFullscreen();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	//screenSize = ofToString(w) + "x" + ofToString(h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
