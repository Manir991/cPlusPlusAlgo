#include <iostream>
#include <stack>
#include <iomanip>

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

void inorder(Node* ptr);
bool isBST(Node* ptr);

int main()
{

    // BST Node
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
    */
    Node *ptr {nullptr};
    Node *root = new Node(30);
    Node *n2 = new Node(20);
    Node *n3 = new Node(40);
    Node *n4 = new Node(10);
    Node *n5 = new Node(25);
    Node *n6 = new Node(35);
    Node *n7 = new Node(45);
    Node *n8 = new Node(42);
    Node *n9 = new Node(43);

    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n7->left = n8;
    n8->right = n9;
    ptr=root;

    cout << boolalpha;
    cout << isBST(ptr) << endl;
    return 0;
}

bool isBST(Node* ptr)
{
    bool leftChild, rightChild;
    if(!ptr){
        return true;
    }
    // Leaf Nodes
    if(ptr->left == nullptr && ptr->right == nullptr){
        return true;
    }
    // False condition for left node
    if(ptr->left && ptr->num < ptr->left->num){
        return false;
    }
    leftChild = isBST(ptr->left);
    // False condition for right node
    if(ptr->right && ptr->num > ptr->right->num){
        return false;
    }
    rightChild = isBST(ptr->right);

    return leftChild && rightChild;

}
