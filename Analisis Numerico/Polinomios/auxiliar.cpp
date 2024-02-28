# include <bits/stdc++.h>
# define nl '\n'

using namespace std;

/*
4
0 0 75
0 0
3 225 77
3 225
5 383 80
5 383
8 623 74
8 623
13 993 72
13 993
*/

int main()
{
    freopen("datos.txt", "w", stdout);

    int n = 100*13;
    cout << n << endl;

    for(int i=0;i<n;++i)
    {
        cout << 13*double(i)/n << endl;
    }

    return 0;
}