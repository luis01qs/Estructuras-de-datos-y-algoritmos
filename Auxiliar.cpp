# include "My_Library.hpp"

void N::swap(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

int N::max(int &a, int &b)
{
    if(a >= b) return a;
    return b;
}

int N::min(int &a, int &b)
{
    if(a <= b) return a;
    return b;
}