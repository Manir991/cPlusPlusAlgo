#include <iostream>

using namespace std;

class Node
{
    public:
    int num;
    Node *next{nullptr};
};

/************************************/
void createList(int arr[], int size);
void printList(Node *ptr);
/*************************************/

Node *head {nullptr};

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int length = sizeof(arr) / sizeof(arr[0]);

    createList(arr, length);
    printList(head);

    return 0;
}

void createList(int arr[], int size)
{
    // Empty arr
    if(size <= 0)
    {
        return;
    }

    Node *ptr = new Node;
    ptr->num = arr[0];
    ptr->next = ptr;
    head = ptr;
    for(int i = 1; i < size; i++)
    {
        Node *n = new Node;
        n->num = arr[i];
        ptr->next = n;
        ptr=n;
    }
    ptr->next = head;
}

void printList(Node *ptr)
{
    do
    {
        cout << ptr->num << " ";
        ptr=ptr->next;
    } while(ptr != head);
    cout << endl;
    return;
}
