# include "library.hpp"

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("datos.txt", "w", stdout);

    funcion_1();
    std::cout << std::endl;

    funcion_2();
    std::cout << std::endl;

    funcion_3();
    std::cout << std::endl;

    funcion_4();
    std::cout << std::endl;

    return 0;
}