# Reto 

### Descripción

- Clase base Particle (interfaz virtual).

- Dos clases derivadas: FastParticle y SlowParticle.

- std::vector<Particle*> particles para almacenar instancias (arreglo dinámico).

- ParticleStack pila ligada para undo.

- Interacciones: S (toggle spawn), R (remove last + push undo), U (undo), C (clear all), left/right click para crear partículas.

### Experimentos (RAE2):

1. Creación y destrucción:

- Creé varias partículas por spawn automático y por clic.

- Observé con el depurador (breakpoints en mousePressed, keyPressed, y clearAll) que cuando elimino partículas se ejecuta delete y particles.size() decrece.

2. Undo (pila):

- Presioné R para remover y U para restaurar.

- Verifiqué que undoStack.size() aumentaba y luego disminuía.

3. Polimorfismo:

- Inspeccioné un Particle* en el vector con el depurador y confirmé que la llamada virtual draw() dibuja según el tipo real.

4. Gestión de memoria al cerrar:

- Ejecuté la app, generé partículas y cerré. En exit() se llamó clearAll() y no hubo fugas detectadas con el análisis básico del IDE.

### Reflexión final:

El uso de métodos virtuales me permitió diseñar la jerarquía y delegar comportamientos específicos en las clases derivadas. Esto añade un pequeño overhead (vptr) pero mejora claridad y extensibilidad.

La pila manual mostró la necesidad de definir claramente la propiedad de memoria: la app es responsable de delete.

Para optimizar mantendría el diseño polimórfico, pero en una versión más exigente.


Video: https://youtu.be/6ARnj82jfvY