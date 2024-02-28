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
    // Variable auxiliar
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

// Shell sort
void N::sort_shellsort(std::vector<int> &a)
{
    // Creamos variables auxiliares
    int temp, j;

    // Iteramos sobre el tamaño del gap 
    for(int gap=int(a.size());gap>0;gap/=2)
    {
        // Iteramos sobre todos los elementos desde el tamaño del gap hasta el final del vector
        for(int i=gap;i<int(a.size());++i)
        {
            // Utilizamos una variable auxiliar que almacene temporalmente el valor de a[i]
            temp = a[i];

            // Iteramos sobre elementos de el vector con saltos de distancia gap
            for(j=i;j>=gap && a[j-gap]>temp;j-=gap) 
            {
                // Recorremos los elementos a la derecha
                a[j] = a[j - gap];
            }

            // Movemos a[i] a a[j]
            a[j] = temp;
        }
    }
}

// Merge sort
void N::sort_mergesort(std::vector<int> &a, int l, int r)
{
    // Definición de caso base
    if(r - l == 0) return;

    // Ordenamos los dos subarreglos de forma recursiva
    sort_mergesort(a, l, (r+l)/2);
    sort_mergesort(a, (l+r)/2+1, r);

    // Creamos vector auxiliar
    std::vector<int> aux(r-l+1);

    // Inicializamos iteradores
    int i = l, j = (l+r)/2 + 1, k = 0;

    // Merge
    while(i <= (r+l)/2 && j <= r)
    {
        //Tomamos el más pequeño de la orilla izquierda de ambos subarreglos y anexamos al vector auxiliar
        if(a[i] <= a[j])
        {
            aux[k] = a[i];
            ++i;
        }
        else
        {
            aux[k] = a[j];
            ++j;
        }
        ++k;
    }

    // Terminamos de añadir todos los valores restantes del primer subarreglo
    while(i <= (r+l)/2)
    {
        aux[k] = a[i];
        ++i;
        ++k;
    }

    // Terminamos de añadir todos los valores restantes del segundo subarreglo
    while(j <= r)
    {
        aux[k] = a[j];
        ++j;
        ++k;
    }

    // Hacemos la modificacion en el vector original
    for(int i=0;i<int(aux.size());++i)
    {
        a[i+l] = aux[i];
    }
}
