# include "My_Library.hpp"

// Intercambiar dos elementos
void N::swap(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

// Regresa el elemento más grande entre dos
int N::max(int &a, int &b)
{
    if(a >= b) return a;
    return b;
}

// Regresa el elemento más pequeño entre dos
int N::min(int &a, int &b)
{
    if(a <= b) return a;
    return b;
}