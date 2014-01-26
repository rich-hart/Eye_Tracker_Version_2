#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	camWidth = 320; //640
	camHeight = 280;//480
	
    
    brightness =0.4;
	ps3eye.listDevices();
	
	ps3eye.setDesiredFrameRate(60);
	ps3eye.initGrabber(camWidth,camHeight);
	
	ps3eye.setAutoGainAndShutter(false); // otherwise we can't set gain or shutter
	ps3eye.setGain(1.0);
	ps3eye.setShutter(1.0);
	ps3eye.setGamma(0.4);
	ps3eye.setBrightness(brightness);
	ps3eye.setContrast(1.0);
	ps3eye.setHue(0.5);
	
	ps3eye.setFlicker(1);
}


//--------------------------------------------------------------
void testApp::update(){
	
	ps3eye.update();
	
	// Blink the led everytime there is a new frame
	if(ps3eye.isFrameNew()){
		ps3eye.setLed(true); 
	}
	else ps3eye.setLed(false); 

}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0xffffff);
	ps3eye.draw(20,20);
	
	ofDrawBitmapString("Ps3Eye FPS: "+ ofToString(ps3eye.getRealFrameRate()), 20,15);
}



//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 	
    if(key == '-' && brightness>0){
        brightness = brightness - .1;
        ps3eye.setBrightness(brightness);

    }
	
    
    if(key == '=' && brightness<1.0){
        brightness = brightness + .1;
        ps3eye.setBrightness(brightness);
        
    }
		
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

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
