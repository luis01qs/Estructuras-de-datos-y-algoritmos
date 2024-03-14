# include "Tarea.hpp"

// Ejercicio 1
void ejercicio1(int &a)
{
    a = a*a;
    return;
}

// Ejercicio 2
int ejercicio2(int a)
{
    int res = a*a;
    return res;
}

// Ejercicio 3
int my_function(int *ptr)
{
    // Se le debe eliminar la sentencia const,
    // de lo contrario no te permite cambiar el valor.
    *ptr = *ptr + 10;
    return *ptr;
}

// Ejercicio 4
void ejercicio4()
{
    int a = 10;
    const int *ptr;
    ptr = &a;

    std::cout << *ptr << std::endl;
    a = 30;
    std::cout << *ptr << std::endl;
}

// Ejercicio 5
void ejercicio5()
{
    int *ptr = NULL;
    std::cout << ptr << std::endl;
}

// Ejercicio 6
void ejercicio6()
{
    std::cout << "Conviene cuando queremos generar estructuras finitas. Por ejemplo un árbol" << std::endl;
    std::cout << ", una lista enlazada o una cola, siempre que queramos conocer cuando termina una estructura" << std::endl;
}

// Ejercicio 7
void ejercicio7(int **matriz, int n)
{
    *matriz = new int[n];
    for(int i=0;i<n;++i)
    {
        matriz[i] = new int[n];
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i == j) matriz[i][j] = i;
            else matriz[i][j] = 0;
        }
    }
}

// Ejercicio 8
void ejercicio8()
{
    std::cout << "El operador de indirreción es (*), y se utiliza para retornar el valor que está" << std::endl;
    std::cout << "almacenado en la dirección de memoria que contiene el puntero" << std::endl;

    int *ptr;
    ptr = new int;
    *ptr = 20;

    std::cout << "El puntero apunta a un entero que almacena el valor 20, veamos: ";
    std::cout << *ptr << std::endl; 
}

// Ejercicio 9
void ejercicio9()
{
    int *ptr;
    ptr = new int;
    *ptr = 20;
    std::cout << "El puntero apunta a un entero que almacena el valor 20, veamos: ";
    std::cout << *ptr << std::endl; 
}

// Ejercicio 10
void ejercicio10()
{
    int a = 10, b = 20;
    std::cout << "Valores de a = 10 y b = 20" << std::endl;
    int *ptr;

    ptr = &a;
    std::cout << "Valor con puntero " << ptr << std::endl;

    ptr = &b;
    std::cout << "Valor con puntero " << ptr << std::endl;

}

// Ejercicio 11
void ejercicio11()
{
    std::cout << "La diferencia es que el primero retorna la dirección de memoria que almacena al puntero, " << std::endl;
    std::cout << "y el otro retorna la dirección de memoria que almacena el puntero" << std::endl;
}

// Ejercicio 12
void ejercicio12()
{
    std::cout << "Al primero le hace falta inicializar el puntero, es decir, pInt = new int" << std::endl;
    std::cout << "Al segundo le hace falta hacer *pVar = 9" << std::endl;
}

// Ejercicio 13
void ejercicio13()
{
    int m;
    int *mptr;
    m = 7;
    mptr = &m;
    std::cout << "Se imprime dirección de memoria de m y luego a donde apunta el puntero que almacena la dirección de memoria de m" << std::endl;
    std::cout << &m << " " << mptr << std::endl;

    std::cout << "Se cancelan los operadores, ya que se le pide el valor que almacena la dirección de memoria del puntero que almacena a m, es decir &m" << std::endl;
    std::cout << "En segundo, se le pide la dirección de memoria al valor que almacena la dirección de memoria de m, es decir &m" << std::endl;
    std::cout << *&mptr << " " << &*mptr << std::endl;
}