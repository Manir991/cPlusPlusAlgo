#include <iostream>

using namespace std;

class Node
{
    public:
        int num;
        Node* next;
};

class Stack
{
    public:
        int capacity{0};    //Max limit of stack
        int size{-1};   // Current size
        Node* head{nullptr};

        Stack(int capacity);
        ~Stack();
        void push(int elem);
        void pop();
        int isFull();
        int isEmpty();
        Node* first();
        Node* peek(int position);
};

Stack::Stack(int capacity)
{
    this->capacity = capacity;
}

Stack::~Stack()
{
    cout << "Stack of size " << size << " is destroyed" << endl;
}

int Stack::isFull()
{
    if (size == capacity - 1)
    {
        return 1;
    }
    return 0;
}

int Stack::isEmpty()
{
    if(head == nullptr || size == -1)
    {
        return 1;
    }
    return 0;
}

void Stack::pop()
{
    // Check for empty stack
    Node *tmp = head;
    if (!isEmpty())
    {
        cout << "Popped elem: " << head->num << endl;
        head = head->next;
        delete tmp;
        size--;
    }
    else
    {
        cout << "Stack empty" << endl;
    }
}

void Stack::push(int elem)
{
    // Check for stack empty
    if(isFull())
    {
        cout << "Stack Full" << endl;
        return;
    }
    Node *n  = new Node;
    n->num = elem;
    if(isEmpty())
    {
        head = n;
    }
    else
    {
        n->next = head;
        head = n;
    }
    size++;
}

Node* Stack::peek(int position)
{
    Node* tmp = new Node;
    tmp = head;
    if(size - position + 1 < 0)
    {
        cout << "Invalid index" << endl;
        return nullptr;
    }
    for(int i = 1; i < position && tmp->next != nullptr; i++)
    {
        tmp = tmp->next;
    }
    return tmp;

}

Node* Stack::first()
{
    return head;
}

/*Conditions
Empty Stack -> if (head == nullptr || size == -1)
Full Stack -> if (size == caparcity - 1 )
*/


int main()
{
    Stack s1(5);
    cout << s1.capacity << endl;

    s1.push(5);
    s1.push(10);
    s1.push(15);
    s1.push(20);
    s1.push(25);
    s1.push(30);
    Node* elem = s1.peek(7);
    if (elem){
        cout << elem -> num << endl;
    }
    else{
        cout << "ERROR" << endl;
    }
    delete elem;
    return 0;
}
