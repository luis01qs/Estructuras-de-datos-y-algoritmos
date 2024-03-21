# include <bits/stdc++.h>
# define ll long long
# define nl '\n'

using namespace std;

int K = 26;

struct Nodo
{
    vector<Nodo*> hijos;
    bool final;

    Nodo()
    {
        final = false;
        hijos.resize(26, nullptr);
    }
};

struct Trie
{
    Nodo *root;

    Trie()
    {
        root = new Nodo;
    }

    void insert(string &s)
    {
        Nodo *actual = root;
        for(char &c:s)
        {
            if(actual -> hijos[c-'a'] == nullptr)
            {
                actual -> hijos[c-'a'] = new Nodo;
            }
            actual = actual -> hijos[c-'a'];
        }
        actual -> final = true;
    }

    void print(Nodo *nodo)
    {
        for(int i=0;i<K;++i)
        {
            if(nodo -> hijos[i] == nullptr) continue;
            cout << char('a' + i) << nl;
            print(nodo -> hijos[i]);
        }
    }
};


int main()
{
    freopen("prueba.txt", "r", stdin);
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;++i) cin>>s[i];

    Trie trie;
    for(int i=0;i<n;++i)
    {
        trie.insert(s[i]);
    }

    trie.print(trie.root);
}
