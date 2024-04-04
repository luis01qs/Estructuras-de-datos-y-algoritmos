# include <bits/stdc++.h>

using namespace std;

class Polynomial
{
    private:
        int n;
        std::vector<long double> x, y;
        std::vector<std::vector<long double>> c;
        long double promedio, maximo;

    public:
        void Initialize();
        void Divided_Differences();
        void Print_Coeficients();
};

double absoluto(double &a);

int main()
{
    //freopen("salida.txt", "w", stdout);
    Polynomial pol;
    pol.Initialize();
    pol.Divided_Differences();
    pol.Print_Coeficients();

    return 0;
}

void Polynomial::Initialize()
{
    n = 3;

    x.resize(n, 0);
    y.resize(n, 0);
    c.resize(n, std::vector<long double>(n, 0));

    for(int i=1;i<n+1;++i)
    {
        x[i-1] = cos(M_PI*(2*i-1)/(2*n));
        y[i-1] = cos(x[i-1]);
    }
}

void Polynomial::Divided_Differences()
{
    for(int i=0;i<n;++i)
    {
        c[i][0] = y[i];
    }

    for(int j=1;j<n;++j)
    {
        for(int i=0;i<n-j;++i)
        {
            c[i][j] = (c[i+1][j-1]-c[i][j-1])/(x[i+j]-x[i]);
        }
    }
}

void Polynomial::Print_Coeficients()
{
    for(int i=0;i<n;++i)
    {
        std::cout << c[0][i] << " ";
    }
    std::cout << std::endl;

    for(int i=0;i<n;++i)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}