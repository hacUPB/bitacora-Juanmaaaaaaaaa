# Sesión 2


### Observer

El patrón Observer permite que un objeto (llamado sujeto) notifique automáticamente a otros objetos (observadores) cuando ocurre un evento, sin depender directamente de ellos. En este caso, la clase ofApp actúa como el sujeto, heredando de Subject. Cuando se presiona una tecla, ofApp::keyPressed llama a notify("attract"), notify("repel"), etc., y el método notify recorre todos los observadores (las partículas) ejecutando onNotify(event) en cada uno. De esta forma, todas las partículas reciben el mismo mensaje y reaccionan según su propia lógica, sin que ofApp necesite saber cómo lo hacen internamente.

### Factory

El patrón Factory se usa para centralizar la creación de objetos con diferentes configuraciones, evitando repetir código o condicionales dispersos. En este proyecto, ParticleFactory::createParticle(type) es el punto único donde se crean las partículas y se les asignan características según su tipo ("star", "shooting_star", "planet"). Así, cuando ofApp::setup necesita nuevas partículas, simplemente llama a la fábrica con el tipo deseado y obtiene un objeto completamente configurado (con su color, tamaño y velocidad apropiados).

### State

El patrón State encapsula los distintos comportamientos que puede tener un objeto dependiendo de su estado interno, permitiendo cambiar entre ellos sin usar largas estructuras condicionales. Aquí, la clase Particle mantiene un puntero a un objeto State, que puede ser NormalState, AttractState, RepelState o StopState. Cada estado define su propio comportamiento en el método update(Particle*). Cuando la partícula recibe un evento, por ejemplo "repel", cambia su estado con setState(new RepelState()), y desde ese momento su movimiento se comporta según la lógica del estado de repulsión, hasta que un nuevo evento modifique su estado nuevamente.