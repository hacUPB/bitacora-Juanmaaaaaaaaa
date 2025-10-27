# Actividad 2

1. ¿Cómo funciona?

El código activa el shader, que reemplaza la forma en que OpenFrameworks dibuja los píxeles.
El fragment shader calcula los colores de cada píxel según una fórmula o parámetros enviados desde la CPU.

2. ¿Qué resultados obtuviste?

Con el shader desactivado (//shader.begin() y //shader.end() comentados): se ve un rectángulo blanco.

![alt text](<Captura de pantalla 2025-10-22 171909.png>)

Con el shader activado: cambia el color o patrón según el código del shader.

![alt text](<Captura de pantalla 2025-10-22 172021.png>)


3. ¿Estás usando un vertex shader?

Sí.
El vertex shader procesa las coordenadas de los vértices del rectángulo y los transforma antes de pasarlos al fragment shader.

4. ¿Estás usando un fragment shader?

Sí.
El fragment shader determina el color final de cada píxel del rectángulo.

5. ¿Qué hace cada uno?

Vertex shader: define la posición de los vértices en pantalla.

Fragment shader: decide el color final del píxel, creando efectos visuales.