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
    freopen("salida.txt", "w", stdout);
    ld a = 3, b = 5;
    ld h = b - a;
    int n = 16;

    vector<vector<ld>> R(n+1, vector<ld>(n+1, 0));
    R[1][1] = h*(f(a) + f(b)) / 2;

    cout << fixed << setprecision(5);

    ld suma;
    for(int i=2;i<n+1;++i)
    {
        suma = 0;
        for(ld k=1;k<=pow(2, i-2);++k)
        {
            suma += f(a+(k-0.5)*h);
        }

        R[i][1] = 0.5 * (R[i-1][1] + h*suma);

        for(int j=2;j<=i;++j)
        {
            R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1])/(pow(4, j-1) - 1);
        }

        h /= 2;
    }

    for(auto &e:R)
    {
        for(auto &u:e) cout << u << " ";
        cout << nl;
    }

    return 0;
}