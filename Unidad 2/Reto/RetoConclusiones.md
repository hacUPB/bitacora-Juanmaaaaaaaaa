## Retos

### Reto 1

- ¿Cómo están implementadas las variables `i` y `sum`?

Como enteros (int) locales, almacenados en la RAM.

- ¿En qué direcciones de memoria están estas variables?

En direcciones de memoria dentro de la RAM, no son fijas ni visibles sin ejecutar el programa.

- ¿Cómo está implementado el ciclo `while`?

Como una serie de saltos condicionales que repiten el bloque de código mientras se cumpla la condición (i <= 100).

- ¿Cómo se implementa la variable `i`?

Se representa como un entero, su valor se lee y modifica mediante instrucciones con registros y memoria.

- ¿En qué parte de la memoria se almacena la variable `i`?

En la memoria RAM porque es una variable local.

Después de todo lo que has hecho, ¿Qué es entonces una variable?

Un nombre simbólico para una posición de memoria que almacena un valor que puede cambiar durante la ejecución.

- ¿Qué es la dirección de una variable?

Es la ubicación en memoria donde está guardado su valor.

- ¿Qué es el contenido de una variable?

Es el valor almacenado en la dirección de memoria de la variable.

### Reto 2

ciclo for:

      int i = 1;
      int sum = 0;
      for (int i = 1; i <= 100; i++)
      {
         sum += i;
      }

### Reto 3 
 
(En documento asm)

### Reto 4

- ¿Cómo se declara un puntero en C++? `int *punt;`. `punt` es una variable que almacenará la dirección de un variable que almacena enteros.

Un puntero se declara anteponiendo un asterisco (*) al nombre de la variable, especificando el tipo de dato al que apunta. int *punt; declara un puntero llamado punt que podrá almacenar la dirección de memoria de una variable de tipo int.

- ¿Cómo se define un puntero en C++? `punt = &var;`. Definir el puntero es inicializar el valor del puntero, es decir, guardar la dirección de una variable. En este caso `punt` contendrá la dirección de `var` .

Definir un puntero significa asignarle una dirección de memoria válida. Esto se hace utilizando el operador &, que permite obtener la dirección de una variable existente. punt = &var, guarda en el puntero punt la dirección de memoria de la variable var, lo que permite que punt apunte directamente a esa variable. 

- ¿Cómo se almacena en C++ la dirección de memoria de una variable? Con el operador `&`. `punt = &var;`

La dirección de memoria de una variable se obtiene usando el operador & antes del nombre de la variable. Este operador devuelve la ubicación exacta en memoria donde está almacenado el valor de esa variable. Así, si var es una variable, &var representa su dirección, que puede ser almacenada en un puntero.

- ¿Cómo se escribe el contenido de la variable a la que apunta un puntero? Con el operador . `punt = 20;`. En este caso como `punt` contiene la dirección de `var`  entonces `punt` a la izquierda del igual indica que quieres actualizar el valor de la variable `var` .
 
punt es un puntero que apunta a var, escribir *punt = 20; significa cambiar el contenido de var a 20. Es decir, el * permite acceder al valor de la dirección almacenada en el puntero.

### Reto 5

(En documento asm)

### Reto 6

(En documento asm)

### Reto 7

(En documento asm)

### Reto 8

- ¿Qué hace esto `int *pvar;`?

Declara un puntero a entero, llamado p_var.

- ¿Qué hace esto `pvar = var;`?

Esta asignando el valor de var directamente a un puntero, no la dirección.

- ¿Qué hace esto `var2 = *pvar`?

Esta asignando el valor al que apunta el puntero en la variable var2.

- ¿Qué hace esto `pvar = &var3`?

Hace que el puntero p_var apunte a la dirección de var3.

### Reto 9 

(En documento asm)


### Explica cómo probaste las partes del programa y cómo probaste el programa completo RAE2

Para todos los puntos del reto se utilizó prueba y error, en donde si no funcionaba algo en el emulador, miraba otra forma de hacerlo pensando de forma lógica con la ayuda de los conocimientos aprendidos en la unidad gracias al profe y a la investigación propia.
Esto generaba que al final la mayoría tuviera un buen funcionamiento al finalizar la unidad.