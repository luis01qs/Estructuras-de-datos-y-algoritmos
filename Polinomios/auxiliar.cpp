# include <bits/stdc++.h>
# define nl '\n'

using namespace std;

int main()
{
    freopen("datos.txt", "w", stdout);

    int n = 5;
    cout << n << endl;

    double a = -5;
    double x, y;
    for(int i=0;i<n+1;++i)
    {
        x = a + double(i)/n * 10;
        y = 1/(1+x*x);
        cout << x << " " << y << nl;
    }

    int m = 30;
    cout << m << nl;

    for(int i=1;i<m+1;++i)
    {
        cout << a + double(i)/(m+1) * 10 << nl;
    }

    return 0;
}