# include "My_Library.hpp"

void N::sort_insercion(std::vector<int> &a)
{
    for(int i=0;i<int(a.size())-1;++i)
    {
        for(int j=0;j<int(a.size())-i;++j)
        {
            if(a[j] > a[j+1]) N::swap(a[j], a[j+1]);
        }
    }
}

void N::sort_seleccion(std::vector<int> &a)
{
    int pos;
    for(int i=0;i<int(a.size())-1;++i)
    {
        pos = i;
        for(int j=i;j<int(a.size());++j)
        {
            if(a[j] < a[pos]) pos = j;
        }

        N::swap(a[i], a[pos]);
    }
}