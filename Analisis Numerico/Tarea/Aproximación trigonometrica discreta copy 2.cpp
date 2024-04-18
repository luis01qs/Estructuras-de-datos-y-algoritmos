# include <bits/stdc++.h>
# define nl '\n'

using namespace std;
using ld = long double;

ld evalucion(vector<ld> &a, vector<ld> &b, ld &x)
{
    ld res = 0;

    int k = 0;
    for(auto &e:a)
    {
        res += e*cos(k*x);
        ++k;
    }

    k = 0;
    for(auto &e:b)
    {
        res += e*sin(k*x);
        ++k;
    }

    res -= a[0]/2;

    return res;
}

ld f(long double &x)
{
    ld res = 1.3029*pow(x, 0.575641);
    return res;
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int N;
    cin>>N;

    int m = 3;
    int n = 2;

    ld li = 0, ls = 7;

    vector<ld> x(2*m);
    vector<ld> y(2*m);
    for(int i=0;i<2*m;++i)
    {
        x[i] = -1 + (ld(i)/m);
        x[i] = 0.5*((ls-li) * x[i] + li + ls);
        y[i] = f(x[i]);
    }

    vector<ld> a(n+1, 0), b(n, 0);
    for(int k=0;k<n+1;++k)
    {
        // Calculo de a[k]
        for(int j=0;j<2*m;++j) a[k] += y[j]*cos(k*x[j]);
        a[k] /= m;

        if(k == 0 || k == n) continue;

        // Calculo de b[k]
        for(int j=0;j<2*m;++j) b[k] += y[j]*sin(k*x[j]);
        b[k] /= m;
    }

    for(auto &e:a) cout << e << " ";
    cout << endl;

    for(auto &e:b) cout << e << " ";
    cout << endl;

    for(ld i = li;i<= ls;i+=(ld)0.01)
    {
        //cout << i << " " << f(i) << " " << f(i) << endl;
        cout << i << " " << evalucion(a, b, i) << " " << f(i) << endl;
    }

    //ld res = 0;
    ld X, Y;
    for(int i=0;i<N;++i)
    {
        cin>>X>>Y;
        //res += pow((Y - evalucion(a, b, X)), 2);
    }

    //cout << res << endl;
}