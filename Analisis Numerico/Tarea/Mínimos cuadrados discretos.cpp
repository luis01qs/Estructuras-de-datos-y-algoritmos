# include <bits/stdc++.h>

using namespace std;
using ld = long double;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    int n;
    cin>>n;

    vector<ld> x(n), y(n);
    for(int i=0;i<n;++i)
    {
        cin>>x[i]>>y[i];
    }

    vector<ld> xy(n), xx(n);
    ld sxy = 0, sxx = 0, sx = 0, sy = 0;
    ld maximo = x[0], minimo = x[0];
    for(int i=0;i<n;++i)
    {
        maximo = max(maximo, x[i]);
        minimo = min(minimo, x[i]);

        xy[i] = x[i]*y[i];
        xx[i] = x[i]*x[i];

        sx += x[i];
        sy += y[i];
        sxy += xy[i];
        sxx += xx[i];
    }

    ld a0 = (sxx*sy - sx*sxy)/(n*sxx - sx*sx);
    ld a1 = (n*sxy - sx*sy)/(n*sxx - sx*sx);

    cout << a0 << " " << a1 << endl;
    cout << minimo << " " << maximo << endl;

    for(int i=0;i<n;++i)
    {
        cout << x[i] << " " << y[i] << endl;
    }

    return 0;
}