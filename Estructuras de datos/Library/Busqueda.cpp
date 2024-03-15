# include "My_Library.hpp"

// Busqueda lineal no recursiva
int N::busqueda_lineal(std::vector<int> &a, int x)
{
    // Ciclo para buscar el elemento
    for(int i=0;i<int(a.size());++i)
    {
        // Si lo encunetra regresa el valor
        if(a[i] == x) return i;
    }

    // Si no lo encuentra regresa -1
    return -1;
}

// Busqueda lineal recursiva
int N::busqueda_lineal_recursivo(std::vector<int> &a, int x, int i)
{
    // Caso en el que llegó al final del vector y no lo encontró
    if(i == int(a.size())) return -1;

    // Si lo encuentra en la posición i, retorna i
    if(a[i] == x) return i;

    // En caso de que no esté en i busca en i+1
    return N::busqueda_lineal_recursivo(a, x, i+1);
}

// Busqueda binaria no recursiva
int N::busqueda_binaria(std::vector<int> &a, int x)
{
    // Limite inferior y superior
    int l = 0, r = int(a.size())-1;

    // Punto medio 
    int m;

    // Bucle para hacer busqueda binaria
    while(l <= r)
    {
        // Calcula punto medio
        m = l + (r - l)/2;

        // Verifica si el valor está en el punto medio y en tal caso retorna el índice
        if(a[m] == x) return m;

        // Verifica si el valor está en la mitad derecha o izquierda del subvector
        if(a[m] < x) l = m + 1;
        else r = m - 1;
    }

    // Si no lo encuentra retorna -1
    return -1;
}

// Búsqueda binaria recursiva
int N::busqueda_binaria_recursiva(std::vector<int> &a, int l, int r, int x)
{
    // Caso base
    if(l > r) return -1;

    // Definimos el punto medio
    int m = l + (r - l) / 2;

    // Si el valor buscado está en m retorna m
    if(a[m] == x) return m;

    // Si está a la izquierda retornamos la busqueda binaria de la izquierda
    if(a[m] < x) return N::busqueda_binaria_recursiva(a, m + 1, r, x);

    // De lo contrario retornamos la busuqda binaria de la derecha
    return N::busqueda_binaria_recursiva(a, l, m-1, x);
}
