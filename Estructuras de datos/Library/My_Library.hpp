# ifndef My_Library
# define My_Library

# include <iostream>
# include <vector>

namespace N
{
    // Matemáticas
    int mcd(int &x, int &y);
    int factorial(int n);

    // Sorting
    void sort_insercion(std::vector<int> &a);
    void sort_seleccion(std::vector<int> &a);
    void sort_burbuja(std::vector<int> &a);
    void sort_quicksort(std::vector<int> &a, int x, int y);
    void sort_shellsort(std::vector<int> &a);
    void sort_mergesort(std::vector<int> &a, int l, int r);

    // Auxiliares
    void swap(int &a, int &b);
    int max(int &a, int &b);
    int min(int &a, int &b);
}

# include "Math.cpp"
# include "Sort.cpp"
# include "Auxiliar.cpp"
# endif // My_Library