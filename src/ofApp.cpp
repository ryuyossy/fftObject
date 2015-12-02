#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowPosition( 2881, 0 );
    ofSetWindowShape(1920,1080);
    ofToggleFullscreen();
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    // FFTのサンプル数(2の累乗)を指定して初期化
    fft.setup(pow(2.0, 12.0));
    //light
    
    light.enable();
    light.setSpotlight();
    light.setPosition(0, 0, 0);
    light.setAmbientColor(ofFloatColor(0.1,0.1,0.1,1.0));
    light.setDiffuseColor(ofFloatColor(0.3,0.3,0.3));
    light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
    
    fade = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    fft.update(); // FFT更新
    
    if (fade < 1) {
        fade += 0.0001;
    }
    
    buffer = fft.getBins();
    
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < buffer.size()/10; i++) {
            // 右
            float rx = ofGetWindowWidth() * buffer[i];
            
            mesh.addVertex(ofVec3f(rx, rx, 1000*sin(i)));
            mesh.addColor(ofFloatColor(0.01,0.3,0.3,fade));
            mesh.addIndex(i);
            
            mesh.addVertex(ofVec3f(rx, rx, 1000*sin(i)));
            mesh.addColor(ofFloatColor(0.2,0,0.2,fade));
            mesh.addIndex(i+1);
            
            mesh.addVertex(ofVec3f(rx, ofGetHeight(), 1000*sin(i)));
            mesh.addColor(ofFloatColor(0.1,0,0.5,fade));
            mesh.addIndex(i+2);
        
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // float型の配列にFFT結果を格納
    buffer = fft.getBins();

    // グラフに描画
    ofPushMatrix();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    //ofSetLineWidth(ofGetWidth() / float(buffer.size()));
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofPopMatrix();
    
    
    //GUI
    gui.draw();
    
    angle+=0.1;
    
    cam.begin();
    cam.setDistance(4000);
    ofRotateY(angle);
    ofRotateX(-angle);
    ofRotateZ(angle*10);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    mesh.draw();
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
