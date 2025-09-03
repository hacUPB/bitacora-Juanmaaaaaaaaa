#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	ofSetFrameRate(60);

	xStep = 50;
	yStep = 50;
	distDiv = 100.0f;
	amplitud = 100.0f;
	sphereRadius = 10;

	generateGrid();
	sphereSelected = false;
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();

	// Dibujar todas las esferas
	for (auto & pos : spherePositions) {
		if (sphereSelected && pos == selectedSphere) {
			ofSetColor(255, 0, 0); // rojo para esfera seleccionada
		} else {
			ofSetColor(200);
		}
		ofDrawSphere(pos, sphereRadius);
	}

	cam.end();

	// Mostrar info de esfera seleccionada
	if (sphereSelected) {
		ofSetColor(255);
		ofDrawBitmapString("Esfera seleccionada:", 20, 20);
		ofDrawBitmapString("X: " + ofToString(selectedSphere.x), 20, 40);
		ofDrawBitmapString("Y: " + ofToString(selectedSphere.y), 20, 60);
		ofDrawBitmapString("Z: " + ofToString(selectedSphere.z), 20, 80);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key) {
	case 'w':
		amplitud += 10;
		break;
	case 's':
		amplitud -= 10;
		break;
	case 'a':
		distDiv -= 5;
		if (distDiv < 5) distDiv = 5;
		break;
	case 'd':
		distDiv += 5;
		break;
	case '+':
		xStep += 5;
		yStep += 5;
		break;
	case '-':
		if (xStep > 5 && yStep > 5) {
			xStep -= 5;
			yStep -= 5;
		}
		break;
	}
	generateGrid(); // regenerar posiciones al cambiar parámetros
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	glm::vec3 rayStart, rayEnd;
	convertMouseToRay(x, y, rayStart, rayEnd);

	sphereSelected = false;
	for (auto & pos : spherePositions) {
		glm::vec3 intersectionPoint;
		if (rayIntersectsSphere(rayStart, rayEnd - rayStart, pos, sphereRadius, intersectionPoint)) {
			sphereSelected = true;
			selectedSphere = pos;
			break;
		}
	}
}

//--------------------------------------------------------------
void ofApp::convertMouseToRay(int mouseX, int mouseY, glm::vec3 & rayStart, glm::vec3 & rayEnd) {
	glm::mat4 modelview = cam.getModelViewMatrix();
	glm::mat4 projection = cam.getProjectionMatrix();
	ofRectangle viewport = ofGetCurrentViewport();

	float x = 2.0f * (mouseX - viewport.x) / viewport.width - 1.0f;
	float y = 1.0f - 2.0f * (mouseY - viewport.y) / viewport.height;

	glm::vec4 rayStartNDC(x, y, -1.0f, 1.0f);
	glm::vec4 rayEndNDC(x, y, 1.0f, 1.0f);

	glm::vec4 rayStartWorld = glm::inverse(projection * modelview) * rayStartNDC;
	glm::vec4 rayEndWorld = glm::inverse(projection * modelview) * rayEndNDC;

	rayStartWorld /= rayStartWorld.w;
	rayEndWorld /= rayEndWorld.w;

	rayStart = glm::vec3(rayStartWorld);
	rayEnd = glm::vec3(rayEndWorld);
}

//--------------------------------------------------------------
bool ofApp::rayIntersectsSphere(const glm::vec3 & rayStart, const glm::vec3 & rayDir,
	const glm::vec3 & sphereCenter, float sphereRadius,
	glm::vec3 & intersectionPoint) {
	glm::vec3 oc = rayStart - sphereCenter;
	float a = glm::dot(rayDir, rayDir);
	float b = 2.0f * glm::dot(oc, rayDir);
	float c = glm::dot(oc, oc) - sphereRadius * sphereRadius;
	float discriminant = b * b - 4 * a * c;

	if (discriminant < 0) {
		return false;
	} else {
		float t = (-b - sqrt(discriminant)) / (2.0f * a);
		intersectionPoint = rayStart + t * rayDir;
		return true;
	}
}

//--------------------------------------------------------------
void ofApp::generateGrid() {
	spherePositions.clear();
	for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += xStep) {
		for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += yStep) {
			float z = cos(ofDist(x, y, 0, 0) / distDiv) * amplitud;
			spherePositions.push_back(glm::vec3(x, y, z));
		}
	}
}
