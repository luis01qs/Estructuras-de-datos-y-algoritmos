# include "My_Library.hpp"

// Nodo
template <typename T>
N::Node<T>::Node(T d)
{
    value = d;
    next = nullptr;
}

// Linked list ###################################################################

// Constructor
template <typename T>
N::Linked_list<T>::Linked_list()
{
    first = nullptr;
    last = nullptr;
}

// Destructor
template <typename T>
N::Linked_list<T>::~Linked_list()
{
    while(!empty()) pop();
}

// Checa si la lista está vacía
template <typename T>
bool N::Linked_list<T>::empty()
{
    return first == nullptr;
}

// Añade un nuevo nodo al fina de la lista
template <typename T>
void N::Linked_list<T>::push(T d)
{
    dynamic_node = new Node(d);
    if(first == nullptr)
    {
        first = dynamic_node;
        last = dynamic_node;
    }
    else
    {
        last -> next = dynamic_node;
        last = dynamic_node;
    }
}

// Elimina el primer elemento de la lista
template <typename T>
void N::Linked_list<T>::pop()
{
    if(empty()) return;

    Node<T> *old = first;
    first = first -> next;
    delete old;
}

// Imprime la lista de adelante a atrás
template <typename T>
void N::Linked_list<T>::print()
{
    dynamic_node = first;
    while(dynamic_node != nullptr)
    {
        std::cout << dynamic_node -> value << " ";
        dynamic_node = dynamic_node -> next;
    }

    std::cout << std::endl;
}