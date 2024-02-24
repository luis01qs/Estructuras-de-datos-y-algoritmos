# include <iostream>
# include <vector>

// Shell sort
void sort_shellsort(std::vector<int> &a)
{
    // Vector auxiliar para eleminar los valores negativos
    std::vector<int> aux; 
    for(int i=0;i<int(a.size());++i)
    {
        // No hace nada si es un valor negativo
        if(a[i] < 0) continue;
        
        // Añadimos solo los valores no negativos al vector auxiliar
        aux.push_back(a[i]);
    }

    // Hacemos al vector original igual al que no tiene valores negativos
    a = aux;

    // Variables auxiliares
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


int main()
{
    // Acepta el input por medio de un archivo de texto llamado input.txt
    freopen("input.txt", "r", stdin);

    // Imprime el resultado en un archivo de texto llamado output.txt
    freopen("output.txt", "w", stdout);

    // Tamaño del vector
    int n;

    // Lee el tamaño del vector
    std::cin >> n;

    // Crea vector de tamaño dado y luego lee los valores
    std::vector<int> a(n);
    for(int i=0;i<n;++i) std::cin >> a[i];

    // Ordenamiento y eliminación de valores negativos
    sort_shellsort(a);

    // Imprime el resultado
    for(auto &e:a) std::cout << e << " ";
    std::cout << std::endl;
}