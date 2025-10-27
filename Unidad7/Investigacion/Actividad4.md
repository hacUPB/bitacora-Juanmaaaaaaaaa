# Actividad 4

1. ¿Qué hace el código del ejemplo?

Permite que los shaders respondan a la interacción del usuario, por ejemplo, al mover el mouse o presionar teclas.
El color o la forma cambian según esos datos.

2. ¿Cómo funciona la comunicación?

La aplicación envía la posición del mouse como un uniform al shader.
El fragment shader usa esas coordenadas para modificar el color o posición de los píxeles en tiempo real.