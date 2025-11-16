#include "ofApp.h"

// ---------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(10);
	spawning = true;
	spawnTimer = 0.0f;
	ofLogNotice() << "S: toggle spawn | C: clear | R: remove last (push undo) | U: undo | Click left: Fast | Right: Slow";
}

// ---------------------------------------------------------
void ofApp::update() {
	float dt = ofGetLastFrameTime(); // segundos

	// spawn automático
	if (spawning) {
		spawnTimer += dt;
		while (spawnTimer >= spawnInterval) {
			spawnTimer -= spawnInterval;
			spawnRandom();
		}
	}

	// actualizar partículas (recorremos hacia atrás para poder borrar)
	for (int i = (int)particles.size() - 1; i >= 0; --i) {
		Particle * p = particles[i];
		p->update(dt);

		// condición de borrado: fuera de pantalla o muerta
		bool off = (p->getPosition().x < -50 || p->getPosition().x > ofGetWidth() + 50 || p->getPosition().y < -50 || p->getPosition().y > ofGetHeight() + 50);
		if (p->isDead() || off) {
			delete p;
			particles.erase(particles.begin() + i);
		}
	}
}

// ---------------------------------------------------------
void ofApp::draw() {
	ofBackgroundGradient(ofColor(8, 8, 12), ofColor(25, 25, 35));

	// dibujar todas (polimorfismo)
	for (Particle * p : particles) {
		p->draw();
	}

	// UI simple
	ofSetColor(230);
	ofDrawBitmapString("S: toggle spawn | R: remove last (push undo) | U: undo | C: clear all", 10, 18);
	ofDrawBitmapString("Click left: FastParticle | Click right: SlowParticle", 10, 34);
	ofDrawBitmapString("Particles: " + ofToString(particles.size()) + " | UndoStack: " + ofToString(undoStack.size()), 10, 50);
}

// ---------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 's' || key == 'S') {
		spawning = !spawning;
	} else if (key == 'r' || key == 'R') {
		// remove last particle and push pointer to undoStack (no delete here)
		if (!particles.empty()) {
			Particle * p = particles.back();
			particles.pop_back();
			undoStack.push(p);
		}
	} else if (key == 'u' || key == 'U') {
		// undo: pop from stack and reinsert
		if (!undoStack.empty()) {
			Particle * p = undoStack.pop();
			particles.push_back(p);
		}
	} else if (key == 'c' || key == 'C') {
		clearAll();
	}
}

// ---------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	ofVec2f pos((float)x, (float)y);
	ofColor c = pickColor();
	if (button == OF_MOUSE_BUTTON_LEFT) {
		// Fast
		Particle * p = new FastParticle(pos, c);
		particles.push_back(p);
	} else if (button == OF_MOUSE_BUTTON_RIGHT) {
		// Slow
		Particle * p = new SlowParticle(pos, c);
		particles.push_back(p);
	}
}

// ---------------------------------------------------------
ofColor ofApp::pickColor() const {
	// simple palette via HSB
	float h = ofRandom(0, 255);
	return ofColor::fromHsb((int)h, 200, 230);
}

// spawn utility
void ofApp::spawnRandom() {
	ofVec2f pos(ofRandomWidth(), -10.0f);
	ofColor c = pickColor();
	// randomly choose type
	if (ofRandom(1.0f) < 0.5f) {
		particles.push_back(new FastParticle(pos, c));
	} else {
		particles.push_back(new SlowParticle(pos, c));
	}
}

// clear and free memory
void ofApp::clearAll() {
	// delete particles
	for (Particle * p : particles)
		delete p;
	particles.clear();

	// any pointers in undoStack must also be deleted because app owns them
	while (!undoStack.empty()) {
		Particle * p = undoStack.pop();
		delete p;
	}
}

// ensure cleanup on exit
void ofApp::exit() {
	clearAll();
}
