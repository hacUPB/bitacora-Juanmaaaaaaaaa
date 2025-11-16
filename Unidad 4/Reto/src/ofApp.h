#pragma once
#include "ofMain.h"

// ------------------- Particle (lista enlazada) -------------------
class Particle {
public:
	ofVec2f pos;
	ofVec2f vel;
	ofColor color;
	float radius;
	Particle * next;

	Particle(float x, float y, const ofColor & c, const ofVec2f & v)
		: pos(x, y)
		, vel(v)
		, color(c)
		, radius(4.0f)
		, next(nullptr) { }

	~Particle() {
		// no resources aparte de datos simples
	}
};

class ParticleList {
public:
	Particle * head;
	Particle * tail;
	int size;

	ParticleList()
		: head(nullptr)
		, tail(nullptr)
		, size(0) { }
	~ParticleList() { clear(); }

	void pushBack(float x, float y, const ofColor & c, const ofVec2f & v) {
		Particle * p = new Particle(x, y, c, v);
		if (tail) {
			tail->next = p;
			tail = p;
		} else {
			head = tail = p;
		}
		size++;
	}

	// actualiza y elimina partículas que salen de la pantalla
	void update(float width, float height) {
		Particle * prev = nullptr;
		Particle * cur = head;
		while (cur) {
			// movimiento simple con gravedad
			cur->vel.y += 0.12f; // gravedad pequeña
			cur->pos += cur->vel;
			cur->radius = ofClamp(cur->radius * 0.997f, 1.0f, 12.0f);

			bool kill = (cur->pos.y - cur->radius > height) || (cur->pos.x + cur->radius < 0) || (cur->pos.x - cur->radius > width);

			if (kill) {
				Particle * toDelete = cur;
				if (prev) {
					prev->next = cur->next;
				} else {
					head = cur->next;
				}
				if (cur == tail) tail = prev;
				cur = cur->next;
				delete toDelete;
				size--;
			} else {
				prev = cur;
				cur = cur->next;
			}
		}
	}

	void display() {
		Particle * cur = head;
		while (cur) {
			ofSetColor(cur->color);
			ofDrawCircle(cur->pos.x, cur->pos.y, cur->radius);
			cur = cur->next;
		}
	}

	void clear() {
		Particle * cur = head;
		while (cur) {
			Particle * next = cur->next;
			delete cur;
			cur = next;
		}
		head = tail = nullptr;
		size = 0;
	}
};

// ------------------- Burst (pila) -------------------
class Burst {
public:
	ofVec2f center;
	float radius;
	float growth;
	float life; // disminuye hasta 0
	ofColor color;
	Burst * next;

	Burst(float x, float y, const ofColor & c)
		: center(x, y)
		, radius(2.0f)
		, growth(1.8f)
		, life(1.0f)
		, color(c)
		, next(nullptr) { }

	~Burst() { }
};

class BurstStack {
public:
	Burst * top;
	int size;

	BurstStack()
		: top(nullptr)
		, size(0) { }
	~BurstStack() { clear(); }

	void push(float x, float y, const ofColor & c) {
		Burst * b = new Burst(x, y, c);
		b->next = top;
		top = b;
		size++;
	}

	void pop() {
		if (!top) return;
		Burst * t = top;
		top = top->next;
		delete t;
		size--;
	}

	// actualizar: expandir y decrementar vida; eliminar bursts "muertos"
	void update() {
		Burst * prev = nullptr;
		Burst * cur = top;
		while (cur) {
			cur->radius += cur->growth;
			cur->life -= 0.02f;
			if (cur->life <= 0.0f) {
				Burst * toDelete = cur;
				if (prev) {
					prev->next = cur->next;
				} else {
					top = cur->next;
				}
				cur = cur->next;
				delete toDelete;
				size--;
			} else {
				prev = cur;
				cur = cur->next;
			}
		}
	}

	void display() {
		Burst * cur = top;
		while (cur) {
			ofPushStyle();
			ofSetColor(cur->color, (int)ofMap(cur->life, 0, 1, 0, 200));
			ofNoFill();
			ofSetLineWidth(2 + cur->life * 3);
			ofDrawCircle(cur->center.x, cur->center.y, cur->radius);
			ofPopStyle();
			cur = cur->next;
		}
	}

	void clear() {
		Burst * cur = top;
		while (cur) {
			Burst * next = cur->next;
			delete cur;
			cur = next;
		}
		top = nullptr;
		size = 0;
	}
};

// ------------------- ofApp -------------------
class ofApp : public ofBaseApp {
public:
	ParticleList particles;
	BurstStack bursts;

	// paleta (arreglo simple)
	static const int PAL_SIZE = 6;
	ofColor palette[PAL_SIZE];

	// control
	bool spawning = true;
	float spawnTimer = 0.0f;
	float spawnInterval = 0.06f; // frecuencia de nuevas partículas
	bool slowMotion = false;

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void exit(); // para asegurar limpieza en caso de cierre inesperado

	// util
	ofColor pickPaletteColor();
};
