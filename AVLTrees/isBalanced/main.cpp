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

int isHeightBalanced(Node* ptr);

int main()
{

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

    // BST Node
    /*
    *          30
    *       /      \
    *    20         40
    *   /  \       /  \
    * 10    25   35    45
    *                  /
    *                42
    *                  \
    *                   43
    *
    */

    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n7->left = n8;
    // n8->right = n9;
    ptr=root;

    if(isHeightBalanced(ptr) == -1){
        cout << "Not Balanced" << endl;
    }
    else{
        cout << "Balanced" << endl;
    }
    return 0;
}


int isHeightBalanced(Node* ptr)
{
    int leftChild, rightChild;
    // Base Case
    if(!ptr){
        return 0;
    }
    // Leaf Node
    if(!ptr->left && !ptr->right){
        return 1;
    }
    leftChild = isHeightBalanced(ptr->left);
    // Imabalanced left sub-tree
    if(leftChild == -1){
        return -1;
    }
    rightChild = isHeightBalanced(ptr->right);
    // Imbalanced right sub-tree
    if(rightChild == -1){
        return -1;
    }
    // Check for height balanced
    if(abs(leftChild - rightChild) > 1){
        return -1;
    }
    return 1+max(leftChild, rightChild);

}
