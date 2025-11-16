#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(18, 18, 20);
	ofSetFrameRate(60);

	// inicializar paleta (arreglo)
	palette[0] = ofColor::fromHex(0xff6b6b); // rojo pastel
	palette[1] = ofColor::fromHex(0xffb86b); // naranja
	palette[2] = ofColor::fromHex(0xfff56b); // amarillo
	palette[3] = ofColor::fromHex(0x6bffb8); // verde menta
	palette[4] = ofColor::fromHex(0x6bb8ff); // azul
	palette[5] = ofColor::fromHex(0xd46bff); // violeta

	spawning = true;
	spawnTimer = 0.0f;

}

//--------------------------------------------------------------
void ofApp::update() {
	float dt = ofGetLastFrameTime();
	if (slowMotion) dt *= 0.25f;

	// spawn automático de partículas desde el top (usa lista enlazada)
	if (spawning) {
		spawnTimer += dt;
		while (spawnTimer >= spawnInterval) {
			spawnTimer -= spawnInterval;
			float x = ofRandomWidth();
			float y = -10.0f;
			ofVec2f vel(ofRandom(-0.4f, 0.4f), ofRandom(1.0f, 2.5f));
			ofColor c = pickPaletteColor();
			particles.pushBack(x, y, c, vel);
		}
	}

	// actualizar partículas y pila
	particles.update(ofGetWidth(), ofGetHeight());
	bursts.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackgroundGradient(ofColor(12, 12, 16), ofColor(30, 30, 35), OF_GRADIENT_LINEAR);

	// dibujar partículas (lista enlazada)
	particles.display();

	// dibujar bursts (pila)
	bursts.display();

	// UI overlay
	ofSetColor(230);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'a' || key == 'A') {
		spawning = !spawning;
	} else if (key == 's' || key == 'S') {
		// flood spawn: generar muchas partículas en un instante
		for (int i = 0; i < 120; i++) {
			float x = ofRandomWidth();
			float y = ofRandomHeight() * -0.5f; // arriba
			ofVec2f vel(ofRandom(-1.0f, 1.0f), ofRandom(2.0f, 4.0f));
			ofColor c = pickPaletteColor();
			particles.pushBack(x, y, c, vel);
		}
	} else if (key == 'c' || key == 'C') {
		// limpiar todo (gestión de memoria)
		particles.clear();
		bursts.clear();
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	// al click se crea un burst (pila) y además generamos una pequeña ráfaga de partículas
	ofColor c = pickPaletteColor();
	bursts.push(x, y, c);

	// small local spray using dynamic allocation -> pushed to particle list
	for (int i = 0; i < 30; i++) {
		float px = x + ofRandom(-20, 20);
		float py = y + ofRandom(-20, 20);
		ofVec2f vel(ofRandom(-2.5f, 2.5f), ofRandom(-3.5f, 1.5f));
		particles.pushBack(px, py, c, vel);
	}
}

//--------------------------------------------------------------
void ofApp::exit() {
	// Asegurar liberación antes de salir
	particles.clear();
	bursts.clear();
}

//--------------------------------------------------------------
ofColor ofApp::pickPaletteColor() {
	int idx = (int)ofRandom(PAL_SIZE);
	return palette[idx];
}
