#include <iostream>

using namespace std;

class Stack
{
    public:
        int size{0};
        int top{-1};
        int *stk{nullptr};

        Stack(int size);
        ~Stack();
        void push(int elem);
        void pop();
        int isFull();
        int isEmpty();
        int first();
        int peek(int position);
};

Stack::Stack(int size)
{
    this->size = size;
    stk = new int[size-1]{};
}

Stack::~Stack()
{
    cout << "Stack with size " << this->size << " is destroyed" << endl;
    delete [] stk;
}

void Stack::push(int elem)
{
    if(isFull())
    {
        cout << "Stack Full" << endl;
        return;
    }
    stk[++top] = elem; // store new elem inside
    cout << elem << " pushed into position " << top << endl;
}

void Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack Empty" << endl;
        return;
    }
    cout << "Popped elem: " << stk[top] << endl; // Popped elem
    stk[top--] = -1;
}

int Stack::peek(int position)
{
    if(top - position + 1 < 0)
    {
        cout << "Invalid Position" << endl;
        return -1;
    }
    return stk[top - position + 1];
}

int Stack::first()
{
    return top > -1 ? stk[top]:-1;
}

int Stack::isFull()
{
    if(top == size-1)
        return 1;
    return 0;
}

int Stack::isEmpty()
{
    if(top == -1)
        return 1;
    return 0;
}

int main()
{
    Stack *s1 = new Stack(5);
    s1->push(1);
    s1->push(2);
    s1->push(3);
    s1->push(4);
    s1->push(5);

    s1->pop();

    s1->push(6);
    s1->push(7);
    cout << s1 -> peek(5) << endl;
    cout << s1->first() << endl;

    delete s1;
    return 0;
}
