# include <iostream>
# include <vector>

class Polynomial
{
    private:
        int n, m;
        std::vector<long double> x, y, xp, yp;

    public:
        void Initialize();
        void Evaluate();
        void Print();
};

int main()
{
    freopen("datos.txt", "r", stdin);

    Polynomial pol;
    pol.Initialize();
    pol.Evaluate();
    pol.Print();
    return 0;
}

void Polynomial::Initialize()
{
    std::cin >> n;

    x.resize(n, 0);
    y.resize(n, 0);

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

void Polynomial::Evaluate()
{
    long double p;
    for(int k=0;k<m;++k)
    {
        for(int i=0;i<n;++i)
        {
            p = 1;
            for(int j=0;j<n;++j)
            {
                if(i != j) p *= (xp[k] - x[j])/(x[i] - x[j]);
            }

            yp[k] += p * y[i];
        }
    }
}

void Polynomial::Print()
{
    for(int i=0;i<m;++i)
    {
        std::cout << xp[i] << ", " << yp[i] << std::endl;
    }
}
