# include <bits/stdc++.h>

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
    return 2*x*x-9;
}

int main()
{
    //freopen("prueba.txt", "w", stdout);
    int m = 3;
    int n = 2;

    vector<ld> x(2*m);
    vector<ld> y(2*m);
    for(int i=0;i<2*m;++i)
    {
        x[i] = -M_PI + (ld(i)/m)*M_PI;
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

    for(ld i = -M_PI;i<= M_PI;i += (ld)0.001)
    {
        //cout << i << " " << f(i) << " " << f(i) << endl;
        //cout << i << " " << evalucion(a, b, i) << " " << f(i) << endl;
    }

    
}