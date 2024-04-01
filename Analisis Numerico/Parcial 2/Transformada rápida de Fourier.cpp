# include <bits/stdc++.h>
# define nl '\n'

using namespace std;
using ld = long double;

void descomponer(int K, int p, int q, int &K2)
{
    vector<int> b;
    while (K > 0)
    {
        b.push_back(K % 2);
        K /= 2;
    }

    cout << b.size() << nl;

    for(int i=0;i+q<=p;++i)
    {
        cout << q+i << nl;
        K2 += b[q+i] * pow(2, p-i);
    }
}

void descomponer2(int K, int &j, int &p)
{
    vector<int> b;
    while (K > 0)
    {
        b.push_back(K % 2);
        K /= 2;
    }

    j = 0;
    for(int i=0;i<=p;++i)
    {
        j += b[i] * pow(2, p-i);
    }
}

void Transformada_Rapida_Fourier(int &p, int &m, vector<ld> &y, vector<complex<ld>> &c, vector<ld>  &a, vector<ld> &b)
{
    int M = m;
    int q = p;

    complex<ld> zeta = exp(complex<ld>(0, M_PI/m));
    vector<complex<ld>> xi(2*m+1); 

    for(int j=0;j<2*m;++j)
    {
        c[j].real(y[j]);
    }

    for(int j=1;j<=M;++j)
    {
        xi[j] = pow(zeta, j);
        xi[j+M] = -xi[j];
    }

    int K = 0;
    xi[0] = {0,0};

    for(int L=1;L<=p+1;++L)
    {
        while(K < 2*m - 1)
        {
            for(int j=1;j<=M;++j)
            {
                int K2;
                descomponer(K, p, q, K2);
                complex<ld> eta = c[K + M] * xi[K2];
                c[K + M] = c[K] - eta;
                c[K] += eta;
                ++K;
            }
            K += M;
        }
        K = 0;
        M /= 2;
        --q;
    }

    K = 0;
    while(K < 2*m-1)
    {
        int j = 0;
        descomponer2(K, j, p);
        if(j > K) swap(c[j], c[K]); 
        ++K;
    }

    a[0] = real(c[0]) / m;
    complex<ld> aux = exp(complex<ld>(0, -m*M_PI) * c[m] / complex<ld>(m, 0));
    a[m] = real(aux);

    for(int j=1;j<m;++j)
    {
        aux = exp(complex<ld>(0, -j*M_PI) * c[j] / complex<ld>(m, 0));
        a[j] = real(aux);
        b[j] = imag(aux);
    }
}

ld f(ld &x)
{
    return 2*x*x - 9;
}

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

int main()
{
    //freopen("prueba.txt", "w", stdout);
    int p = 1;
    int m = (1 << p);

    vector<ld> y(2*m);
    ld x;

    for(int j=0;j<2*m;++j)
    {
        x = j*(M_PI)/m - M_PI;
        y[j] = f(x);
    }

    vector<ld> a(m+1, 0), b(m+1, 0);
    vector<complex<ld>> c(2*m, {0,0});

    Transformada_Rapida_Fourier(p, m, y, c, a, b);

    for(ld i=-M_PI;i<=M_PI;i+=ld(0.01))
    {
        cout << i << " ";
        cout << evalucion(a, b, i) << " " << f(i) << nl;
    }

    return 0;
}