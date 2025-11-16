#pragma once
#include "ofMain.h"
#include <vector>

// ---------------------------
// Clase base Particle (encapsulamiento)
// ---------------------------
class Particle {
public:
	Particle(const ofVec2f & pos, const ofColor & c)
		: position(pos)
		, color(c)
		, life(5.0f) { }

	virtual ~Particle() { } // destructor virtual por seguridad

	// Interfaz pública (polimorfismo)
	virtual void update(float dt) = 0;
	virtual void draw() const = 0;

	// Consultas seguras
	bool isDead() const { return life <= 0.0f; }
	const ofVec2f & getPosition() const { return position; }

protected:
	ofVec2f position;
	ofVec2f velocity;
	ofColor color;
	float life; // segundos de vida (decay)

	// Helper protegido (accesible a derivadas)
	void decay(float amount) { life -= amount; }
};

// ---------------------------
// Partícula rápida: se desplaza y despinta rápido
// ---------------------------
class FastParticle : public Particle {
public:
	FastParticle(const ofVec2f & pos, const ofColor & c)
		: Particle(pos, c)
		, radius(4.0f) {
		velocity.set(ofRandom(-150, 150), ofRandom(-150, -60));
		life = ofRandom(1.0f, 2.0f);
	}
	~FastParticle() override { }

	void update(float dt) override {
		// dt en segundos
		position += velocity * dt;
		velocity.y += 300.0f * dt; // gravedad
		radius *= 0.995f;
		decay(dt * 1.0f);
	}

	void draw() const override {
		ofPushStyle();
		float a = ofMap(life, 0, 2.0f, 0, 255, true);
		ofSetColor(color, (int)a);
		ofDrawCircle(position.x, position.y, radius);
		ofPopStyle();
	}

private:
	float radius;
};

// ---------------------------
// Partícula lenta y ondulante
// ---------------------------
class SlowParticle : public Particle {
public:
	SlowParticle(const ofVec2f & pos, const ofColor & c)
		: Particle(pos, c)
		, radius(5.0f)
		, phase(ofRandom(0, TWO_PI)) {
		velocity.set(ofRandom(-20, 20), ofRandom(10, 40));
		life = ofRandom(3.0f, 6.0f);
	}
	~SlowParticle() override { }

	void update(float dt) override {
		phase += dt * 4.0f;
		position.x += sin(phase) * 20.0f * dt;
		position += velocity * dt;
		decay(dt * 0.5f);
	}

	void draw() const override {
		ofPushStyle();
		float a = ofMap(life, 0, 6.0f, 0, 255, true);
		ofSetColor(color, (int)a);
		ofDrawCircle(position.x, position.y, radius + sin(phase) * 1.5f);
		ofPopStyle();
	}

private:
	float radius;
	float phase;
};

// ---------------------------
// Pila simple (linked list) para undo - guarda Particle*
// Pila maneja nodos; la app gestiona el delete de los Particle*
// ---------------------------
struct StackNode {
	Particle * value;
	StackNode * next;
	StackNode(Particle * v, StackNode * n)
		: value(v)
		, next(n) { }
};

class ParticleStack {
public:
	ParticleStack()
		: top(nullptr)
		, sz(0) { }
	~ParticleStack() { clear(); }

	void push(Particle * p) {
		StackNode * n = new StackNode(p, top);
		top = n;
		++sz;
	}

	Particle * pop() {
		if (!top) return nullptr;
		StackNode * n = top;
		Particle * v = n->value;
		top = top->next;
		delete n;
		--sz;
		return v;
	}

	bool empty() const { return top == nullptr; }
	int size() const { return sz; }

	void clear() {
		while (top) {
			StackNode * n = top;
			top = top->next;
			delete n;
		}
		sz = 0;
	}

private:
	StackNode * top;
	int sz;
};

// ---------------------------
// ofApp (usa vector<Particle*>, ParticleStack, interacción)
// ---------------------------
class ofApp : public ofBaseApp {
public:
	void setup() override;
	void update() override;
	void draw() override;

	void keyPressed(int key) override;
	void mousePressed(int x, int y, int button) override;
	void exit() override;

private:
	std::vector<Particle *> particles; // arreglo dinámico con punteros
	ParticleStack undoStack; // pila manual para undo

	bool spawning = true;
	float spawnTimer = 0.0f;
	float spawnInterval = 0.12f; // segundos

	// helpers
	ofColor pickColor() const;
	void spawnRandom();
	void clearAll();
};
