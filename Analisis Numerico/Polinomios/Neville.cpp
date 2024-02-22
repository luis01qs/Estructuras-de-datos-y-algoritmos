# include <iostream>
# include <vector>

class Polynomial
{
    private:
        int n, m;
        std::vector<long double> x, y, xp, yp;
        std::vector<std::vector<long double>> p;

    public:
        void Initialize();
        void Calculate();
        void Evaluate(int &a);
        void Print();
};

int main()
{
    freopen("datos.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    Polynomial pol;
    pol.Initialize();
    pol.Calculate();
    pol.Print();
    return 0;
}

void Polynomial::Initialize()
{
    std::cin >> n;
    ++n;

    x.resize(n, 0);
    y.resize(n, 0);
    p.resize(n, std::vector<long double>(n, 0));

    for(int i=0;i<n;++i)
    {
        std::cin >> x[i] >> y[i];
    }

    for(int i=0;i<n;++i)
    {
        std::cout << x[i] << " -> " << y[i] << std::endl;
    }

    std::cin >> m;

    xp.resize(m, 0);
    yp.resize(m, 0);

    for(int i=0;i<m;++i)
    {
        std::cin >> xp[i];
    }
}

void Polynomial::Evaluate(int &a)
{
    for(int i=0;i<n;++i) p[i][i] = y[i];

    for(int j=1;j<n;++j)
    {
        for(int i=0;i+j<n;++i)
        {
            p[i][j+i] = ((xp[a] - x[i])*p[i+1][j+i]+(x[j+i] - xp[a])*p[i][j+i-1])/(x[j+i] - x[i]);
        }
    }
    yp[a] = p[0][n-1];
}

void Polynomial::Calculate()
{
    for(int i=0;i<m;++i)
    {
        Evaluate(i);
    }
}

void Polynomial::Print()
{
    for(int i=0;i<m;++i)
    {
        std::cout << xp[i] << " -> " << yp[i] << std::endl;
    }
}