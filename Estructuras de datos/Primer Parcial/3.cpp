# include <iostream>

using namespace std;

void cambiar(int *a, int *b);
void ordenar_columnas(int **a, int n);
void ordenar_filas(int **a, int n);
void sort_columnas(int **a, int i, int n);
void sort_filas(int **a, int j, int n);
void print_matriz(int **a, int n);

int main()
{
    freopen("Matrix_10_10.txt", "r", stdin);
    freopen("salida3.txt", "w", stdout);

    // Inicializamos variables
    int n = 10;
    int **col, **row;

    col = new int* [n];
    row = new int* [n];

    for(int i=0;i<n;++i)
    {
        col[i] = new int [n];
        row[i] = new int [n];
    }

    // Leer matriz y hacer copia
    char c;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(j != 0) cin >> c;
            cin >> col[i][j];
            row[i][j] = col[i][j];
        }
    }

    // Ordenar
    ordenar_columnas(col, n);
    ordenar_filas(row, n);

    // Imprimir
    cout << "Matriz con columnas ordenadas de manera ascendente" << endl;
    print_matriz(col, n);

    cout << "Matriz con los renglones ordenados de manera descencente" << endl;
    print_matriz(row, n);

    return 0;
}

// Función tipo swap
void cambiar(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Ordenamiento por columnas
void ordenar_columnas(int **a, int n)
{
    // Ordena cada columna
    for(int i=0;i<n;++i)
    {
        sort_columnas(a, i, n);
    }
}

// Ordenamiento por renglones
void ordenar_filas(int **a, int n)
{
    // Ordena cada renglon
    for(int i=0;i<n;++i)
    {
        sort_filas(a, i, n);
    }
}

// Ordenamiento ascendente para columnas
void sort_columnas(int **a, int k, int n)
{
    // Bubble sort
    for(int i=0;i<n;++i)
    {
        for(int j=n-1;j>i;--j)
        {
            if(a[j][k] < a[j-1][k]) cambiar(&a[j][k], &a[j-1][k]);
        }
    }
}

// Ordenamiento descendente para filas
void sort_filas(int **a, int k, int n)
{
    // Bubble sort
    for(int i=0;i<n;++i)
    {
        for(int j=n-1;j>i;--j)
        {
            if(a[k][j] > a[k][j-1]) cambiar(&a[k][j], &a[k][j-1]);
        }
    }
}

void print_matriz(int **a, int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
