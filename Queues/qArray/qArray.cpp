/*
- [✓] Array Queues are always ideal to be Circular Queues
- [✓] In a normal queue, the head and tail pointer and used for O(1) insert and pop operation
- [✓] With every element being popped out, head pointer is moved forward
- [✓] With every element to be inserted, tail pointer is increamented and moved
- [✓] If tail pointer == size - 1 of array, then queue is full
- [✓] If head pointer == tail pointer, queue is empty
    - In this case, best approach would be to reset the position of the pointers to the beginning
- But with every element being taken off with the head pointer, those empty indexes cannot be utilized,
- i.e. if the head == tail, the notion is that the array is empty but cannot be utilized FROM that position itself

Circular Queue
- Head and Tail needs to be at index 0
- For every insert, Tail increments and inserts value
- For every delete, Head moves to the index and then deletes the element
- Empty - If (head + 1) % size == tail, or head == tail, queue is empty
- Full - If (tail + 1) % size == head, then queue is full

*/

#include <iostream>

using namespace std;

class Queue
{
    public:
        int size{};
        int head{0};   // index position
        int tail{0};   // index position
        int *array{nullptr};

        // Constructor
        Queue(int size){
            this->size = size;
            array = new int[size]{};
        }
        // Destructor
        ~Queue(){
            cout << "Queue of size " << size << " released" << endl;
            delete[] array;
        }

        // Methods
        void insert(int elem);
        int remove();
        int first();
        int last();
        bool isEmpty();
        bool isFull();
};

bool Queue::isEmpty(){
    if(head == tail){
        return true;
    }
    return false;
}

bool Queue::isFull(){
    if((tail + 1) % size == head){
        return true;
    }
    return false;
}

void Queue::insert(int elem){
    // Queue full
    if(!isFull()){
        tail = (tail+1) % size;
        array[tail] = elem;
        cout << elem << " inserted at position " << tail << endl;
        return;
    }
    cout << "Queue Full" << endl;
    return;
}

int Queue::remove(){
    // Queue Empty
    int popElem{};
    if(isEmpty()){
        cout << "Queue empty. Nothing to pop" << endl;
        return -1;
    }
    head = (head + 1) % size;
    popElem = array[head];
    array[head] = -1;
    return popElem;
}

int Queue::first(){
    if(!isEmpty()){
        return array[head + 1];
    }
    return -1;
}

int Queue::last(){
    if(!isEmpty()){
        return array[tail];
    }
    return -1;
}

int main()
{
    Queue q1(5);
    q1.insert(5);
    q1.insert(10);
    q1.insert(15);
    q1.insert(20);
    q1.insert(25);

    cout << q1.isFull() << endl;

    cout << q1.remove() << endl;

    q1.remove();
    q1.remove();
    q1.remove();
    q1.remove();
    q1.remove(); // Should see an errror on this

    q1.insert(30);

    return 0;
}
