#include <iostream>
#include <fstream>
#define MAXSIZE 128

void acumular(float& a, float b) {
    a += b;
}

int main(int argc, char** argv)
{

    float valor = 0;
    int num_valores= 0;

    std::cout << "Leyendo archivo" << std::endl;

    std::ifstream file;
    file.open("datos.txt", std::ifstream::in);

    if (file.is_open()) {
        std::cout << "archivo abierto\n";

        char buffer[MAXSIZE];

        while (!file.eof()) {
            file.getline(buffer, MAXSIZE);
            acumular(valor, atof(buffer));

            std::cout << "Valor acumulado:" << valor << std::endl;
            num_valores++;
        }
        valor /= num_valores;

        std::ofstream file_o("datos.txt", std::ofstream::app);
        file_o << "\npromedio: " << valor << std::endl;
    }

    else {
        std::cout << "no se encuentra el archivo\n";
    }
}
