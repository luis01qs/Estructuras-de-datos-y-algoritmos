# include <bits/stdc++.h>
# define ll long long
# define nl '\n'

using namespace std;

vector<vector<ll>> multiplicacion_matrices(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
    vector<vector<ll>> res(a.size(), vector<ll>(b[0].size(), 0));

    for(int i=0;i<res.size();++i)
    {
        for(int j=0;j<res[i].size();++j)
        {
            for(int k=0;k<a[i].size();++k) res[i][j] += a[i][k] * b[k][j];
        }
    }
    return res;
}

vector<vector<ll>> exponenciacion_matriz(vector<vector<ll>> a, int n)
{
    if(n == 0)
    {
        for(int i=0;i<a.size();++i)
        {
            for(int j=0;j<a.size();++j)
            {
                if(i == j) a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
        return a;
    }
    if(n == 1) return a;

    vector<vector<ll>> res = exponenciacion_matriz(a, n/2);
    res = multiplicacion_matrices(res, res);
    if(n%2 == 0) return res;
    return multiplicacion_matrices(a, res);
}
