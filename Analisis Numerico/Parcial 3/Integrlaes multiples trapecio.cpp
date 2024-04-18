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
    n = 2;
    m = 2;

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

            if(i == 0 || i == n)
            {
                if(j == 0 || j == m)
                {
                    res += aux;
                    continue;
                }

                res += 2*aux;
                continue;
            }

            if(j == 0 || j == m)
            {
                res += 2*aux;
                continue;
            }

            res += 4*aux;
        }
    }

    res *= (h*k)/4;
    cout << res << nl;

    return 0;
}