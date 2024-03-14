# include "library.hpp"

void funcion_1()
{
    // Inicializamos i
    int i = 5;

    // Creamos puntero que almacene dirección de memoria de i
    int *p_j;
    p_j = &i;

    // Multiplicar por 5 (como *p_j = 5 -> (*p_j)*(*p_j) = 5*(*p_j))
    *p_j = (*p_j)*(*p_j);

    // Nuevo puntero con asignación de memoria
    int *p_k;
    p_k = new int;

    // Le asignamos el valor de i al nuevo puntero
    *p_k = i;

    // Imprimirmos los valores de todas las varibales para ver que son iguales
    std::cout << "Valores de i, *p_j y *p_k respectivamente:" << std::endl;
    std::cout << i << " " << *p_j << " " << *p_k << std::endl;

    // Liberar memoria
    delete p_k;
}

void funcion_2()
{
    // Punteros con asignación de memoria
    int *a, *b;
    a = new int;
    b = new int;

    // Asignación de valores
    *a = 10;
    *b = 20;

    // Imprimimos valores iniciales
    std::cout << "Los valores de a y b respectivamente: " << std::endl;
    std::cout << *a << " "  << *b << std::endl;

    // Variable auxiliar
    int *c;
    c = new int;

    // Swap
    *c = *a;
    *a = *b;
    *b = *c;

    // Imprimimos valores modificados
    std::cout << "Los valores de a y b después de modificar respectivamente: " << std::endl;
    std::cout << *a << " "  << *b << std::endl;

    // Liberar memoria
    delete a;
    delete b;
    delete c;
}

void funcion_3()
{
    // Se reduce de 1000000000 a 100 debido a que es demasiado grande el archivo de texto con el resultado.
    // Ya se comprobó que se limpia memoria de forma correcta
    for(int i=0;i<100;++i)
    {
        // Crea arreglos con punteros
        double *v1 = new double[3];
        double *v2 = new double[3];

        // Variable auxiliar para producto punto
        double *res = new double;
        *res = 0;

        // Inicialización de arrgelos
        for(int j=0;j<3;++j)
        {
            *(v1+ j) = double(j)/(i+1);
            *(v2+ j) = double(j+1)/(i+1);
        }

        // Cálculo de producto punto
        for(int j=0;j<3;++j)
        {
            *res += *(v1 + j)*(*(v2+j));
        }

        // Imprimir resultados
        std::cout << "Valor del producto punto: " << *res << std::endl;

        // Liberar memoria
        delete res;
        delete[] v1;
        delete[] v2;
    }
}

void funcion_4()
{
    // Se reduce de 1000000000 a 100 debido a que es demasiado grande el archivo de texto con el resultado.
    // Ya se comprobó que se limpia memoria de forma correcta
    for(int i=0;i<100;++i)
    {
        // Creando matrices con punteros
        int **a, **b, **c;
        a = new int* [2];
        b = new int* [2];
        c = new int* [2];

        for(int j=0;j<2;++j)
        {
            *(a+j) = new int[2];
            *(b+j) = new int[2];
            *(c+j) = new int[2];
        }

        // Inicializacion
        for(int j=0;j<2;++j)
        {
            for(int k=0;k<2;++k)
            {
                *(*(a+j)+k) = i+j+k;
                *(*(b+j)+k) = i+j+k;
                *(*(c+j)+k) = *(*(a+j)+k) + *(*(b+j)+k);
            }
        }

        // Imprimir matriz
        std::cout << "El valor de la matriz C es de: " << std::endl;
        for(int j=0;j<2;++j)
        {
            for(int k=0;k<2;++k)
            {
                std::cout << *(*(c+j)+k) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        // Liberar memoria
        for(int j=0;j<2;++j)
        {
            delete[] a[j];
            delete[] b[j];
            delete[] c[j];
        }

        delete[] a;
        delete[] b;
        delete[] c;
    }
}