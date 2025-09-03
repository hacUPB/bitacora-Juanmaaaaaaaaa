# Actividad 9

- ¿Qué sucede cuando presionas la tecla “f”?

Si heapObjects no está vacío, se toma el último puntero, se ejecuta delete sobre esa dirección, y luego pop_back() remueve el puntero del vector. Lo que provoca que el objeto se destruya.

- Analiza detalladamente esta parte del código:

1. Delete debe aplicarse solo a punteros que fueron asignados con new.
2. Después de delete, la dirección en memoria queda inválida, pues se necesita un pop.back().
