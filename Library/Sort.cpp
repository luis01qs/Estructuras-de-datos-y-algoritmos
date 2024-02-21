# include "My_Library.hpp"

// Insercion
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

// Selección
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

// Burbuja
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

// Quick sort
void N::sort_quicksort(std::vector<int> &a, int x, int y)
{
    if(x >= y) return ;

    int pivot = a[y];
	int i = x - 1;

	for(int j=x;j<=y-1;j++)
	{
		if(a[j] <= pivot)
		{
            i++;
			N::swap(a[j], a[i]);
		} 
	}

	N::swap(a[y], a[i + 1]);
    pivot = i+1;

    sort_quicksort(a, x, pivot - 1);
    sort_quicksort(a, pivot + 1, y);
}
