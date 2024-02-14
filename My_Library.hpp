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

    // Auxiliares
    void swap(int &a, int &b);
}

# include "Math.cpp"
# endif // My_Library

