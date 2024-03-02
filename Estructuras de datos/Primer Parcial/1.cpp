# include <iostream>
# include <vector>

using namespace std;

// Prototipo de funciones
void cambiar(int &a, int &b);
void ordenar_columnas(vector<vector<int>> &a);
void ordenar_filas(vector<vector<int>> &a);
void sort_seleccion(vector<int> &a);
void print_matriz(vector<vector<int>> &a);
vector<float> estadistica(vector<vector<int>> &a);

int main()
{
    // Entrada y salida
    freopen("Matrix_10_10.txt", "r", stdin);
    freopen("salida1.txt", "w", stdout);

    // Inicializar variables
    int n = 10, m = 10;
    vector<vector<int>> datos(n, vector<int>(m, 0));

    // Auxiliar para leer las comas
    char c;

    // Leer datos
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(j != 0) cin>>c;
            cin>>datos[i][j];
        }
    }

    // Auxiliares
    vector<vector<int>> col = datos, row = datos;

    // Por columnas
    cout << "Matriz con columnas ordenadas de manera ascendente" << endl;
    ordenar_columnas(col);
    print_matriz(col);
    cout << endl;

    // Por filas
    cout << "Matriz con los renglones ordenados de manera descencente" << endl;
    ordenar_filas(row);
    print_matriz(row);
    cout << endl;

    // Valores estadístico
    vector<float> est = estadistica(datos);
    cout << "El valor de la media es: " << est[0] << ", y hay " << est[2] << " valores menores a la media" << endl;
    cout << "El valor de la mediana es: " << est[1] << ", y hay " << est[3] << " valores menores a la mediana" << endl;

    return 0;
}

// Swap dos elementos
void cambiar(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

// Método para ordenar por columnas
void ordenar_columnas(vector<vector<int>> &a)
{
    // Vector auxiliar
    vector<int> aux(a.size());
    for(int i=0;i<int(a.size());++i)
    {
        // Copia columna a vector
        for(int j=0;j<int(a[i].size());++j)
        {
            aux[j] = a[j][i];
        }

        // Ordenamiento de vector auxiliar
        sort_seleccion(aux);

        // Cambio de columna por vector ordenado
        for(int j=0;j<int(a[i].size());++j)
        {
            a[j][i] = aux[j];
        }
    }
}

//Método para ordenar por fila
void ordenar_filas(vector<vector<int>> &a)
{
    // Vector auxiliar
    vector<int> aux(a.size(), 0);
    for(int i=0;i<int(a.size());++i)
    {
        // Copia columna a vector
        for(int j=0;j<int(a[i].size());++j)
        {
            // Numeros negativos para ordenar de mayor a menor
            aux[j] = -a[i][j];
        }

        // Ordenamiento de vector auxiliar
        sort_seleccion(aux);

        // Cambio de columna por vector ordenado
        for(int j=0;j<int(a[i].size());++j)
        {
            // Regreso a numeros positivos para ordenamiento decreciente
            a[i][j] = -aux[j];
        }
    }
}

// Selección
void sort_seleccion(vector<int> &a)
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
        cambiar(a[i], a[pos]);
    }
}

// Imprimir la matriz
void print_matriz(vector<vector<int>> &a)
{
    for(int i=0;i<int(a.size());++i)
    {
        for(int j=0;j<int(a[i].size());++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

vector<float> estadistica(vector<vector<int>> &a)
{
    // Vector auxiliar para ordenar
    vector<int> aux;
    for(int i=0;i<int(a.size());++i)
    {
        for(int j=0;j<int(a[i].size());++j) aux.push_back(a[i][j]);
    }

    // Ordena auxiliar
    sort_seleccion(aux);

    // Creamos vector de respuesta
    vector<float> res(4, 0);

    // Calcula media
    for(int i=0;i<int(aux.size());++i) res[0] += aux[i];
    res[0] /= aux.size();

    // Calcula mediana
    res[1] = (aux[aux.size()/2-1] + aux[aux.size()/2]) / 2;

    // Calcular número de elementos menores a la media y a la mediana
    for(int i=0;i<int(aux.size());++i)
    {
        if(aux[i] < res[0]) res[2]++;
        if(aux[i] < res[1]) res[3]++;
    }

    return res;
}
