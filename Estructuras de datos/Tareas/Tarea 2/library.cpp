# include "library.hpp"

void funcion_1(int x)
{
    int *ptr;
    ptr = &x;

    std::cout << "The value of x is: " << x << std::endl;
    std::cout << "The value of x using pointer is: " << *ptr << std::endl;
}

void funcion_2(int x)
{
    int *ptr = new int;
    *ptr = x;

    std::cout << "The value stored in dynamically allocated memory is: " << *ptr << std::endl;

    delete ptr;
}

void funcion_3(int arr[])
{
    int *ptr = arr;

    std::cout << "First element: " << *ptr << std::endl;
    std::cout << "Second element: " << *(ptr + 1) << std::endl;
    std::cout << "Third element: " << *(ptr + 2) << std::endl;
}

void funcion_4(int x)
{
    int *ptr1 = &x;
    int **ptr2 = &ptr1;

    std::cout << "The value of x is: " << x << std::endl;
    std::cout << "The value of x using ptr1 is: " << *ptr1 << std::endl;
    std::cout << "The value of x using ptr2 is: " << **ptr2 << std::endl;
}

void funcion_5()
{
    // Declare a structure variable
    Person person1;

    // Initialize structure members using dot operator
    person1.name = "John";
    person1.age = 25;
    person1.height = 6.1;

    // Declare a pointer to a structure
    Person *ptr;

    // Assign the address of the structure variable to the pointer
    ptr = &person1;

    // Access structure members using pointer and arrow operator
    std::cout << "Name: " << ptr->name << std::endl;
    std::cout << "Age: " << ptr->age << std::endl;
    std::cout << "Height: " << ptr->height << " feet" << std::endl;
}

void funcion_6()
{
    Employee emp1;

    // Initialize structure members
    emp1.name = "Alice";
    emp1.age = 30;

    // Allocate memory dynamically for the salary
    emp1.salary = new double;

    // Assign a value to the dynamically allocated memory
    *(emp1.salary) = 50000.0;

    // Access structure members
    std::cout << "Name: " << emp1.name << std::endl;
    std::cout << "Age: " << emp1.age << std::endl;
    std::cout << "Salary: $" << *(emp1.salary) << std::endl;

    // Don't forget to free the dynamically allocated memory
    delete emp1.salary;
}

