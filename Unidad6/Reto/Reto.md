# Reto

## Idea



## Patrones

Observer: En el proyecto ofApp actúa como Subject y cada Particle es un Observer. ofApp registra partículas con addObserver y cuando el usuario presiona una tecla hace notify("evento"). El notify recorre la lista de observadores y ejecuta onNotify(event) en cada Particle. Así todas las partículas reaccionan al mismo evento (cambiar color, subir, bajar, hover on/off, desaparecer) sin que ofApp deba conocer detalles de la reacción de cada una.

Factory: ParticleFactory::createParticle(type) centraliza la creación y configuración de los cuadrados. Cuando ofApp::setup necesita muchos cuadrados, llama a la fábrica con tipos (por ejemplo "small", "medium", "large") y recibe Particle* ya configuradas en tamaño, color y velocidad. La fábrica evita duplicar código de inicialización y facilita añadir nuevos tipos de cuadrados en un solo lugar.

State: Cada Particle mantiene un puntero State* state. Los estados concretos (NormalState, UpState, DownState, DisappearState) encapsulan el comportamiento de movimiento o visibilidad. Cuando una partícula recibe el evento "up", hace setState(new UpState()) y desde ese momento su update() delega el movimiento en la lógica del UpState. Cambiar de estado se hace sin if/switch dispersos: se instancia el estado correspondiente y la conducta cambia automáticamente.