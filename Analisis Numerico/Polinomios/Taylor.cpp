# include <iostream>

int main()
{
    freopen("datos.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int n;
    long double res, potencia, factorial, x;


    x = 0;
    n = 50;
    while(x <= 10)
    {
        potencia = 1;
        factorial = 1;
        res = 0;
        for(int k=1;k<=n;++k)
        {
            factorial *= k;
            potencia *= x;

            res += potencia/(factorial * k);
        }

        std::cout << x << " " << res << std::endl;

        x += 0.01;
    }

    return 0;
}