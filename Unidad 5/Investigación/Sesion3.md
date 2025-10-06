# Sesión 3

## Profundizando en el Encapsulamiento

### ¿Cómo implementa el compilador el encapsulamiento en C++? Si los miembros privados aún ocupan espacio en el objeto, ¿qué impide que se acceda a ellos desde fuera de la clase?
El compilador aplica el encapsulamiento controlando accesos en tiempo de compilación, no en ejecución. Los miembros privados ocupan espacio en el objeto, pero el compilador bloquea su uso directo fuera de la clase; aun así, con punteros o reinterpret_cast pueden leerse porque la memoria sigue accesible.

## Hagamos un poco de hackers y rompamos el encapsulamiento

### ¿Qué es el encapsulamiento y cuál es su propósito en la programación orientada a objetos?
El encapsulamiento es ocultar los detalles internos de una clase y exponer solo lo necesario, protegiendo el estado del objeto y facilitando el mantenimiento del software.

### ¿Por qué es importante proteger los datos de una clase y restringir el acceso desde fuera de la misma?
Es importante porque evita modificaciones incorrectas del estado interno, asegurando consistencia y reduciendo errores lógicos en el programa.

### ¿Qué significa reinterpret_cast y cómo afecta la seguridad del programa?
reinterpret_cast fuerza a tratar memoria como otro tipo, rompiendo la seguridad y pudiendo producir comportamientos indefinidos o vulnerabilidades.

### ¿Por qué se pudo acceder a los miembros privados de MyClass en este experimento, a pesar de que el compilador normalmente lo impediría?
Se pudo porque la restricción es solo del compilador; en ejecución los atributos están en memoria y pueden leerse con punteros.

### ¿Cuáles podrían ser las consecuencias de utilizar técnicas como las mostradas en este experimento en un programa real?
Podrían causar corrupción de datos, fallos y vulnerabilidades, volviendo al programa inseguro y poco confiable.

### ¿Qué implicaciones tiene este experimento sobre la confianza en las barreras de encapsulamiento que proporciona C++?
Implica que el encapsulamiento en C++ es una disciplina de diseño apoyada por el compilador, no una protección física en tiempo de ejecución.

## Herencia y la Relación en Memoria

Pregunta: ¿Cómo se organizan los atributos en memoria?
Los atributos de la clase base se almacenan primero y luego los de la clase derivada, siguiendo el orden de herencia.

### ¿Qué sucede si agregamos más niveles de herencia?
Se van encadenando en memoria: primero la base más antigua, luego las intermedias y al final la derivada más específica.

### ¿Cómo se organiza en memoria un objeto de una clase derivada en C++?
El objeto derivado contiene primero los datos de la base y después sus propios atributos, garantizando compatibilidad entre punteros.

## Polimorfismo y Vtables en detalle

### ¿Cómo utiliza el programa las vtables para el polimorfismo?
Cada objeto guarda un puntero a la vtable de su clase, y al invocar un método virtual se consulta esa tabla para ejecutar la función correcta.

### ¿Cuál es el impacto en el rendimiento?
El impacto es bajo pero existe, ya que las llamadas virtuales requieren un salto indirecto adicional frente a llamadas normales.

### ¿Cómo funciona el polimorfismo en C++ a nivel interno?
Se implementa con vtables y punteros ocultos en los objetos, que permiten resolver en tiempo de ejecución qué versión del método ejecutar.

## Reflexión Individual

### ¿Cómo se implementan internamente el encapsulamiento, la herencia y el polimorfismo?
El encapsulamiento se maneja en compilación, la herencia organiza atributos en orden de base a derivada y el polimorfismo usa vtables y punteros ocultos.

### ¿Cuáles son las ventajas y desventajas en términos de eficiencia y complejidad?
Ventajas: modularidad, reutilización y flexibilidad. 
Desventajas: mayor tamaño de objetos, ligeros costos en llamadas virtuales y más complejidad interna.