# Sesión 2

## Análisis de la estructura de una clase

### ¿Dónde se almacenan los datos y métodos de una clase en C++ en la memoria?

Los datos de una clase se almacenan en el stack o en el heap, dependiendo de si el objeto fue creado de manera automática o dinámica. Los métodos no se copian en cada objeto, sino que residen en la sección de código (.text) del programa, siendo compartidos por todas las instancias. Cuando la clase tiene métodos virtuales, cada objeto incluye un puntero oculto a la vtable, que está en la sección de datos de solo lectura (.rodata).

### ¿Qué es una vtable y cómo se relaciona con los métodos virtuales?

Una vtable (tabla de funciones virtuales) es una estructura generada por el compilador que contiene punteros a las implementaciones de los métodos virtuales de una clase. Cada objeto con métodos virtuales incluye un puntero oculto a la vtable correspondiente a su tipo dinámico. Así, cuando se invoca un método virtual mediante un puntero o referencia a la clase base, el programa consulta la vtable y llama a la implementación correcta según el tipo real del objeto.

## Exploración de métodos virtuales

### ¿En qué parte de la memoria se encuentran las vtables de cada objeto?

Las vtables se almacenan en la sección .rodata (read-only data) del programa, ya que son estructuras creadas por el compilador que no cambian en tiempo de ejecución. Cada clase con métodos virtuales tiene su propia vtable en esa sección, y cada objeto de esa clase incluye un puntero que la referencia. Esto permite que todos los objetos de la misma clase compartan la misma vtable, optimizando memoria y garantizando polimorfismo dinámico.

### ¿Cómo afecta la presencia de métodos virtuales al tamaño del objeto?

La inclusión de métodos virtuales agrega un puntero oculto a la vtable en cada objeto, lo cual aumenta su tamaño en al menos el tamaño de un puntero (4 bytes en 32 bits o 8 bytes en 64 bits). Esto significa que incluso un objeto con atributos mínimos ocupa más memoria si posee métodos virtuales. Aunque esta sobrecarga es pequeña, se debe considerar en sistemas con muchos objetos, pues impacta en la eficiencia espacial.

### ¿Qué papel juegan las vtables en el polimorfismo?

Las vtables permiten que el polimorfismo dinámico funcione en C++. Cuando un método virtual se invoca a través de un puntero o referencia a la clase base, el programa utiliza el puntero a la vtable del objeto para determinar cuál versión del método ejecutar. Esto habilita que un mismo código trabaje con diferentes tipos derivados de forma uniforme, garantizando flexibilidad y extensibilidad en el diseño orientado a objetos.

### ¿Cómo se implementan los métodos virtuales en C++?

Los métodos virtuales se implementan mediante un mecanismo de despacho dinámico basado en la vtable. Al compilar una clase con virtuales, el compilador genera una tabla con punteros a las funciones que representan las implementaciones de esos métodos. En tiempo de ejecución, cada objeto tiene un puntero a su vtable, y cuando se llama a un método virtual, el programa busca la dirección en la tabla y realiza un salto indirecto a la función correspondiente.

## Uso de punteros y referencias

### ¿Cuál es la relación entre los punteros a métodos y la vtable?

Los punteros a funciones y la vtable están relacionados en que ambos contienen direcciones de funciones en memoria, pero cumplen roles distintos. Un puntero a función es gestionado explícitamente por el programador y puede apuntar a funciones libres o estáticas, mientras que una vtable es gestionada automáticamente por el compilador y organiza los métodos virtuales de una clase para soportar polimorfismo dinámico. La vtable puede verse como un arreglo de punteros a funciones administrado de forma interna.

### ¿Qué diferencia hay entre punteros a funciones y punteros a métodos miembro en C++?

Un puntero a función es una variable que almacena la dirección de una función global o estática, y su tamaño suele ser igual al de un puntero normal. En cambio, un puntero a método miembro requiere información adicional porque las funciones miembro dependen de un objeto y necesitan acceso a this. Por esto, los punteros a métodos miembro pueden ser más complejos e incluso ocupar más espacio. A nivel de rendimiento, ambos implican un salto indirecto, pero los punteros a métodos miembro añaden el paso extra de ajustar el contexto del objeto.

### ¿Dónde residen los datos y métodos de una clase en la memoria?

Los atributos de un objeto residen en el stack o en el heap, dependiendo de cómo se haya creado la instancia. Los métodos están en la sección de código del programa (.text) y son compartidos por todas las instancias. En el caso de métodos virtuales, la vtable se encuentra en la sección de datos de solo lectura (.rodata), y cada objeto con virtuales incluye un puntero oculto que apunta a ella.

### ¿Cómo interactúan las diferentes partes en tiempo de ejecución?

En tiempo de ejecución, los atributos del objeto se leen directamente desde el stack o heap, mientras que las llamadas a métodos se resuelven consultando el código en la sección de texto. Si el método es virtual, el programa primero accede al puntero de vtable dentro del objeto, consulta la dirección de la función en la tabla y luego salta a la implementación adecuada. Esto asegura que se ejecute la versión correcta del método, según el tipo dinámico del objeto.

### ¿Cómo afecta esta comprensión al diseño de sistemas?

Comprender dónde residen los datos y métodos en memoria permite tomar decisiones más informadas sobre uso de polimorfismo, eficiencia y organización de clases. Por ejemplo, saber que los métodos virtuales añaden sobrecarga ayuda a evaluar si conviene usarlos en estructuras con millones de objetos. También permite optimizar el diseño separando datos y comportamientos cuando sea necesario, y balancear entre flexibilidad (vtable y polimorfismo) y rendimiento (llamadas directas a funciones).