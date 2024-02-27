# include <iostream>
# include <vector>

class Spline
{
    private:
        int p, n, m;
        std::vector<long double> x, xp, yp;
        std::vector<std::vector<long double>> b;

    public:
        void Intialize();
        void Evaluate();
        long double Calculate(long double &a);
        void Print();
        void Print2();
};

int main()
{
    freopen("datos.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    Spline spline;
    spline.Intialize();
    spline.Evaluate();
    spline.Print2();

    return 0;
}

void Spline::Intialize()
{
    std::cin >> n;
    ++n;

    x.resize(n);

    for(int i=0;i<n;++i)
    {
        std::cin >> x[i];
    }

    std::cin >> m;
    xp.resize(m);
    yp.resize(m, 0);

    for(int i=0;i<m;++i)
    {
        std::cin >> xp[i];
    }

    std::cin >> p;

    //std::cout << p << std::endl;

    b.resize(n, std::vector<long double>(p, 0));
}

void Spline::Evaluate()
{
    for(int i=0;i<m;++i)
    {
        yp[i] = Calculate(xp[i]);
    }
}

long double Spline::Calculate(long double &a)
{
    long double res = 0;
    for(int i=0;i<n-1;++i)
    {
        if(a >= x[i] && a < x[i+1]) b[i][0] = 1;
        else b[i][0] = 0;
    }

    for(int k=1;k<p;++k)
    {
        for(int i=0;i+k+1<n;++i)
        {
            b[i][k] = b[i][k-1]*(a-x[i])/(x[i+k]-x[i]) + b[i+1][k-1]*(x[i+k+1]-a)/(x[i+k+1]-x[i+1]);
            //std::cout << i << " " << k << std::endl;
        }
    }

    res = b[n/2][p-1];

    return res;
}

void Spline::Print()
{
    for(auto &e:b)
    {
        for(auto &u:e) std::cout << u << " ";
        std::cout << std::endl;
    }
}

void Spline::Print2()
{
    for(int i=0;i<m;++i)
    {
        std::cout << xp[i] << " " << yp[i] << std::endl;
    }
}