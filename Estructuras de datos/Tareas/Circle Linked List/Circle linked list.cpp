# include <iostream>

class Node
{
    public:
        int valor;
        Node *next;
        Node *prev;

        Node(int valor)
        {
            this -> valor = valor;
            next = nullptr;
            prev = nullptr;
        }
};

class Circle_Linked_List
{
    private:
        Node *first;
        Node *last;
        Node *dynamic_node;

    public:
        Circle_Linked_List();
        bool empty();
        void insert_first(int d);
        void insert_last(int d);
        void pop_first();
        void pop_last();
        void print_fwd();
        void print_bwd();
};

int main()
{
    Circle_Linked_List cll;

    cll.insert_last(1);
    cll.insert_last(2);
    cll.insert_last(3);
    cll.insert_last(4);
    cll.insert_last(5);
    cll.insert_last(6);
    cll.insert_last(7);
    cll.insert_last(8);
    cll.insert_last(9);
    cll.insert_last(10);
    cll.insert_last(11);

    cll.print_fwd();
    cll.pop_first();
    cll.print_fwd();
    cll.pop_last();
    cll.print_fwd();

    return 0;
}

Circle_Linked_List::Circle_Linked_List()
{
    first = nullptr;
    last = nullptr;
}

bool Circle_Linked_List::empty()
{
    return first == nullptr;
}

void Circle_Linked_List::insert_first(int d)
{
    dynamic_node = new Node(d);
    
    if(!empty())
    {
        dynamic_node -> next = first;
        dynamic_node -> prev = last;
        first -> prev = dynamic_node;
        last -> next = dynamic_node;
        first = dynamic_node;
    }
    else
    {
        dynamic_node -> next = dynamic_node;
        dynamic_node -> prev = dynamic_node;
        first = dynamic_node;
        last = dynamic_node;
    }
}

void Circle_Linked_List::insert_last(int d)
{
    dynamic_node = new Node(d);
    
    if(!empty())
    {
        dynamic_node -> next = first;
        dynamic_node -> prev = last;
        first -> prev = dynamic_node;
        last -> next = dynamic_node;
        last = dynamic_node;
    }
    else
    {
        dynamic_node -> next = dynamic_node;
        dynamic_node -> prev = dynamic_node;
        first = dynamic_node;
        last = dynamic_node;
    }
}

void Circle_Linked_List::pop_first()
{
    if(empty()) return;

    dynamic_node = first;
    last -> next = first -> next;
    first -> next -> prev = last;
    first = first -> next;

    delete dynamic_node;
}

void Circle_Linked_List::pop_last()
{
    if(empty()) return;

    dynamic_node = last;
    first -> prev = last -> prev;
    last -> prev -> next = first;
    last = last -> prev;

    delete dynamic_node;
}

void Circle_Linked_List::print_fwd()
{
    if(empty()) return;
    dynamic_node = first;
    while(true)
    {
        std::cout << dynamic_node -> valor << " ";
        dynamic_node = dynamic_node -> next; 

        if(dynamic_node == first) break;
    }

    std::cout << dynamic_node -> valor << std::endl;
}

void Circle_Linked_List::print_bwd()
{
    if(empty()) return;
    dynamic_node = last;
    while(true)
    {
        std::cout << dynamic_node -> valor << " ";
        dynamic_node = dynamic_node -> prev; 

        if(dynamic_node == last) break;
    }

    std::cout << dynamic_node -> valor << std::endl;
}