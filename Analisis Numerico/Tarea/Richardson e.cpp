# include <bits/stdc++.h>
# define nl '\n'

using namespace std;
using ld = long double;

int main()
{
    //freopen("prueba.txt", "r", stdin);

    int n = 3;
    //cin>>n;

    vector<vector<ld>> N(n, vector<ld>(n, 0));

    cout << fixed << setprecision(10);

    ld h = 0.04;
    N[0][0] = pow(1+h/(1), 1/(h/(1)));
    N[0][1] = pow(1+h/(2), 1/(h/(2)));
    N[0][2] = pow(1+h/(4), 1/(h/(4)));

    for(int i=1;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            N[i][j] = N[i-1][j] + (N[i-1][j] - N[i-1][j-1])/(pow(2, i) - 1);
        }
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j) cout << N[j][i] << " ";
        cout << nl;
    }

    return 0;
}