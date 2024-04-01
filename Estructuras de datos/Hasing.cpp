# include <bits/stdc++.h>

using namespace std;

int HASH(int x)
{
    int res = 0;
    while(x)
    {
        res += x % 10;
        x /= 10;
    }

    return res;
}

int HASH2(int x)
{
    int res = 1;
    while(x)
    {
        res *= x%10;
        x /= 10;
    }

    return res;
}

int main()
{
    vector<int> a = {7832, 5498, 2067, 9145, 3721, 6803, 4319, 1876, 5024, 3490};
    vector<int> b(a.size()), c(a.size());

    for(int i=0;i<int(a.size());++i)
    {
        b[i] = HASH(a[i]);
        c[i] = HASH2(a[i]);

        cout << b[i] << " " << c[i] << endl;
    }

    return 0; 
}