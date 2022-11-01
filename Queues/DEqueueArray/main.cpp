// Double Ended Queue - Using head and tail to insert and delete elements from a queue

#include <iostream>

using namespace std;

class Dequeue
{
    private:
        int size;
        int head{-1};
        int tail{-1};
        int *array{nullptr};
    public:
        Dequeue(int size);
        ~Dequeue();
        bool isEmpty();
        bool isFull();
        void enqueueHead(int elem);
        void enqueueTail(int elem);
        int dequeueHead();
        int dequeueTail();
};

Dequeue::Dequeue(int size){
    this->size = size;
    head = -1;
    tail = -1;
    array = new int[size];
}
Dequeue::~Dequeue(){
    delete []array;
    cout << "Queue of size " << size << " released" << endl;
}
bool Dequeue::isEmpty(){
    if(head == tail){
        head = -1; tail = -1;
        return 1;
    }
    return 0;
}
bool Dequeue::isFull(){
    if(tail == size-1){
        return 1;
    }
    return 0;
}
void Dequeue::enqueueHead(int elem){
    // Inserting from head end
    // | 1| 2| 3| 4|
    if(head < 0 && tail >= -1){
        cout << "Elem can't be inserted from head" << endl;
    } else {
        array[head--] = elem;
        cout << elem << " inserted into position " << head + 1 << endl;
    }
}
void Dequeue::enqueueTail(int elem){
    if(!isFull()){
        array[++tail] = elem;
        return;
    }
    cout << "Queue is full;" << endl;
}

int Dequeue::dequeueHead(){
    if(!isEmpty()){
        int popElem = array[++head];
        array[head] = -1;
        return popElem;
    }
    cout << "Queue is empty;" << endl;
    return -1;

}
int Dequeue::dequeueTail(){
    if(!isEmpty()){
        int popElem = array[tail];
        array[tail--] = -1;
        return popElem;
    }
    cout << "Queue is empty;" << endl;
    return -1;
}



int main()
{
    Dequeue q1(5);

    q1.enqueueTail(10);
    q1.enqueueTail(15);


    cout << q1.dequeueHead() << endl;
    cout << q1.dequeueTail() << endl;

    q1.enqueueHead(5);
    q1.enqueueTail(100);
    q1.enqueueHead(20);

    // cout << q1.isFull() << endl;

    // cout << q1.remove() << endl;

    // // q1.remove();
    // // q1.remove();
    // // q1.remove();
    // // q1.remove();
    // // q1.remove(); // Should see an errror on this

    // q1.insert(30);

    // q1.remove();
    // q1.remove();
    // q1.remove();
    // q1.remove();
    // q1.remove();
    // q1.remove();

    return 0;

}
