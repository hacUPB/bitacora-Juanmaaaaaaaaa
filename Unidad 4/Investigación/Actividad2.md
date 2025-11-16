# Actividad 2

1. Entendiendo la aplicación

Para esta actividad trabajé con dos implementaciones manuales en C++ usando openFrameworks:
una pila (stack) y una cola (queue), ambas dibujando círculos en pantalla y manejando memoria manualmente con new y delete.

Comencé usando ChatGPT con el siguiente prompt:

“Quiero entender de manera muy detallada el siguiente programa hecho en C++ y openFrameworks.”

Le pasé el código de la pila y la cola y empecé a preguntarle punto por punto cómo funcionaban los nodos, cómo se enlazaban, cómo se hacía la gestión de memoria, y cómo se dibujaban los círculos.

Mientras tanto, abrí el proyecto en Visual Studio, activé depuración y fui comprobando lo que ChatGPT explicaba.
Verifiqué:

- Que push() crea un nodo nuevo y lo enlaza a top.

- Que pop() elimina el nodo superior y libera memoria.

- Que en la cola, enqueue() agrega al final y actualiza rear.

- Que dequeue() elimina desde el frente y libera memoria.

- Que clear() realiza llamadas repetidas a pop() o dequeue().

Con el depurador revisé:

- El estado de los punteros (top, front, rear) paso a paso.

- Que los nodos se destruían correctamente.

- Que después de eliminar nodos ya no había referencias inválidas.

Pude observar claramente los cambios en memoria mientras interactuaba con las teclas 'a' y 'd'.

2. Evaluaciones formativas

Le pedí a ChatGPT que generara preguntas para validar si realmente estaba entendiendo cómo funcionaban las dos estructuras. Algunas preguntas fueron:

- “¿Cuál es el orden en el que se dibujan los círculos en un stack?”

Los círculos se dibujan desde el último que se apiló hacia el primero, porque el stack es una estructura LIFO. Eso significa que el nodo que está más arriba (top) es el primero que se recorre en display(), así que espero que los círculos aparezcan en pantalla en el orden inverso al que los añadí.

- “¿Qué pasa si llamo pop() cuando la pila está vacía?”

Supongo que no pasará nada grave porque el método pop() revisa si top es distinto de nullptr antes de hacer delete. Entonces, pienso que simplemente no va a eliminar ningún nodo y el programa continuará sin fallar.

- “¿Qué sucede con el puntero rear cuando desencolo el último nodo?”

Cuando desencolo el último nodo, el puntero front quedará en nullptr y el código va a detectar esto para poner también rear en nullptr. Eso significa que la cola queda completamente vacía y ambos punteros deben quedar en nullptr, evitando que rear quede apuntando a memoria liberada.

Este proceso me obligó a verificar cuidadosamente cada paso y me ayudó a entender la diferencia entre LIFO y FIFO a nivel de punteros.

3. Pruebas del programa

Le pedí a ChatGPT que me recomendara formas de probar las funciones individualmente y el programa completo. Probé:

**Pruebas para Stack**

- Presionar 'a' varias veces y confirmar que los nodos aparecen en orden inverso al agregado.

- Presionar 'd' repetidamente para asegurarme de que la memoria se libera y top avanza correctamente.

- Hacer pop() cuando la pila está vacía para comprobar que no ocurre un crash.

**Pruebas para Queue**

- Agregar varios nodos con 'a' y confirmar que se dibujan en el mismo orden en el que se agregaron.

- Desencolar con 'd' y observar cómo front se mueve al siguiente nodo.

- Usar el depurador para verificar que cuando front queda en nullptr, el puntero rear también se vuelve nullptr.

Todas las pruebas coincidieron con el comportamiento esperado.

### Preguntas de reflexión — Stack

1. ¿Cómo se gestiona la memoria en una implementación manual de un stack en C++?

En este stack cada nodo se reserva con new, y cada pop() elimina el nodo superior con delete.
Esto hace que la responsabilidad de evitar fugas de memoria recaiga totalmente en el programador.
Es eficiente porque solo hay operaciones en la cima, pero también es propenso a errores si olvido liberar un nodo.

2. ¿Por qué es importante liberar la memoria al desapilar?

Si no se libera memoria en cada pop(), los nodos eliminados quedan en memoria sin acceso, creando fugas que pueden acumularse y afectar el rendimiento, especialmente en aplicaciones de larga duración como simulaciones visuales.

3. ¿Qué diferencias existen entre usar std::stack y un stack manual?

std::stack maneja toda la memoria automáticamente y es más seguro.
Un stack manual, aunque más complejo, da control total sobre:

- cómo se almacenan los nodos.

- cómo se dibujan.

- cómo se libera exactamente la memoria.

Esto lo hace ideal para aprender o para proyectos muy personalizados.

4. ¿Cómo afecta la estructura LIFO al acceso?

En un stack solo puedo acceder al último elemento agregado.
Esto lo hace ideal para:

- deshacer acciones.

- recorrer árboles en profundidad.

- evaluar expresiones matemáticas.

Pero no sirve para acceder al “fondo” rápidamente.

5. ¿Cómo almacenar datos más complejos sin problemas de memoria?

Podría almacenar objetos completos, pero debe tener destructor adecuado para evitar fugas.
También podría usar shared_ptr para simplificar la gestión, pero eso cambiaría la naturaleza manual del stack.

### Autoevaluación — Stack

- Sí puedo explicar cómo se apila y desapila un nodo y cómo funciona la memoria.

- Sí puedo identificar fugas de memoria usando el depurador.

- Podría implementar una función de búsqueda sin romper el orden del stack.

- Entiendo claramente qué problemas se benefician del modelo LIFO.

- Soy capaz de extender el stack a tipos de datos más complejos.

### Preguntas de reflexión — Queue
1. ¿Cómo se maneja la memoria en una queue manual?

Cada nodo se crea con new y se libera al desencolar.
Los punteros front y rear deben mantenerse correctamente para evitar nodos perdidos.

2. ¿Qué desafíos presenta una queue frente a un stack?

La queue necesita manejar dos punteros (front y rear), lo que hace más fácil perder referencias si no se actualizan correctamente.
En un stack solo gestiono top.

3. ¿Cómo afecta FIFO a su uso?

FIFO es ideal para:

- colas de espera.

- procesamiento de tareas en orden.

- simulaciones de tráfico o flujo.

El orden de llegada define el orden de salida.

4. ¿Cómo podría implementar una queue circular?

Debería hacer que el último nodo apunte al primero.
La ventaja es usar memoria de manera más eficiente porque reutiliza posiciones sin fragmentación.

5. ¿Qué problemas surgen si no manejo bien front y rear?

Puedo perder acceso a nodos, generar fugas de memoria o dejar la queue en un estado inconsistente.
Para evitarlos:

- verificar siempre condiciones de lista vacía.

- actualizar ambos punteros cuando la queue queda vacía.

### Autoevaluación — Queue

- Sí puedo explicar encolar y desencolar con memoria manual.

- Sí puedo identificar errores de puntero en front y rear.

- Puedo convertir esto en una queue circular.

- Entiendo claramente los problemas que se benefician del modelo FIFO.

- Puedo manejar tipos complejos asegurando que no haya fugas.