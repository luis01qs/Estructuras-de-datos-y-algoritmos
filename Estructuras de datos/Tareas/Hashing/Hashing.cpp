# include <bits/stdc++.h>

using namespace std;

const int M = 208;

class Personas
{
    public:
        int ID;
        string Nombre;

        Personas();
        Personas(int ID, string Nombre);
        int hash();
        int push(vector<Personas> &personas);
};

int main()
{
    freopen("List_names.txt", "r", stdin);

    vector<Personas> personas(M);

    int x;
    string s;
    while(cin>>x>>s)
    {
        Personas p(x, s);
        personas[p.push(personas)] = p;
    }

    for(int i=0;i<M;++i)
    {
        if(personas[i].ID != INT_MAX)
        {
            cout << i << " " << personas[i].ID << " " << personas[i].Nombre << endl;
        }
    }

    return 0;
}

Personas::Personas()
{
    this -> ID = INT_MAX;
    this -> Nombre = "";
}

Personas::Personas(int ID, string Nombre)
{
    this -> ID = ID;
    this -> Nombre = Nombre;
}

int Personas::hash()
{
    int aux = ID;
    int res = aux % 10;

    aux /= 10;
    res += aux % 100;

    aux /= 100;
    res += aux % 100;

    return res;
}

int Personas::push(vector<Personas> &personas)
{
    int H = hash();

    int i = 0;
    while(true)
    {
        if(personas[(H+i*i) % M].ID == INT_MAX) return (H+i*i) % M;
        ++i;
    }

    return 0;
}