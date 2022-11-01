// Applying concept of Dequeue using Linked List

#include <iostream>

using namespace std;

class Node{
    public:
        int num;
        Node *next{nullptr};
        // Constructor
        Node(int num){
            this->num = num;
            next = {nullptr};
        }
};

class Dequeue{
    private:
        int size{0};
        int elemsInserted{0};
        Node* head{nullptr};
        Node* tail{nullptr};

    public:
        // Constructor
        Dequeue(int size){
            this->size = size;
        }
        // Destructor
        ~Dequeue(){
            Node *tmp = head->next;
            while(tmp != nullptr){
                delete head;
                head = tmp;
                tmp = tmp->next;
                elemsInserted--;
            }
            delete head; head = nullptr; tail = nullptr;
            cout << "Size of " << size << " released from memory" << endl;
        }

        bool isEmpty();
        bool isFull();
        void enqueueHead(int elem);
        void enqueueTail(int elem);
        int dequeueHead();
        int dequeueTail();
};

bool Dequeue::isEmpty(){
    if(head == nullptr && tail == nullptr){
        return 1;
    }
    return 0;
}

bool Dequeue::isFull(){
    if(elemsInserted == size){
        return 1;
    }
    return 0;
}

void Dequeue::enqueueTail(int elem){
    if(!isFull()){
        Node* n = new Node(elem);
        if(isEmpty()){
            head = n; tail = n;
        }
        else{
            tail->next = n;
            tail = n; // Tail moved to appended elem
        }
        elemsInserted++;
        cout << elem << " inserted on tail end" << endl;
    }
    else{
        cout << "Queue full" << endl;
    }
}
void Dequeue::enqueueHead(int elem){
    if(!isFull()){
        Node *n = new Node(elem);
        if(isEmpty()){
            head = n; tail = n;
        }
        else{
            n->next = head;
            head = n;
        }
        elemsInserted++;
        cout << elem << " inserted on head end" << endl;
    }
    else{
        cout << "Queue full" << endl;
    }
}
int Dequeue::dequeueHead(){
    int pop{-1};
    if(head == tail){
        pop = head->num;
        delete head;
        head = nullptr; tail = nullptr;
        elemsInserted--;
    }
    else if(head != nullptr){
        Node* tmp = head->next;
        pop = head->num;
        delete head;
        head = tmp;
        elemsInserted--;
    }
    else{
        cout << "Cannot pop elem from head" << endl;
    }
    return pop;
}

int Dequeue::dequeueTail(){
    int pop{-1};
    if(head == tail){
        pop = head->num;
        delete head;
        head = nullptr; tail = nullptr;
        elemsInserted--;
    }
    else if(tail != nullptr){
        // Iterate all the way to node->next = tail
        Node* tmp = head;
        while(tmp->next != tail && tmp->next != nullptr){
            tmp=tmp->next;
        }
        pop = tail->num;
        delete tail;
        tail = tmp;
        elemsInserted--;
    }
    else{
        cout << "Cannot pop elem from tail" << endl;
    }
    return pop;
}




int main()
{
    Dequeue q1(5);

    q1.enqueueHead(10);
    q1.enqueueTail(15);


    cout << q1.dequeueHead() << endl;
    cout << q1.dequeueTail() << endl;

    q1.enqueueHead(5);
    q1.enqueueTail(100);
    q1.enqueueHead(20);

    return 0;
}

