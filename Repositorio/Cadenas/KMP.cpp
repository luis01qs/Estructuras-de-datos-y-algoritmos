# include <bits/stdc++.h>
# define ll long long
# define nl '\n'

using namespace std;

vector<int> b;
void kmpPreprocess(string &p)
{
    b.resize(p.size() + 1);
    int i = 0, j = -1;
    b[0] = -1;
    while(i < int(p.size()))
    {
        while(j >= 0 && p[i] != p[j]) j = b[j];
        ++i, ++j;
        b[i] = j;
    }
}

void kmpSearch(string &p, string &t)
{
    int i = 0, j = 0;
    while(i < int(t.size()))
    {
        while(j >= 0 && t[i] != p[j]) j = b[j];
        ++i, ++j;
        if(j == int(p.size()))
        {
            cout << i-j << endl;
            j = b[j];
        }
    }
}

int main()
{
    string p = "SEVENTY SEVEN";
    string t = "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN";
    b.resize(p.size() + 1);
    kmpPreprocess(p);
    kmpSearch(p, t);
    return 0;
}