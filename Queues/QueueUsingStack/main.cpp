// Simulating queue using 2 stacks

#include <iostream>
#include <stack>

using namespace std;

const int stk1size{5};
const int stk2size{5};

class Queue
{
    private:
        stack<int> eStk;
        stack<int> dStk;
    public:
        Queue();
        ~Queue();
        void enqueue(int elem);
        int dequeue();
};

Queue::Queue(){}
Queue::~Queue(){
    cout << "Memory released" << endl;
}

void Queue::enqueue(int elem)
{
    eStk.push(elem);
}

int Queue::dequeue()
{
    int popped{-1};
    if(eStk.empty() && dStk.empty()){
        cout << "Queue empty" << endl;
        return popped;
    }
    if(dStk.empty()){
        while(!eStk.empty()){
            dStk.push(eStk.top());
            eStk.pop();
        }
    }
    popped = dStk.top();
    dStk.pop();
    return popped;
}


int main()
{
    Queue q1;

    int elem[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(elem)/ sizeof(elem[0]);

    // PUSH 1/2 of array elems
    for(int i{0}; i < size; i++){
        q1.enqueue(elem[i]);
    }
    for(int i{0}; i < size; i++){
        cout << q1.dequeue() << " ";
    }
    cout << endl;

    cout << q1.dequeue() << endl;

    return 0;
}
