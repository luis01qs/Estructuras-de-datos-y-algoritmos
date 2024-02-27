# include <bits/stdc++.h>
# define nl '\n'

using namespace std;

int main()
{
    freopen("datos.txt", "w", stdout);

    int n = 30;
    cout << n << nl;
    for(int i=0;i<n+1;++i)
    {
        cout << i << nl;
    }

    int m = 10*100;
    cout << m << nl;
    for(int i=0;i<m;++i)
    {
        cout << 10 + 10*(long double)(i)/m << nl;
    }

    cout << 3 << nl;

    return 0;
}