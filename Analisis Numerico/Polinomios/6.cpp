# include <bits/stdc++.h>
# define ll long long
# define ld long double

using namespace std;

ld factorial2(ld k)
{
    //if(k > 17) k = 17;
    ld res = 1;
    for(ld i = 1;i<=k;++i) res *= i;
    return res;
}

int main()
{
    int n;
    long double res, x;

    freopen("salida.txt", "w", stdout);

    x = 0;
    n = 30;
    while(x <= 3)
    {
        res = 0;
        for(ld i=1;i<=n;++i)
        {
            res += pow(-1, i)*pow(x, 2*i)/(factorial2(2*i)*2*i);
            //cout << res << endl;
        }

        cout << x << " " << -res << endl;
        x += 0.01;
    }

    return 0;
}