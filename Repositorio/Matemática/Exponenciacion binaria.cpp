# include <bits/stdc++.h>
# define ll long long

using namespace std;

ll bin_pow(ll a, ll b)
{
    if(b == 0) return 1;

    ll res = bin_pow(a, b/2);

    if(b%2 == 0) return res * res;
    return res * res * a;
}

