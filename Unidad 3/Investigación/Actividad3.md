# Actividad 3

### Explica el cambio que hiciste

Antes del cambio las partículas que seguían al cursor eran de forma circular, pero al generar el cambio, estas se transforma planos, básicamente cuadrados. En el código original solo hubo un cambio en la línea “ofDrawCircle(pos.x, pos.y, 50);”, la cual dibuja un círculo en la posición obtenida del cursor con un radio de 50. Toda la anterior línea se cambió por “ofDrawPlane(pos.x, pos.y, 30, 30);”, la cual dibuja un plano en la posición obtenida del cursor por medio de un vector, y le da la altura de 30 y el ancho de 30. 
