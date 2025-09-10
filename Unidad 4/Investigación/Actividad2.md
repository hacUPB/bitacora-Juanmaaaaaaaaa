# Actividad 2


1. Entendiendo la aplicación

El programa en C++ con openFrameworks implementa dos estructuras de datos: stack (pila) y queue (cola), donde cada nodo representa un círculo en la pantalla. En el stack, al presionar 'a' se apila un círculo en la posición del mouse y con 'd' se desapila el último agregado, mostrando el comportamiento LIFO. En la queue, 'a' encola un círculo en la posición del mouse y 'd' desencola el primero en entrar, mostrando el comportamiento FIFO. La memoria se gestiona manualmente con new y delete, y se liberan nodos con clear() para evitar fugas.

2. Evaluaciones formativas

Las preguntas de repaso permiten comprobar con el depurador el estado de los punteros y la memoria: por ejemplo, observar cómo cambia top al apilar y desapilar, qué sucede con rear cuando se desencola el último nodo, o qué nodo queda al frente después de varias operaciones. También plantean qué ocurre si no se libera la memoria con delete, reforzando la importancia de entender punteros, condiciones de vacío y gestión manual de nodos.

3. Pruebas sugeridas

Para validar el programa se recomienda probar el apilado/desapilado en el stack verificando que siempre se elimine el último círculo agregado, y el encolado/desencolado en la queue comprobando que se respete el orden de llegada. Además, se deben realizar pruebas de memoria para confirmar que no existan fugas al vaciar las estructuras o al cerrar la aplicación, lo que asegura un uso correcto de punteros y delete.