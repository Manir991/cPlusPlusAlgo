/*
- Array Queues are always ideal to be Circular Queues
- In a normal queue, the head and tail pointer and used for O(1) insert and pop operation
- With every element being popped out, head pointer is moved forward
- With every element to be inserted, tail pointer is increamented and moved
- If tail pointer == size - 1 of array, then queue is full
- If head pointer == tail pointer, queue is empty
    - In this case, best approach would be to reset the position of the pointers to the beginning
- But with every element being taken off with the head pointer, those empty indexes cannot be utilized,
- i.e. if the head == tail, the notion is that the array is empty but cannot be utilized FROM that position itself

*/

#include <iostream>

using namespace std;

class Node
{
    public:
        int num{};
        Node* next{nullptr};
        // Constructor
        Node(int num){
            this->num = num;
        }
};

class Queue
{
    public:
        int nodesInserted{0};
        int size{0};
        Node *head{nullptr};
        Node *tail{nullptr};

        // Constructor
        Queue(int size){
            this->size = size;
        }
        // Destructor
        ~Queue(){
            cout << "List of size " << size << " released" << endl;
        }

        // Methods
        bool isEmpty();
        bool isFull();
        void insert(int elem);
        int remove();
        int first(); int last();
};

void Queue::insert(int elem){
    if(isFull()){
        cout << "Queue full" << endl;
        return;
    }
    Node *n = new Node(elem);
    if(isEmpty()){
        head = n;
        tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
    nodesInserted++;
    cout << "Inserted " << elem << " at position " << nodesInserted << endl;
    return;
}

int Queue::remove(){
    if(isEmpty()){
        cout << "List empty" << endl;
        return -1;
    }
    int poppedElem{};
    // Condition for one node only
    if(head->next == nullptr){
        poppedElem = head->num;
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *tmp = head->next;
        poppedElem = head->num;
        delete head;
        head = tmp;
    }
    nodesInserted--;
    return poppedElem;
}

int Queue::first(){
    if(isEmpty()){
        cout << "Queue Empty" << endl;
        return -1;
    }
    return head->num;
}

int Queue::last(){
    if(isEmpty()){
        cout << "Queue Empty" << endl;
        return -1;
    }
    return tail->num;
}

bool Queue::isEmpty(){
    // Head and Tail in the same position
    if((head == nullptr && tail == nullptr)){
        return true;
    }
    return false;
}

bool Queue::isFull(){
    if(nodesInserted == size){
        return 1;
    }
    return 0;
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

    // q1.remove();
    // q1.remove();
    // q1.remove();
    // q1.remove();
    // q1.remove(); // Should see an errror on this

    q1.insert(30);

    q1.remove();
    q1.remove();
    q1.remove();
    q1.remove();
    q1.remove();
    q1.remove();

    return 0;
}
