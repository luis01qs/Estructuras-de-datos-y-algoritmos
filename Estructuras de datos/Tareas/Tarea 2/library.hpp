# ifndef Tarea
# define Tarea

# include <iostream>
# include <string>

struct Person 
{
    std::string name;
    int age;
    double height;
};

struct Employee 
{
    std::string name;
    int age;
    double *salary; // Pointer to double for storing salary
};

void funcion_1(int x);
void funcion_2(int x);
void funcion_3(int arr[]);
void funcion_4(int x);
void funcion_5();
void funcion_6();

# include "library.cpp"
# endif // Tarea
