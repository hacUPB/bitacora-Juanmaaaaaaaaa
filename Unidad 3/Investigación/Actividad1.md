# Actividad 1

            #include "ofApp.h"

            //--------------------------------------------------------------
            void ofApp::setup(){
                ofBackground(0);
            }

            //--------------------------------------------------------------
            void ofApp::update(){

            }

            //--------------------------------------------------------------
            void ofApp::draw(){
                ofSetColor(255);
                ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 20);
            }

### ¿Cuál es el resultado que se obtiene al ejecutar este programa?

Al ejecutar el programa se puede observar que la aplicación muestra un fondo negro y un círculo de color blanco, el cual cambia su posición dependiendo de donde muevas el cursor, pues este lo sigue y copia su dirección en la pantalla.