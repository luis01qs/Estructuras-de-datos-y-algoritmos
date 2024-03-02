# include "My_Library.hpp"

int main()
{
    int x = 10, y = 20;
    std::cout << N::mcd(x, y) << std::endl;

    std::vector<int> a = {4, 2, 5, 7, 10, 2, 5, 2, 7, 1};
    N::sort_mergesort(a, 0, a.size()-1);

    for(auto &e:a) std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}