# include "My_Library.hpp"

// Mínimo común divisor
int N::mcd(int &x, int &y)
{
    // Caso base
    if(y == 0) return x;

    // Algoritmo de Euclides
    x = x % y;

    // Llamada recursiva
    return mcd(y, x);
}

// Factorial
int N::factorial(int n)
{
    // Caso base
    if(n == 0) return 1;

    // Llamada recursiva
    return n*factorial(n-1);
}

