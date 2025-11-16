# Actividad 1


### 1. Entiende la aplicación

Implementa una serpiente mediante una lista enlazada, donde cada nodo representa un segmento que almacena su posición en el plano. Al inicio se crean 11 nodos ubicados en el centro de la ventana, y en cada actualización el primer nodo sigue la posición del mouse mientras los demás copian la posición anterior de su predecesor, generando el efecto de movimiento encadenado. En el dibujo, cada nodo se representa como un círculo rojo y la pantalla se repinta de gris en cada frame. Además, con la tecla 'c' es posible limpiar la lista y eliminar todos los nodos, dejando la serpiente vacía hasta que se añadan nuevos segmentos manualmente.

### 2. Realiza evaluaciones formativas

- ¿Cuántos nodos tiene la lista apenas inicia la aplicación (antes de setup())?

1 nodo. El constructor de LinkedList crea un head inicial.

- ¿Cuántos nodos tiene la lista justo después de setup()?

11 nodos (1 inicial + 10 del for).

- ¿Qué nodo toma primero la posición del ratón en update()?

El nodo head. Es el primero en asignarse como (mouseX, mouseY).

- ¿Cómo obtiene el segundo nodo su nueva posición?

Toma la posición anterior que tenía la cabeza.

- ¿Se libera memoria cuando presionas 'c'?

Sí. clear() borra todos los nodos con delete.

- ¿El método ~LinkedList() libera los nodos al cerrar la aplicación?

Sí, porque llama clear(). No hay fugas.

- ¿Qué pasa en display() cuando la lista está vacía?

No dibuja nada, porque head == nullptr y el while no se ejecuta.

- ¿Qué ocurre si mueves el ratón rápido?

La serpiente se estira; cada nodo queda a una distancia proporcional al salto entre frames.

- ¿Qué ocurriría si tail se perdiera (tail = nullptr accidentalmente)?

El próximo addNode() trataría la lista como vacía y sobrescribiría head, causando inconsistencia.

- ¿Es seguro llamar clear() y luego seguir dibujando en los frames siguientes?

Sí. display() verifica current != nullptr, así que no hay accesos inválidos.


### 3. ¿Qué es una lista enlazada y en qué se diferencia de un arreglo en cuanto a la forma en que los elementos están almacenados en la memoria?

Una lista enlazada es una estructura de datos donde cada elemento (nodo) contiene datos y un puntero al siguiente nodo, mientras que en un arreglo los elementos se guardan en posiciones contiguas de memoria. En la lista los nodos pueden estar dispersos en memoria y conectados solo por punteros, mientras que en un arreglo se accede por índice directo.

### 4. Al observar el código de una lista enlazada en C++, ¿Cómo crees que se vinculan los nodos entre sí? ¿Qué estructura se utiliza para lograr esta conexión?

Los nodos se vinculan gracias al puntero Node* next que almacena la dirección del siguiente nodo en la lista, formando una cadena de referencias que une todos los elementos.

### 5. ¿Cómo se gestiona la memoria en una lista enlazada? Investiga cómo se crea y se destruye un nodo en memoria utilizando el operador new y delete en C++.

Cada nodo se crea dinámicamente en el heap con el operador new. Cuando ya no se necesita, se libera con delete. Esto significa que el programador controla explícitamente la creación y destrucción de cada nodo.

### 6. Considerando la estructura de una lista enlazada, ¿qué ventajas ofrece en comparación con un arreglo cuando se trata de insertar o eliminar elementos en posiciones intermedias?

En una lista enlazada insertar o eliminar nodos en medio de la estructura es eficiente, pues solo hay que cambiar los punteros de los nodos vecinos. En un arreglo, estas operaciones suelen requerir mover muchos elementos en memoria.

### 7. En el código presentado, ¿Cómo se asegura que no haya fugas de memoria? ¿Qué papel juega el destructor en la clase LinkedList?

El destructor de la clase LinkedList llama al método clear(), que recorre toda la lista y libera cada nodo con delete. Esto asegura que al destruir la lista no quede memoria sin liberar.

### 8. ¿Qué sucede en la memoria cuando se invoca el método clear() en una lista enlazada? 

1. Se toma head como punto de inicio.

2. Se recorre nodo por nodo guardando la dirección del siguiente.

3. Se libera el nodo actual con delete.

4. Al final, todos los nodos desaparecen del heap, y head y tail se ponen en nullptr.

### 9. Explica cómo cambia la estructura en memoria de una lista enlazada al agregar un nuevo nodo al final de la lista. ¿Cómo afecta esto al rendimiento de la lista enlazada?

Se crea un nuevo Node en memoria dinámica. El puntero next del nodo que antes era tail se ajusta para apuntar al nuevo nodo, y tail se actualiza. Esto es eficiente en listas enlazadas porque agregar al final es O(1) si se tiene puntero a la cola.

### 10. Analiza una situación en la que utilizar una lista enlazada sería más ventajoso que utilizar un arreglo. Justifica tu respuesta considerando la gestión de memoria y las operaciones de inserción y eliminación.

Una lista enlazada es mejor que un arreglo cuando necesitas insertar o eliminar elementos frecuentemente en posiciones intermedias o desconoces de antemano el número exacto de elementos, ya que crece dinámicamente sin necesidad de redimensionar bloques contiguos de memoria.

### 11. Después de estudiar el manejo de memoria en listas enlazadas, ¿Cómo aplicarías este conocimiento para diseñar una estructura de datos personalizada para una aplicación creativa? ¿Qué aspectos considerarías para asegurar la eficiencia y evitar fugas de memoria?

Si diseñaras tu propia estructura creativa, por ejemplo una “cola de partículas”, podrías usar una lista enlazada para añadir o eliminar partículas en movimiento de manera eficiente. Deberías incluir un destructor, usar punteros seguros (como unique_ptr) y asegurarte de que cada recurso creado se libere en el momento adecuado.

### 12. Reflexiona sobre las diferencias en la gestión de memoria entre C++ y un lenguaje con recolección de basura automática como C#. ¿Qué ventajas y desafíos encuentras en la gestión explícita de memoria en C++ al trabajar con estructuras de datos?

En C++ la memoria se gestiona explícitamente con new y delete, lo que da mayor control y eficiencia, pero implica riesgo de fugas y errores si se olvida liberar recursos. En C#, la recolección de basura maneja la memoria automáticamente, reduciendo errores, aunque a veces puede introducir pausas y menos control sobre cuándo exactamente se libera la memoria.

### 13. Imagina que estás optimizando una pieza de arte generativo que usa listas enlazadas para representar elementos en movimiento. ¿Qué consideraciones tomarías en cuenta para garantizar que la gestión de la memoria sea eficiente y que no ocurran fugas de memoria?

Al usar listas enlazadas en arte generativo, deberías:

- Asegurarte de liberar nodos que ya no se usan.

- Evitar la creación/destrucción excesiva de nodos en cada frame, usando reutilización si es posible.

- Probar con herramientas de perfilado para detectar fugas de memoria o cuellos de botella.

### 14. Pruebas

- Unidad (LinkedList): crear una lista, agregar nodos, verificar el tamaño, limpiar y confirmar que head == nullptr.

- Integración (ofApp): mover el mouse y observar si la serpiente lo sigue correctamente.

- Prueba de memoria: limpiar con 'c' y verificar con un depurador que no quedan bloques en el heap.

- Prueba visual: comprobar que el número de nodos dibujados coincide con el esperado tras agregar o limpiar.

Pues creo que funcionaron relativamente bien, ps cumple con lo que dice pero de manera muy sencilla.