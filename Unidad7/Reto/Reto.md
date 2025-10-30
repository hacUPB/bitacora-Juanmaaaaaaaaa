# Reto

¿Qué hace cada shader?

1. Vertex shader (shader.vert)

- Modifica vértices: toma el valor de la textura (texVal) y lo usa para desplazar cada vértice en Y y en Z (profundidad). Además añade una onda (wave) y una ligera torsión (twist) que depende de texcoord.x y texVal. Esto deforma la malla (plane) de forma visible cuando se dibuja el plane.drawWireframe() en tu ofApp::draw().

- Pasa información al fragment shader: calcula vDisp (cantidad de desplazamiento normalizada) y la envía al fragment shader para modular colores.

2. Fragment shader (shader.frag)

- Modifica colores de fragmentos: no limita el color a la textura original; usa la combinación de t (valor de la textura), vDisp y texCoordVarying.y para generar un índice de color. Re-mapea ese índice a una paleta (azul, naranja, rojo) y lo mezcla según texCoordVarying.x para introducir variación horizontal. Finalmente atenúa por la luminancia original para conservar contraste.

Resultado: la malla deformada se pinta con un gradiente dinámico dependiente de la deformación, mostrando visualmente dónde la malla se desplaza más.

3. Reto del profe

- Poner en la maya una imagen, en este caso se dejó todo como estaba antes, pero con la adición de una imagen de un gatito en la malla creada anteriormente.

## Evidencias y RAE

1. Construcción / ejecución

- En la ventana principal se dibuja la malla en wireframe (el plane.drawWireframe()), inclinada por la rotación basada en mouseY.

- La malla ahora aparecerá deformada en ondas y torsionada (vértices movidos).

- En la parte superior izquierda (grayscale img.draw(0,0)), verás la textura original pequeña; la deformación corresponde a los valores de esa textura.

- La superficie del plano tendrá una coloración gradiente (azul, naranja, rojo) que varía según la deformación.

2. Probar el vertex shader (evidencia)

- Qué comprobar: que los vértices se mueven según la textura.

- Cómo probar: usar mouseX para variar noiseScale. Observar cambios en la amplitud de la malla.


3. Probar el fragment shader (evidencia)

- Qué comprobar: que el color cambia con la deformación.

- Cómo probar: crea regiones en la textura donde t sea alto (brillantes) y bajo (oscuras). Observa que las regiones con mayor vDisp tiñen la malla hacia naranja/rojo.

4. Probar la aplicación completa (evidencia RAE2)

Link: https://youtu.be/aLY3siKCVVs 