# include <bits/stdc++.h>
# define nl '\n'

using namespace std;
using ld = long double;

ld f(ld x)
{
    // Definir función a integrar
    return 1/(x * log(x));
}

int main()
{
    // Definir límites de la integral
    ld a = exp(1), b = exp(1) + 1; 

    // Definimos h
    ld h = b - a;

    ld res = h/2 * (f(a) + f(b));

    cout << res << nl;

    return 0;
}