# Estructuras de datos y algoritmos

El archivo My_Library.hpp tiene todas los prototipos de las funciones que se utilizan. 

## Matemáticas

El proptotipo de las funciones están en My_Library.hpp y el desarrollo de las funciones está en Math.cpp. Aquí se encuentran las funciones:

- mcd: calcula el mcd entre dos números enteros.
- factorial: calcula el n-ésimo elemento de la sucesión de fibonacci de manera recursiva (no es la más eficiente).
- raiz_cuadrada: recibe tres long doubles, límite inferior l (recomendado 0), límite superior r(recomendado x) y el valor a calcular la raíz x, respectivamente. Retorna el valor con diferencia de 0.0001 de la raíz. 

## Ordenamiento

El proptotipo de las funciones están en My_Library.hpp y el desarrollo de las funciones está en Sort.cpp. Aquí se encuentran las funciones:

- sort_insertion: Ordena de menor a mayor un vector de enteros utilizando el método de la inseción. 
- sort_seleccion: Ordena de menor a mayor un vector de enteros utilizando el método de selección. 
- sort_burbuja: Ordena de menor a mayor un vector de enteros utlilzando el método de la burbuja. 
- sort_quicksort: Ordena de menor a mayor un vector de enteros ultilizando el método de quick sort. 
- sort_shellsort: Ordena de menor a mayor un vector de enteros ulitizando el método de shell sort.
- sort_mergesort: Ordena de menor a mayor un vector de enteros utilizando el método de merge sort.

## Auxiliar

El prototipo de las funciones están en My_Library.hpp y el desarrollo de las funciones está en Auxiliar.cpp. Aquí se encuentran las funciones:

- swap: Intercambia dos valores tipo entero.
- max: Retorna el máximo valor entre dos enteros.
- min: Retorna el mínomo valor entre dos enteros.

## Busqueda

El prototipo de las funciones están en My_Library.hpp y el desarrollo de las funciones está en Busqueda.cpp. Aquí se encuentran las funciones:

- busqueda_lineal: Retorna la posición del elemento que se busca de forma lineal. Si no está en el vector retorna -1.
- busqueda_lineal_recursiva: Retorna la posición del elemento que se busca de forma recursiva y lineal. Si no está en el vector retorna -1.
- busqueda_binaria: Retorna la posición del elemento que se busca de forma binaria. Si no está en el vector retorn -1.
- busqueda_binaria_recursiva: Retorna la posición del elemento que se busca de forma recursiva y binaria. Si no está en el vector retorn -1.