# include <bits/stdc++.h>
# define nl '\n'

using namespace std;
using ld = long double;

ld f(ld x)
{
    // Definir función a integrar
    return 1/sqrt(x*x-4);
}

int main()
{
    // Definir límites de la integral
    ld a = 3, b = 5; 

    // Definimos h
    ld h = (b - a) / 3;

    ld res = 3*h/8 * (f(a) + 3*f(a + h) + 3*f(a + 2*h) + f(a + 3*h));

    cout << res << nl;

    return 0;
}