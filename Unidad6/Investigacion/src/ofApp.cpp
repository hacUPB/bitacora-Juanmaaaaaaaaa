#include "ofApp.h"
#include <algorithm> // std::remove

void Subject::addObserver(Observer * observer) {
	observers.push_back(observer);
}

void Subject::removeObserver(Observer * observer) {
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify(const std::string & event) {
	for (Observer * observer : observers) {
		observer->onNotify(event);
	}
}

Particle::Particle() {
	position = ofVec2f(ofRandomWidth(), ofRandomHeight());
	velocity = ofVec2f(ofRandom(-0.5f, 0.5f), ofRandom(-0.5f, 0.5f));
	size = ofRandom(2, 5);
	color = ofColor(255);
	state = new NormalState();
}

Particle::~Particle() {
	delete state;
}

void Particle::setState(State * newState) {
	if (state != nullptr) {
		state->onExit(this);
		delete state;
	}
	state = newState;
	if (state != nullptr) {
		state->onEnter(this);
	}
}

void Particle::update() {
	if (state != nullptr) {
		state->update(this);
	}
	
	if (position.x < 0 || position.x > ofGetWidth()) velocity.x *= -1;
	if (position.y < 0 || position.y > ofGetHeight()) velocity.y *= -1;
}

void Particle::draw() {
	ofSetColor(color);
	ofDrawCircle(position, size);
}

void Particle::onNotify(const std::string & event) {
	
	if (event == "attract") {
		setState(new AttractState());
	} else if (event == "repel") {
		setState(new RepelState());
	} else if (event == "stop") {
		setState(new StopState());
	} else if (event == "normal") {
		setState(new NormalState());
	} else if (event == "orbit") {
		setState(new OrbitState());
	}
	
	else if (event == "speedup") {
		velocity *= 1.8f;
	} else if (event == "slow") {
		velocity *= 0.4f;
	} else if (event == "glow") {
		color = ofColor(255, 255, 50, 255);
		size *= 1.4f;
	}
}


void NormalState::update(Particle * particle) {
	particle->position += particle->velocity;
}

void NormalState::onEnter(Particle * particle) {
	particle->velocity = ofVec2f(ofRandom(-0.5f, 0.5f), ofRandom(-0.5f, 0.5f));
}

void AttractState::update(Particle * particle) {
	ofVec2f mousePosition(((ofApp *)ofGetAppPtr())->mouseX, ((ofApp *)ofGetAppPtr())->mouseY);
	ofVec2f direction = mousePosition - particle->position;
	if (direction.lengthSquared() > 0.0001f) direction.normalize();
	particle->velocity += direction * 0.05f;
	particle->velocity.x = ofClamp(particle->velocity.x, -3, 3);
	particle->velocity.y = ofClamp(particle->velocity.y, -3, 3);
	particle->position += particle->velocity * 0.2f;
}

void RepelState::update(Particle * particle) {
	ofVec2f mousePosition(((ofApp *)ofGetAppPtr())->mouseX, ((ofApp *)ofGetAppPtr())->mouseY);
	ofVec2f direction = particle->position - mousePosition;
	if (direction.lengthSquared() > 0.0001f) direction.normalize();
	particle->velocity += direction * 0.05f;
	particle->velocity.x = ofClamp(particle->velocity.x, -3, 3);
	particle->velocity.y = ofClamp(particle->velocity.y, -3, 3);
	particle->position += particle->velocity * 0.2f;
}

void StopState::update(Particle * particle) {
	particle->velocity.x = 0;
	particle->velocity.y = 0;
}


void OrbitState::update(Particle * particle) {
	ofVec2f center(((ofApp *)ofGetAppPtr())->mouseX, ((ofApp *)ofGetAppPtr())->mouseY);
	ofVec2f dir = particle->position - center;
	float dist = dir.length();
	if (dist < 1.0f) dist = 1.0f;
	
	ofVec2f tangent(-dir.y, dir.x);
	if (tangent.lengthSquared() > 0.0001f) tangent.normalize();
	
	particle->velocity += tangent * 0.15f - dir * 0.001f;
	particle->velocity.x = ofClamp(particle->velocity.x, -4, 4);
	particle->velocity.y = ofClamp(particle->velocity.y, -4, 4);
	particle->position += particle->velocity * 0.8f;
}


Particle * ParticleFactory::createParticle(const std::string & type) {
	Particle * particle = new Particle();

	if (type == "star") {
		particle->size = ofRandom(2, 4);
		particle->color = ofColor(255, 0, 0);
	} else if (type == "shooting_star") {
		particle->size = ofRandom(3, 6);
		particle->color = ofColor(0, 255, 0);
		particle->velocity *= 3;
	} else if (type == "planet") {
		particle->size = ofRandom(5, 8);
		particle->color = ofColor(0, 0, 255);
	} else if (type == "comet") {
		particle->size = ofRandom(6, 10);
		particle->color = ofColor(255, 200, 80);
		particle->velocity = ofVec2f(ofRandom(-2.0f, 2.0f), ofRandom(-1.0f, 1.0f)) * 3.0f;
	} else if (type == "ghost") {
		particle->size = ofRandom(3, 6);
		particle->color = ofColor(200, 200, 255, 100); 
		particle->velocity *= 0.4f;
	}
	return particle;
}


void ofApp::setup() {
	ofBackground(0);
	
	for (int i = 0; i < 100; ++i) {
		Particle * p = ParticleFactory::createParticle("star");
		particles.push_back(p);
		addObserver(p);
	}

	for (int i = 0; i < 5; ++i) {
		Particle * p = ParticleFactory::createParticle("shooting_star");
		particles.push_back(p);
		addObserver(p);
	}

	for (int i = 0; i < 10; ++i) {
		Particle * p = ParticleFactory::createParticle("planet");
		particles.push_back(p);
		addObserver(p);
	}


	for (int i = 0; i < 3; ++i) {
		Particle * p = ParticleFactory::createParticle("comet");
		particles.push_back(p);
		addObserver(p);
	}

	for (int i = 0; i < 7; ++i) {
		Particle * p = ParticleFactory::createParticle("ghost");
		particles.push_back(p);
		addObserver(p);
	}
}

void ofApp::update() {
	for (Particle * p : particles) {
		p->update();
	}
}

void ofApp::draw() {
	for (Particle * p : particles) {
		p->draw();
	}
}

void ofApp::keyPressed(int key) {
	if (key == 's') {
		notify("stop");
	} else if (key == 'a') {
		notify("attract");
	} else if (key == 'r') {
		notify("repel");
	} else if (key == 'n') {
		notify("normal");
	} else if (key == 'o') {
		notify("orbit"); 
	} else if (key == '+') {
		notify("speedup"); 
	} else if (key == '-') {
		notify("slow"); 
	} else if (key == 'g') {
		notify("glow"); 
	}
}

ofApp::~ofApp() {
	for (Particle * p : particles) {
		removeObserver(p);
		delete p;
	}
	particles.clear();
}
