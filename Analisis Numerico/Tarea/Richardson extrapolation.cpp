# include <bits/stdc++.h>
# define nl '\n'

using namespace std;
using ld = long double;

int main()
{
    freopen("prueba.txt", "r", stdin);

    int n;
    cin>>n;

    vector<vector<ld>> N(n, vector<ld>(n, 0));

    cout << fixed << setprecision(10);

    for(int i=0;i<n;++i) cin>>N[0][i];

    for(int i=1;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            N[i][j] = N[i-1][j] + (N[i-1][j] - N[i-1][j-1])/(pow(4, i) - 1);
        }
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j) cout << N[j][i] << " ";
        cout << nl;
    }

    return 0;
}