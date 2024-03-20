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

// Raíz cuadrada
long double N::raiz_cuadrada(long double l, long double r, long double &x)
{
    // Comprobamos error
    if((r-l) < 0.00001) return (l+r)/2;

    // Calculamos el punto medio
    long double m = (l + r)/2;

    // Dividimos el intervalo de búsqueda en dos
    if(m*m < x) return N::raiz_cuadrada(m, r, x);
    return N::raiz_cuadrada(l, m, x);
}

