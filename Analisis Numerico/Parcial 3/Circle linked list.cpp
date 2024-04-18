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



