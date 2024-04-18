# include <bits/stdc++.h>
# define nl '\n'

using namespace std;
using ld = long double;

ld f(ld x, ld y)
{
    return log(x + 2*y);
}

int main()
{
    int n, m;
    n = 4;
    m = 4;

    ld a = 1.4, b = 2;
    ld c = 1, d = 1.5;

    ld h = (b-a)/n;
    ld k = (d-c)/m;

    ld res = 0;
    ld aux;
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            aux = f(a + i*h, c + j*k);

            if((i == 0 || i == n) && (j == 0 || j == m))
            {
                res += aux;
                continue;
            }

            if((i + j) % 2 == 0)
            {
                if(i%2 == 0) res += 4*aux;
                else res += 16*aux;
            }
            else res += 8*aux;
        }
    }

    res *= (k*h)/9;
    cout << res << nl;

    return 0;
}