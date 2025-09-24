#include <iostream>

class Particle {
public:
    float x, y;
    void move(float dx, float dy) {
        x += dx;
        y += dy;
    }
};

int main() {
    Particle p1;
    Particle p2;

    // Mostrar direcciones de los objetos
    std::cout << "Dirección de p1: " << &p1 << std::endl;
    std::cout << "Dirección de p2: " << &p2 << std::endl;

    // Mostrar tamaño del objeto
    std::cout << "Tamaño de Particle: " << sizeof(Particle) << " bytes" << std::endl;

    // Mostrar direcciones de atributos de p1
    std::cout << "Dirección de p1.x: " << &(p1.x) << std::endl;
    std::cout << "Dirección de p1.y: " << &(p1.y) << std::endl;

    // Mostrar direcciones de atributos de p2
    std::cout << "Dirección de p2.x: " << &(p2.x) << std::endl;
    std::cout << "Dirección de p2.y: " << &(p2.y) << std::endl;

    return 0;
}
