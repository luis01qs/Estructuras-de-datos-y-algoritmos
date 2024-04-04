# include <bits/stdc++.h>
# define nl '\n'

using namespace std;
using ld = long double;

ld f(ld x)
{
    // Definir función a integrar
    return x*log(x+1);
}

int main()
{
    // Definir límites de la integral
    ld a = -0.5, b = 0; 

    // Definimos h
    ld h = (b - a) / 4;

    ld res = 4*h/3 * (2*f(a+h) - f(a + 2*h) + 2*f(a + 3*h));

    cout << res << nl;

    return 0;
}