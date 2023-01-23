#include <iostream>
#include <fstream>
#define MAXSIZE 128

void acumular(float& num, float valor) {
    num += valor;
}

int main(int argc, char** argv)
{
    std::cout << "Leyendo archivo" << std::endl;

    std::ifstream file;
    file.open("datos.txt", std::ifstream::in);

    if (file.is_open()) {
        std::cout << "archivo abierto\n";

        char buffer[MAXSIZE];

        while (!file.eof()) {
            file.getline(buffer, MAXSIZE);
            std::cout << buffer << std::endl;
        }
    }

    else {
        std::cout << "no se encuentra el archivo\n";
    }

    if (argc <= 1) return 0;

    float suma = 0;
    std::cout << "argc:" << argc << std::endl;

    for (int i = 1; i < argc; i++) {
        std::cout << argv[i] << std::endl;
        acumular(suma, atoi(argv[i]));
    }

    float promedio = suma / (argc - 1);
    std::cout << "Promedio" << promedio << std::endl;
    return 0;


}
