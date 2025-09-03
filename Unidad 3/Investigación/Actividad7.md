# Actividad 7

- ¿Qué sucede cuando presionas la tecla “c”? (1)

Cuando se hace globalVector.push_back(&localSphere); se está guardando la dirección de un objeto local en el stack. Ese objeto desaparece al terminar la función, así que el puntero queda apuntando a algo que ya no existe.

- ¿Qué sucede cuando presionas la tecla “c”? (2) y ¿Por qué ocurre esto?

Al presionar “c” con la versión del heap, se crea un objeto en el heap, se guarda su dirección en el vector y el objeto sigue existiendo después de salir de la función. Eso permite acceder a él sin problema, por su nivel de memoría.