# include "My_Library.hpp"
# include <bits/stdc++.h>

int main()
{
    std::vector<int> a = {5,6,4,3,1,7};
    N::sort_quicksort(a, 0, int(a.size())-1);

    for(auto &e:a) std::cout << e << " ";
    std::cout << std::endl;

    std::cout << N::busqueda_binaria_recursiva(a, 0, int(a.size())-1, 3) << std::endl;
    return 0;
}