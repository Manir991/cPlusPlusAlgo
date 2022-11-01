/*
- Insertion of node is usually at the end of the BST after comparing it with each nodes
- Recursive and Iterative version presented below
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

Node* insertNode(Node* ptr, int key);
Node* deleteNode(Node* ptr, int key);
Node* insertNodeIter(Node* ptr, int key);
void inorder(Node* ptr);

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
    // Node *root = new Node(30);
    // Node *n2 = new Node(15);
    // Node *n3 = new Node(50);
    // Node *n4 = new Node(10);
    // Node *n5 = new Node(20);
    // Node *n6 = new Node(40);
    // Node *n7 = new Node (60);

    // root->left = n2;
    // root->right = n3;
    // n2->left = n4;
    // n2->right = n5;
    // n3->left = n6;
    // n3->right = n7;
    // ptr=root;

    ptr = insertNodeIter(ptr, 30);
    insertNodeIter(ptr, 60);
    insertNode(ptr, 50);
    insertNode(ptr, 15);
    insertNode(ptr, 20);
    insertNode(ptr, 10);
    insertNode(ptr, 40);
    inorder(ptr);

    return 0;
}

Node* insertNode(Node* ptr, int key)
{
    // Base Case
    if(!ptr){
        Node* n = new Node(key);
        return n;
    }
    if(ptr->num == key){
        return nullptr;
    }
    // Move to left node
    if(key < ptr->num){
        ptr->left = insertNode(ptr->left, key);
    }
    else{
        ptr->right = insertNode(ptr->right, key);
    }
    return ptr;
}

Node* insertNodeIter(Node* ptr, int key)
{
    int nodePtr{0}; // left = -1, right = 1;
    while(ptr){
        if(key == ptr->num){
            cout << "Duplicate found" << endl;
            return nullptr;
        }
        // Left node
        if(key < ptr->num){
            if(ptr->left == nullptr){
                nodePtr = -1;
                break;
            }
            ptr=ptr->left;
        }
        // Right node
        else{
            if(ptr->right == nullptr){
                nodePtr = 1;
                break;
            }
            ptr=ptr->right;
        }
    }
    Node* n = new Node(key);
    // Left pointer
    if(nodePtr == -1){
        ptr->left = n;
    }
    // Right pointer
    else if(nodePtr == 1){
        ptr->right = n;
    }
    else{
        ptr = n;
    }
    return ptr;
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
