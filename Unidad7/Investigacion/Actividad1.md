# Actividad 1

1. ¿Qué son los vértices?

Los vértices son los puntos que definen la forma de un objeto 3D.
Por ejemplo, un triángulo tiene 3 vértices. Cada vértice guarda información como su posición en el espacio (x, y, z), color, coordenadas de textura y normales.

2. ¿Con qué figura geométrica se dibuja en 3D?

Con triángulos.
Cualquier forma 3D (cubos, esferas, personajes) se descompone en triángulos porque son la figura más simple y eficiente para representar superficies planas.

3. ¿Qué es un shader?

Un shader es un pequeño programa que se ejecuta en la GPU.
Su función es decirle a la tarjeta gráfica cómo dibujar cada vértice y cada píxel (fragmento).
Existen varios tipos, siendo los principales el vertex shader y el fragment shader.

4. ¿Cómo se les llama a los grupos de píxeles de un mismo triángulo?

Se les llama fragmentos.
Cada fragmento representa un posible píxel en la pantalla que pertenece a un triángulo.

5. ¿Qué es un fragment shader?

El fragment shader calcula el color final de cada píxel que aparece en la pantalla.
Aquí decides cómo se ve la superficie: color, textura, iluminación, brillo, etc.

6. ¿Qué es un vertex shader?

El vertex shader se encarga de procesar cada vértice: transforma su posición, aplica rotaciones, escalas, proyecciones y puede pasar información al fragment shader.

7. ¿Al proceso de determinar qué píxeles del display va a cubrir cada triángulo de una mesh se le llama?

Se llama rasterización.
Es el paso donde se decide qué píxeles corresponden a cada triángulo.

8. ¿Qué es el render pipeline?

El render pipeline es la cadena de pasos que sigue la GPU para convertir datos 3D (vértices) en una imagen 2D visible.
Incluye:

Procesamiento de vértices

Rasterización

Procesamiento de fragmentos

Mezcla y salida en pantalla

9. ¿Hay alguna diferencia entre aplicar un color a una superficie o aplicar una textura?

Sí.

Color: es un valor fijo o calculado (por ejemplo, rojo).

Textura: es una imagen que se “pega” sobre la superficie y puede tener variaciones de color, brillo o relieve.

10. ¿Cuál es la diferencia entre una textura y un material?

Textura: una imagen o mapa de píxeles.

Material: combina una o varias texturas + propiedades físicas (brillo, transparencia, reflexión, rugosidad).
El material define cómo interactúa la superficie con la luz.

11. ¿Qué transformaciones se requieren para mover un vértice del 3D world al View Screen?

Model transform: coloca el objeto en el mundo.

View transform: ajusta la vista de la cámara.

Projection transform: proyecta el mundo 3D en la pantalla 2D.

Viewport transform: lo adapta al tamaño real del display.

12. ¿Al proceso de convertir los triángulos en fragmentos se le llama?

También rasterización (como en la pregunta 7).

13. ¿Qué es el framebuffer?

El framebuffer es una memoria temporal donde se almacenan los resultados de los cálculos gráficos antes de mostrarlos en pantalla (colores, profundidad, transparencia).

14. ¿Para qué se usa el Z-buffer o depth buffer en el render pipeline?

El Z-buffer guarda la distancia de cada píxel respecto a la cámara.
Sirve para saber qué objeto está más cerca y evitar dibujar los que quedan detrás (ocultamiento).

15. Luego de ver el segundo video, ¿por qué la GPU tiene que funcionar tan rápido y de manera paralela?

Porque debe procesar millones de vértices y píxeles al mismo tiempo para cada cuadro (frame).
A diferencia de la CPU (que tiene pocos núcleos muy potentes), la GPU tiene miles de núcleos pequeños trabajando en paralelo, lo que permite renderizar gráficos a alta velocidad (60 fps o más).