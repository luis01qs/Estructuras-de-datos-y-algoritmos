# include <iostream>
# include <math.h>

int main()
{
    freopen("datos.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int n;
    long double res, potencia, factorial, x;

    x = -5;
    n = 200;
    while(x <= 5)
    {
        potencia = x;
        factorial = 1;
        res = x;
        for(int k=1;k<=n;++k)
        {
            potencia *= - (x * x);
            factorial *= k;

            res += potencia/(factorial*(2*k+1));
        }

        res *= 2/sqrt(M_PI);
        std::cout << x << " " << res << std::endl;
        x += 0.01;
    }

    return 0;
}