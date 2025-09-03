# Actividad 5


- ¿Cuál es la definición de un puntero?

Un puntero es una variable que almacena la dirección de memoria de otra variable

- ¿Dónde está el puntero?

vector<Sphere*> spheres;
Sphere* selectedSphere;

- ¿Cómo se inicializa el puntero?

En el setup()
spheres.push_back(new Sphere(x, y, radius));
selectedSphere = nullptr;

- ¿Para qué se está usando el puntero?

Para seleccionar una esfera específica y moverla.

- ¿Qué es exactamente lo que está almacenado en el puntero?

La dirección de memoría de la esfera