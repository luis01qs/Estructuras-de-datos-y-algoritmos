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

void N::sort_burbuja(std::vector<int> &a)
{
    for(int i=0;i<int(a.size());++i)
    {
        for(int j=int(a.size())-1;j>i;--j)
        {
            if(a[j] < a[j-1]) N::swap(a[j], a[j-1]);
        }
    }
}

void N::sort_quicksort(std::vector<int> &a)
{
    N::sort_quicksort(a, 0, a.size()-1);
}

void N::sort_quicksort(std::vector<int> &a, int l, int r)
{
    if(r - l <= 1) return;

    int p = a[l], cont = 0;
    for(int i=l+1;i<=r;++i)
    {
        if(a[i] <= p) cont++;
    }

    int p_indice = l + cont;
    N::swap(a[l], a[p_indice]);

    int i = l, j = r;
    while(i < p_indice && j > p_indice)
    {
        while(a[i] <= p) ++i;
        while(a[j] > p) ++j;

        if(i < p_indice && j > p_indice) N::swap(a[i++], a[j--]);
    }

    N::sort_quicksort(a, l, p-1);
    N::sort_quicksort(a, p+1, r);
}