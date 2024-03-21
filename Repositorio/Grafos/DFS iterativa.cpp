# include <bits/stdc++.h>
# define ll long long
# define nl '\n'

using namespace std;


vector<vector<int>> grafo;
vector<bool> vis;
void dfs(int nodo)
{
    if(vis[nodo] == true) return;
    vis[nodo] = true;

    for(int i=0;i<int(grafo[nodo].size());++i)
    {
        if(vis[grafo[nodo][i]] == true) continue;
        cout << nodo << " -> " << grafo[nodo][i] << nl;
        dfs(grafo[nodo][i]);
    }
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    int n;
    cin>>n;
    grafo.resize(n);
    vis.resize(n, 0);
    int m;
    cin>>m;

    int u, v;
    while(m--)
    {
        cin>>u>>v;
        --u, --v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    dfs(0);

    return 0;
}