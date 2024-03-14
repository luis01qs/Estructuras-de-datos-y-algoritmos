#include "library.hpp"

int main() 
{
    freopen("salidat.txt", "w", stdout);
    
    funcion_1(10);
    std::cout << std::endl;

    funcion_2(20);
    std::cout << std::endl;

    int arr[] = {10, 20, 30, 40, 50};
    funcion_3(arr);
    std::cout << std::endl;

    funcion_4(10);
    std::cout << std::endl;
    
    funcion_5();
    std::cout << std::endl;

    funcion_6();
    std::cout << std::endl;

    return 0;
}