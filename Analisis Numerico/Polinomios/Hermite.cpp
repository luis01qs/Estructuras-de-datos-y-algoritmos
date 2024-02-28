# include <iostream>
# include <vector>

class Polynomial
{
    private:
        int n, m;
        std::vector<long double> x, y, d,  xp, yp;
        std::vector<std::vector<long double>> c;
        long double promedio, maximo;

    public:
        void Initialize();
        void Divided_Differences();
        void Evaluate();
        void Print_Evaluations();
        void Print_Coeficients();
        void Print_Problema();
        void Promedio();
        void Maximo();
};

double absoluto(double &a);

int main()
{
    freopen("datos.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    Polynomial pol;
    pol.Initialize();
    pol.Divided_Differences();
    pol.Evaluate();
    //pol.Promedio();
    //pol.Maximo();
    pol.Print_Evaluations();
    pol.Print_Coeficients();
    //pol.Print_Problema();

    return 0;
}

void Polynomial::Initialize()
{
    std::cin >> n;
    ++n;
    n = 2*n;

    x.resize(n, 0);
    y.resize(n, 0);
    d.resize(n, 100000);
    c.resize(n, std::vector<long double>(n, 100000));

    for(int i=0;i<n;i++)
    {
        std::cin >> x[i] >> y[i] >> d[i];
        i++;
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
        c[i][1] = d[i];
    }

    //Print_Coeficients();
    std::cout << std::endl;

    for(int j=1;j<n;++j)
    {
        for(int i=0;i<n-j;++i)
        {
            if(c[i][j] != 100000) continue;
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
    //double error = 0;
    //double eva, e;
    for(int i=0;i<m;++i)
    {
        //eva = double(1)/(1+xp[i]*xp[i]);
        //std::cout << "Punto " << i+1 << std::endl;
        //std::cout << "f(" << xp[i] << ") = " << eva << std::endl;
        std::cout << xp[i] << " " << (yp[i+1] - yp[i])/(xp[i+1] - xp[i]) << std::endl;
        //std::cout << std::endl;
        //e = eva - yp[i];
        //error += (absoluto(e));
    }

    //std::cout << "Error total: " << error << std::endl;
}

void Polynomial::Print_Coeficients()
{
    for(int i=0;i<n;++i)
    {
        //std::cout << c[0][i] << " ";
    }
    //std::cout << std::endl;

    for(auto &e:c)
    {
        for(auto &u:e) std::cout << u << " ";
        std::cout << std::endl;
    }
}

double absoluto(double &a)
{
    if(a < 0) return -a;
    return a;
}

void Polynomial::Print_Problema()
{
    std::cout << n << std::endl;
    for(int i=0;i<n;++i)
    {
        std::cout << x[i] << " " << y[i] << std::endl;
    }

    std::cout << m << std::endl;
    for(int i=0;i<m;++i)
    {
        std::cout << xp[i] << std::endl;
    }
}

void Polynomial::Promedio()
{
    promedio = 0;
    for(int i=0;i<m;++i)
    {
        promedio += yp[i];
    }

    promedio = promedio / m;

    std::cout << "El promedio del polinomio es aproximadamente: " << promedio << std::endl;
}

void Polynomial::Maximo()
{
    maximo = 0;
    long double pos = 0;
    for(int i=0;i<m;++i)
    {
        if(maximo < yp[i])
        {
            maximo = yp[i];
            pos = xp[i];
        }
    }

    std::cout << "El máximo del polinomio es de aproximadamente: " << maximo <<  " alcanzado en el día: " << pos << std::endl;
}
