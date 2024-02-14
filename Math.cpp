# include "My_Library.hpp"

int N::mcd(int &x, int &y)
{
    if(y == 0) return x;
    x = x % y;
    return mcd(y, x);
}

int N::factorial(int n)
{
    if(n == 0) return 1;
    return n*factorial(n-1);
}

