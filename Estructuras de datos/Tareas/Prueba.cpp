# include "Tarea.hpp"

int main()
{
    freopen("resultados.txt", "w", stdout);

    // Ejercicio 1
    std::cout << "Ejercicio 1" << std::endl;
    int a = 10;
    ejercicio1(a);
    std::cout << "El cuadrado de 10 usando referencia es: ";
    std::cout << a << std::endl;
    std::cout << std::endl;

    // Ejercicio 2
    std::cout << "Ejercicio 2" << std::endl;
    a = 10;
    std::cout << "El cuadrado de 10 usando retorno de función es: ";
    std::cout << ejercicio2(a) << std::endl;
    std::cout << std::endl;

    // Ejercicio 3
    std::cout << "Ejercicio 3" << std::endl;
    int *ptr;
    ptr = new int;
    *ptr = 10;
    std::cout << "Pasando un puntero con valor inicial *ptr = 10 y en la función sumarle 10 resulta: ";
    std::cout << my_function(ptr) << std::endl;
    std::cout << std::endl;

    // Ejercicio 4
    std::cout << "Ejercicio 4" << std::endl;
    std::cout << "En este programa se crea puntero constante a variable no constante" << std::endl;
    std::cout << "Se aclara que lo constante es a donde apunta, más no el valor de la posición de memoria que almacena" << std::endl;
    ejercicio4();
    std::cout << std::endl;

    // Ejercicio 5
    std::cout << "Ejercicio 5" << std::endl;
    std::cout << "Imprimiendo dirección de memoria que apunta puntero nulo: ";
    ejercicio5();
    std::cout << std::endl;

    // Ejercicio 6
    std::cout << "Ejercicio 6" << std::endl;
    ejercicio6();
    std::cout << std::endl;

    // Ejercicio 7
    std::cout << "Ejercicio 7" << std::endl;
    int n = 10;
    int **matriz;
    ejercicio7(matriz, n);
    std::cout << "Matriz diagonal de tamaño n = 10: " << std::endl;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j) std::cout << matriz[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Ejercicio 8
    std::cout << "Ejercicio 8" << std::endl;
    ejercicio8();
    std::cout << std::endl;

    // Ejercicio 9
    std::cout << "Ejercicio 9" << std::endl;
    ejercicio9();
    std::cout << std::endl;

    // Ejercicio 10
    std::cout << "Ejercicio 10" << std::endl;
    ejercicio10();
    std::cout << std::endl;

    // Ejercicio 11
    std::cout << "Ejercicio 11" << std::endl;
    ejercicio11();
    std::cout << std::endl;

    // Ejercicio 12
    std::cout << "Ejercicio 12" << std::endl;
    ejercicio12();
    std::cout << std::endl;

    // Ejercicio 13
    std::cout << "Ejercicio 13" << std::endl;
    ejercicio13();
    std::cout << std::endl;

}