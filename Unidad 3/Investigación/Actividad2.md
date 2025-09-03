# Actividad 2

### ¿Qué fue lo que incluimos en el archivo .h?

En el archivo .h se agregó setup, update y draw, que es para que funcione la aplicación de la forma más básica, luego se agregaron los controles del mouse tanto del movimiento como de sus botones, para detectar el input que generamos con el mouse. Por último, se agregaron dos variables privadas, la primera es un vector para la posición de las partículas, la otra es una variable color para estas.

### ¿Cómo funciona la aplicación?

La aplicación toma el valor de la ubicación del cursor para asignársela a las partículas, que en este caso son círculos que se van generando a medida de que se mueve el cursor y cada que se generan nuevos círculos los más antiguos se van desapareciendo simulando unas partículas que va dejando el cursor, además cada que se presiona cualquier botón del mouse, este va a cambiar el color de las partículas.

### ¿Qué hace la función mouseMoved?

Crea un circulo cada que se mueve el mouse de posición y solo guarda los últimos 100 círculos creados, porque elimina cada circulo que sobre pase ese límite.

### ¿Qué hace la función mousePressed?

Cambia de color las partículas cada que se presiona un botón del mouse de forma random utilizando números aleatorios del 0 al 255 en R, G y B.

### ¿Qué hace la función setup?

Crea las condiciones iniciales, en este caso, pone las particulas en color blanco y el fondo negro.

### ¿Qué hace la función update?

Esta vacía en este caso, pero actualiza el programa cada que pasa un frame.

### ¿Qué hace la función draw?

Crea lo que se va a ver, en este caso, crea circulos de radio 50 en la posición del cursor, también cambia el color de las partículas, y tiene el vector de la posición todas las partículas.
