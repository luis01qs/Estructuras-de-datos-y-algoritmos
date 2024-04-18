# include <bits/stdc++.h>
# define nl '\n'

using namespace std;
using ld = long double;

ld f(ld x)
{
    // Definir función a integrar
    return 1/sqrt(x*x-4);
}

ld trapecio(ld &a, ld &b, ld &n)
{
    ld res = f(a);
    ld h = (b - a) / n;
    for(int i=1;i<n;++i)
    {
        res += 2*f(a + i*h);
    }
    res += f(b);

    res *= h/2;
    return res;
}

ld simpson(ld &a, ld &b, int n)
{
    ld res = 0;
    ld h = (b-a)/ld(n);

    res += f(a);
    for(int i=1;i<=(n/2 - 1);++i)
    {
        res += 2*f(a + 2*i*h);
    }

    for(int i=1;i<=n/2;++i)
    {
        res += 4*f(a + (2*i - 1)*h);
    }
    res += f(b);

    res *= h/3;
    return res;
}

ld midpoint(ld &a, ld &b, ld &h)
{
    ld res = 0;
    int n = (b - a)/h - 2;

    for(int i=0;i<=(n/2);++i)
    {
        res += f(a + (2*i + 1)*h);
    }

    res *= 2*h;
    return res;
}

int main()
{
    ld a = 3, b = 5;
    ld n = 30;

    cout << fixed << setprecision(10);
    //cout << trapecio(a, b, n) << nl;
    cout << simpson(a, b, n) << nl;
    //cout << midpoint(a, b, h) << nl;

    return 0;
}