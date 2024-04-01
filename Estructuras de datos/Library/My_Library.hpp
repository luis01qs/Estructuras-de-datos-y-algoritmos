# ifndef My_Library
# define My_Library

# include <iostream>
# include <vector>

namespace N
{
    // Matemáticas
    int mcd(int &x, int &y);
    int factorial(int n);
    long double raiz_cuadrada(long double l, long double r, long double &x);

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

    // Búsqueda
    int busqueda_lineal(std::vector<int> &a, int x);
    int busqueda_lineal_recursiva(std::vector<int> &a, int x, int i);
    int busqueda_binaria(std::vector<int> &a, int x);
    int busqueda_binaria_recursiva(std::vector<int> &a, int l, int r, int x);

    // Estructuras de datos
    template<typename T>
    class Node
    {
        public:   
            T value;
            Node *next;
            Node(T d);
    };

    template<typename T>
    class Linked_list
    {
        private: 
            N::Node<T> *first;
            N::Node<T> *last;
            N::Node<T> *dynamic_node;

        public:
            Linked_list();
            ~Linked_list();
            bool empty();
            void push(T d);
            void pop();
            void print();
    };
}

# include "Math.cpp"
# include "Sort.cpp"
# include "Auxiliar.cpp"
# include "Busqueda.cpp"
# include "Estructuras.cpp"
# endif // My_Library
