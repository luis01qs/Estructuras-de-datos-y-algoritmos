# include <bits/stdc++.h>
# define nl '\n'

using namespace std;
using ld = long double;

ld f(ld x)
{
    // Definir función a integrar
    return pow(sin(x), 2) - 2*x*sin(x) + 1;
}

int main()
{
    // Definir límites de la integral
    ld a = 0.75, b = 1.3; 

    // Definimos h
    ld h = (b - a) / 2;

    ld res = h/3 * (f(a) + 4*f(a + h) + f(b));

    cout << res << nl;

    return 0;
}