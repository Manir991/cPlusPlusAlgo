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

Node* deleteNode(Node* ptr, int key);
void inorder(Node* ptr);
int height(Node* ptr);
Node* inPred(Node* ptr);
Node* inSuccess(Node* ptr);
Node* inSuccess(Node* ptr);

int main()
{

    // Balanced Node
    /*
    *         30
    *       /    \
    *    20         40
    *   /  \       /  \
    * 10    25   35    45
    *                  /
    *                42
    *                  \
    *                   43
    *
    *         10
    *            \
    *             90
    *             /
    *            20
    *             \
    *             80
    *             /
    *            30
    *             \
    *             70
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

    inorder(ptr);
    cout << endl;
    deleteNode(ptr, 9);
    inorder(ptr);
    cout << endl;


    return 0;
}

Node* deleteNode(Node* ptr, int key)
{
    Node* inorder{nullptr};
    if(!ptr){
        return nullptr;
    }
    // leaf node
    if(key==ptr->num && !ptr->left && !ptr->right){
        delete ptr; ptr=nullptr; return ptr;
    }
    // move to left node
    else if(key < ptr->num){
        ptr->left = deleteNode(ptr->left, key);
    }
    // move to right node
    else if(key > ptr->num){
        ptr->right = deleteNode(ptr->right, key);
    }
    // if at the node, analyse for child nodes
    else{
        if(height(ptr->left) > height(ptr->right)){
            inorder = inPred(ptr);
            ptr->num = inorder->num; // exchange values
            ptr->left = deleteNode(ptr->left, inorder->num);
        }
        else{
            inorder = inSuccess(ptr);
            ptr->num = inorder->num; // exchange values
            ptr->right = deleteNode(ptr->right, inorder->num);
        }
    }
    return ptr;
}

int height(Node* ptr)
{
    if(!ptr){
        return 0;
    }
    return 1 + max(height(ptr->left), height(ptr->right));
}

Node* inPred(Node* ptr)
{
    // Base
    ptr = ptr->left; // move to left
    while(ptr->right != nullptr){
        ptr=ptr->right;
    }
    return ptr;
}

Node* inSuccess(Node* ptr)
{
    // Base
    ptr = ptr->right; // move to right
    while(ptr->left != nullptr){
        ptr=ptr->left;
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
