# include <bits/stdc++.h>
# define ld long double
# define M 1e9 + 7
 
using namespace std;
 
vector<vector<ld>> multiplicacion_matrices(vector<vector<ld>> &a, vector<vector<ld>> &b)
{
    vector<vector<ld>> res(a.size(), vector<ld>(b[0].size(), 0));
 
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            for(int k=0;k<a[i].size();k++) res[i][j] += a[i][k] * b[k][j];
        }
    }
    return res;
}
 
vector<vector<ld>> exponenciacion_matriz(vector<vector<ld>> a, int n)
{
    if(n == 0)
    {
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a.size();j++)
            {
                if(i == j) a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
        return a;
    }
    if(n == 1) return a;
 
    vector<vector<ld>> res = exponenciacion_matriz(a, n/2);
    res = multiplicacion_matrices(res, res);
    if(n%2 == 0) return res;
    return multiplicacion_matrices(a, res);
}
 
void imprimir_matriz(vector<vector<ld>> &a)
{
    for(auto &e:a)
    {
        for(auto &u:e) cout << u << " ";
        cout << endl;
    }
}
 
int main()
{
    //freopen("prueba.txt", "r", stdin);
    int n;
    ld p;
    cin>>n>>p;
 
    vector<vector<ld>> a = {{1-p,p}, {p,1-p}};
    vector<vector<ld>> res = exponenciacion_matriz(a, n);
    vector<vector<ld>> ini = {{1}, {0}};
    vector<vector<ld>> res2 = multiplicacion_matrices(res, ini);
    cout << setprecision(12) << res2[0][0] << endl;
 
 
    return 0;
}