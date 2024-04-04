# include <bits/stdc++.h>

using namespace std;
using ld = long double;

ld end_point(vector<ld> &x, vector<ld> &y, int i)
{
    ld res = 0;
    ld h = x[i+1] - x[i];

    res += (-3*y[i] + 4*y[i+1] - y[i+2]);
    res = res / (2*h);

    return res;
}

ld mid_point(vector<ld> &x, vector<ld> &y, int i)
{
    ld res = 0;
    ld h = x[i+1] - x[i];

    res += y[i+1] - y[i-1];
    res = res / (2*h);

    return res;
}

ld end_point_inverted(vector<ld> &x, vector<ld> &y, int i)
{
    ld res = 0;
    ld h = x[i] - x[i-1];

    res += (3*y[i] - 4*y[i-1] + y[i-2]);
    res = res / (2*h);

    return res;
}

int main()
{
    freopen("prueba.txt", "r", stdin);

    int n;
    cin>>n;

    vector<ld> x(n), y(n);
    for(int i=0;i<n;++i)
    {
        cin>>x[i]>>y[i];
    }

    vector<ld> res(n);
    for(int i=0;i<n;++i)
    {
        if(i != 0 && i != n-1)
        {
            res[i] = mid_point(x, y, i);
            continue;
        }

        if(i == 0) res[i] = end_point(x, y, i);
        else res[i] = end_point_inverted(x, y, i);
    }

    for(int i=0;i<n;++i)
    {
        cout << x[i] << ", " << y[i] << " -> " << res[i] << endl;
    }

    return 0;
}