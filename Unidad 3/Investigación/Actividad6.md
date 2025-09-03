# Actividad 6

El problema es que no hay mouseReleased, cuando seleccionas una esfera con mousePressed la variable selectedSphere queda apuntando a ella para siempre.
Se soluciona con un mouseReleased para soltar la esfera.