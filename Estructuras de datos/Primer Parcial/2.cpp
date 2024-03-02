# include <iostream>
# include <vector>

using namespace std;

// Prototipo de funciones
void cambiar(pair<int, int> &a, pair<int, int> &b);
void ordenar(vector<vector<pair<int, int>>> &a);
void quicksort(vector<pair<int, int>> &a, int x, int y);
void imprimir(vector<vector<pair<int, int>>> &a);
void imprimir_arreglo(vector<vector<pair<int, int>>> &a);

int main()
{
    // Estructura que almacena los datos
    vector<vector<pair<int ,int>>> datos(3, vector<pair<int ,int>>(6));
    string s;

    // Salida
    freopen("salida2.txt", "w", stdout);

    // Leemos los datos para las ventas del año 2019
    freopen("Ventas_bimestrales_2019.txt", "r", stdin);
    cin>>s>>s;

    for(int i=0;i<6;++i)
    {
        cin>>datos[0][i].first>>datos[0][i].second;
    }

    // Leemos los datos para las ventas del año 2020
    freopen("Ventas_bimestrales_2020.txt", "r", stdin);
    cin>>s>>s;

    for(int i=0;i<6;++i)
    {
        cin>>datos[1][i].first>>datos[1][i].second;
    }

    // Leemos los datos para las ventas del año 2021
    freopen("Ventas_bimestrales_2021.txt", "r", stdin);
    cin>>s>>s;

    for(int i=0;i<6;++i)
    {
        cin>>datos[2][i].first>>datos[2][i].second;
    }

    // Ordenamos los datos de cada año
    ordenar(datos);

    // Imprime los resultados
    imprimir(datos);

    // Imprime arreglo de mayores ventas por año
    imprimir_arreglo(datos);

    return 0;
}

// Swap dos pair
void cambiar(pair<int, int> &a, pair<int, int> &b)
{
    pair<int, int> aux = a;
    a = b;
    b = aux;
}

// Función que manda a llamar el ordenamiento
void ordenar(vector<vector<pair<int ,int>>> &a)
{
    // Manda a ordenar los años
    for(int i=0;i<int(a.size());++i)
    {
        quicksort(a[i], 0, a[i].size()-1);
    }
}

// Función para ordenar
void quicksort(vector<pair<int, int>> &a, int x, int y)
{
    // Caso base
    if(x >= y) return ;

    // Tomamos al úlitmo elemento como pivote
    pair<int, int> pivot = a[y];
	int i = x - 1;

    // Recorrde todos los elementos del subarreglo a excepción del pivote
	for(int j=x;j<=y-1;++j)
	{
        // Coloca a los menores que el pivote a la izquierda del subareglo
		if(a[j].second <= pivot.second)
		{
            ++i;
            cambiar(a[j], a[i]);
		}
	}

    // Coloca al pivote entre los menores y los mayores que el pivote
	cambiar(a[y], a[i + 1]);

	int pivote = i+1;

    // Ordena los subarreglos menor y mayor
    quicksort(a, x, pivote-1);
    quicksort(a, pivote + 1, y);
}

void imprimir(vector<vector<pair<int, int>>> &a)
{
    int k1 = 0, k2 = 0;

    // Imprime mayores y menores de cada año
    for(int i=0;i<int(a.size());++i)
    {
        if(a[i][0].second < a[k1][0].second) k1 = i;
        if(a[i][a[i].size()-1].second > a[k2][a[i].size()-1].second) k2 = i;

        cout << "Bimestre de menor venta: " << a[i][0].first << " - " << 2019+i << " - " << a[i][0].second << endl;
        cout << "Bimestre de mayor venta: " << a[i][a[i].size()-1].first << " - " << 2019+i << " - " << a[i][a[i].size()-1].second << endl;
    }
    cout << endl;

    // Imprime mayores y menores globales
    cout << "Bimestre de menor venta global: " << a[k1][0].first << " - " << 2019+k1 << " - " << a[k1][0].second << endl;
    cout << "Bimestre de mayor venta global: " << a[k2][a[k2].size()-1].first << " - " << 2019+k2 << " - " << a[k2][a[k2].size()-1].second << endl;
    cout << endl;
}

void imprimir_arreglo(vector<vector<pair<int, int>>> &a)
{
    for(int i=0;i<int(a.size());++i)
    {
        cout << a[i][a[i].size()-1].first << " - " << 2019+i << " - " << a[i][a[i].size()-1].second << endl;
    }
    cout << endl;
}
