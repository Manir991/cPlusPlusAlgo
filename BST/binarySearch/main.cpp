/*
- All elements in BST are placed in ascending order from left to right and top to bottom
- All elements are to be UNIQUE within each node aka no duplicates allowed
- BST are better represented in LinkedList format and NOT in array format
- Inorder traversal can be performed to traverse the elements in ascending order
*/

#include <iostream>

using namespace std;

class Node{
    public:
        int num;
        Node* left{nullptr};
        Node* right{nullptr};

        // Constructor
        Node(int num){
            this->num = num;
            left = nullptr;
            right = nullptr;
        }
        ~Node(){}
};

Node* binarySearch(Node* ptr, int key);
Node* binarySearchIter(Node* ptr, int key);

int main()
{

    // Balanced Node
    /*
    *       30
    *   15       50
    * 10   20   40   60
    *
    */
    Node *ptr {nullptr};
    Node *root = new Node(30);
    Node *n2 = new Node(15);
    Node *n3 = new Node(50);
    Node *n4 = new Node(10);
    Node *n5 = new Node(20);
    Node *n6 = new Node(40);
    Node *n7 = new Node (60);

    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    ptr=root;


    Node* elemNode = binarySearchIter(ptr, 60);
    if(elemNode){
        cout << elemNode->num << endl;
    }
    else{
        cout << "not found" << endl;
    }
    return 0;
}

Node* binarySearch(Node* ptr, int key)
{
    // Base Condition
    if(!ptr){
        return nullptr;
    }
    if(ptr->num == key){
        return ptr;
    }
    else if(key < ptr->num){
        return binarySearch(ptr->left, key);
    }
    else{
        return binarySearch(ptr->right, key);
    }
    return nullptr;
}

Node* binarySearchIter(Node* ptr, int key)
{
    while(ptr)
    {
        if(key == ptr->num){
            return ptr;
        }
        else if (key < ptr->num){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    return nullptr;
}

void inorder(Node* ptr)
{
    // Base Case
    if(!ptr){
        return;
    }
    // Leaf
    if(!ptr->left && !ptr->right){
        cout << ptr->num << " ";
        return;
    }
    inorder(ptr->left);
    cout << ptr->num << " ";
    inorder(ptr->right);
}
