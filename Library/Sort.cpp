# include "My_Library.hpp"

// Insercion
void N::sort_insercion(std::vector<int> &a)
{
    // Restringe los últimos i elementos del vector, porque ya están ordenados 
    for(int i=0;i<int(a.size())-1;++i)
    {
        // Itera desde el primer elemento hasta n-i
        for(int j=0;j<int(a.size())-i;++j)
        {
            // Mueve el elemento más grande hasta la derecha
            if(a[j] > a[j+1]) N::swap(a[j], a[j+1]);
        }
    }
}

// Selección
void N::sort_seleccion(std::vector<int> &a)
{
    int pos;

    // Itera elementos de derecha a izquierda 
    for(int i=0;i<int(a.size())-1;++i)
    {
        pos = i;

        // Encuentra el índice del más pequeño desde i hasta n
        for(int j=i;j<int(a.size());++j)
        {
            if(a[j] < a[pos]) pos = j;
        }

        // Cambia el más pequeño por el i
        N::swap(a[i], a[pos]);
    }
}

// Burbuja
void N::sort_burbuja(std::vector<int> &a)
{
    // Itera los elementos de izquierda a derecha
    for(int i=0;i<int(a.size());++i)
    {
        // Itera desde n-1 hasta i
        for(int j=int(a.size())-1;j>i;--j)
        {
            // Recorrde el más pequeño a la izquierda
            if(a[j] < a[j-1]) N::swap(a[j], a[j-1]);
        }
    }
}

// Quick sort
void N::sort_quicksort(std::vector<int> &a, int x, int y)
{
    // Caso base
    if(x >= y) return ;

    // Tomamos al úlitmo elemento como pivote
    int pivot = a[y];
	int i = x - 1;

    // Recorrde todos los elementos del subarreglo a excepción del pivote
	for(int j=x;j<=y-1;++j)
	{
        // Coloca a los menores que el pivote a la izquierda del subareglo
		if(a[j] <= pivot)
		{
            ++i;
			N::swap(a[j], a[i]);
		} 
	}

    // Coloca al pivote entre los menores y los mayores que el pivote
	N::swap(a[y], a[i + 1]);

    // Selecciones al pivote como el elemento del medio
    pivot = i+1;

    // Ordena los subarreglos menor y mayor
    sort_quicksort(a, x, pivot - 1);
    sort_quicksort(a, pivot + 1, y);
}
