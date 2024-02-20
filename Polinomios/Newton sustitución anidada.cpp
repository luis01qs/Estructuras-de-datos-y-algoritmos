# include <iostream>
# include <vector>

class Polynomial
{
    private:
        int n, m;
        std::vector<long double> x, y, xp, yp;
        std::vector<std::vector<long double>> c;

    public:
        void Initialize();
        void Divided_Differences();
        void Evaluate();
        void Print_Evaluations();
        void Print_Coeficients();
};

double absoluto(double &a);

int main()
{
    freopen("datos.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    Polynomial pol;
    pol.Initialize();
    pol.Divided_Differences();
    pol.Evaluate();
    pol.Print_Evaluations();
    //pol.Print_Coeficients();

    return 0;
}

void Polynomial::Initialize()
{
    std::cin >> n;
    n++;

    x.resize(n, 0);
    y.resize(n, 0);
    c.resize(n, std::vector<long double>(n, 0));

    for(int i=0;i<n;++i)
    {
        std::cin >> x[i] >> y[i];
    }

    std::cin >> m;

    xp.resize(m, 0);
    yp.resize(m, 0);

    for(int i=0;i<m;++i)
    {
        std::cin >> xp[i];
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

void Polynomial::Evaluate()
{
    for(int k=0;k<m;++k)
    {
        yp[k] = c[0][n-1];
        for(int i=n-2;i>=0;--i)
        {
            yp[k] = yp[k]*(xp[k]-x[i]) + c[0][i];
        }
    }
}

void Polynomial::Print_Evaluations()
{
    double error = 0;
    double eva, e;
    for(int i=0;i<m;++i)
    {
        eva = double(1)/(1+xp[i]*xp[i]);
        std::cout << "Punto " << i+1 << std::endl;
        std::cout << "f(" << xp[i] << ") = " << eva << std::endl;
        std::cout << "p(" << xp[i] << ") = " << yp[i] << std::endl;
        std::cout << std::endl;
        e = eva - yp[i];
        error += (absoluto(e));
    }

    std::cout << "Error total: " << error << std::endl; 
}

void Polynomial::Print_Coeficients()
{
    for(int i=0;i<n;++i)
    {
        std::cout << c[0][i] << " ";
    }
    std::cout << std::endl;
}

double absoluto(double &a)
{
    if(a < 0) return -a;
    return a;
}

