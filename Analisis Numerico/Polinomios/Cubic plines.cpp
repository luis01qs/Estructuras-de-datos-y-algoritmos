# include <iostream>
# include <vector>
# include <iomanip>

class Polynomial
{
    private:
        int n, m;
        std::vector<long double> x, y, alpha, h, a, b, c, d, xp, yp, l, mu, z;
        long double FPO, FPN;

    public:
        void Intialize();
        void Calculate_Natural();
        void Calculate_Clamped();
        void Print_Coefficients();
        void Evaluate();
        void Print_Results();
};

void p(std::vector<long double> &a)
{
       for(auto &e:a) std::cout << e << " ";
       std::cout << std::endl;
}

int main()
{
    freopen("datos.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    Polynomial pol;
    pol.Intialize();
    //pol.Calculate_Natural();
    pol.Calculate_Clamped();
    //pol.Print_Coefficients();
    pol.Evaluate();
    pol.Print_Results();

    return 0;
}

void Polynomial::Intialize()
{
    std::cin >> n;
    ++n;
    
    x.resize(n, 0);
    y.resize(n, 0);
    alpha.resize(n, 0);
    h.resize(n, 0);
    a.resize(n, 0);
    b.resize(n, 0);
    c.resize(n, 0);
    d.resize(n, 0);
    l.resize(n, 0);
    mu.resize(n, 0);
    z.resize(n, 0);

    for(int i=0;i<n;++i)
    {
        std::cin >> x[i] >> y[i];
    }

    std::cin >> FPO >> FPN;

    a = y;

    std::cin >> m;
    xp.resize(m);
    yp.resize(m, 0);

    for(int i=0;i<m;++i) std::cin >> xp[i];
}

void Polynomial::Calculate_Natural()
{
    for(int i=0;i<n-1;++i)
    {
        h[i] = x[i+1]-x[i];
    }

    for(int i=1;i<n-1;++i)
    {
        alpha[i] = 3/h[i]*(a[i+1]-a[i]) - 3/h[i-1]*(a[i]-a[i-1]);
    }

    l[0] = 1;

    for(int i=1;i<n-1;++i)
    {
        l[i] = 2*(x[i+1]-x[i-1])-h[i-1]*mu[i-1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i-1]*z[i-1]) / l[i];
    }

    l[n-1] = 1;

    std::cout << std::fixed << std::showpoint << std::setprecision(12);

    for(int i=n-2;i>=0;--i)
    {
        c[i] = z[i]-mu[i]*c[i+1];
        b[i] = (a[i+1]-a[i])/h[i] - h[i]*(c[i+1]+2*c[i])/3;
        d[i] = (c[i+1]-c[i])/(3*h[i]);
    }
}

void Polynomial::Calculate_Clamped()
{
    for(int i=0;i<n-1;++i)
    {
        h[i] = x[i+1] - x[i];
    }

    alpha[0] = 3*(a[1] - a[0])/h[0] - 3*FPO;
    alpha[n-1] = 3*FPN - 3*(a[n-1] - a[n-2])/h[n-2];

    for(int i=1;i<n-1;++i)
    {
        alpha[i] = 3/h[i]*(a[i+1]-a[i]) - 3/h[i-1]*(a[i]-a[i-1]);
    }

    l[0] = 2*h[0];
    mu[0] = 0.5;
    z[0] = alpha[0] / l[0];

    for(int i=1;i<n-1;++i)
    {
        l[i] = 2*(x[i+1]-x[i-1])-h[i-1]*mu[i-1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i-1]*z[i-1]) / l[i];
    }

    l[n-1] = h[n-2]*(2-mu[n-2]);
    z[n-1] = (alpha[n-1] - h[n-2]*z[n-2]) / l[n-1];
    c[n-1] = z[n-1];

    for(int i=n-2;i>=0;--i)
    {
        c[i] = z[i]-mu[i]*c[i+1];
        b[i] = (a[i+1]-a[i])/h[i] - h[i]*(c[i+1]+2*c[i])/3;
        d[i] = (c[i+1]-c[i])/(3*h[i]);
    }
}

void Polynomial::Print_Coefficients()
{
    for(int i=0;i<n-1;++i)
    {
        std::cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << std::endl;
    }
}

void Polynomial::Evaluate()
{
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n-1;++j)
        {
            if(xp[i] <= x[j+1] && xp[i] >= x[j])
            {
                yp[i] = a[j] + b[j]*(xp[i]-x[j]) + c[j]*(xp[i]-x[j])*(xp[i]-x[j]) + d[j]*(xp[i]-x[j])*(xp[i]-x[j])*(xp[i]-x[j]);
                break;
            }
        }
    }
}

void Polynomial::Print_Results()
{
    long double maximo = 0;
    for(int i=0;i<m-1;++i)
    {
        std::cout << xp[i] << " " << yp[i] << std::endl;
        //std::cout << (yp[i+1] - yp[i])/(xp[i+1] - xp[i]) << std::endl;
        maximo = std::max(maximo, (yp[i+1] - yp[i])/(xp[i+1] - xp[i]));
    }

    std::cout << maximo << std::endl;
}