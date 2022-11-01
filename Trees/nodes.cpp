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


int main()
{

    // Balanced Node
    /*
    *       1
    *     /   \
    *    2     3
    *   / \   / \
    *  4   5 6   7
    *
    */
    Node *ptr {nullptr};
    Node *root = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node (7);

    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    ptr=root;


    // Skewed Node
    /*
    *       1
    *     /   \
    *    2     3
    *   /       \
    *  4         5
    *   \       /
    *    6     7
    */

    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n3->right = n5;
    n4->right = n6;
    n5->left = n7;
    ptr=root;

    // Skewed Node
    /*
    *       1
    *     /   \
    *    2     3
    *     \   /
    *     4   5
    *     /   \
    *    6     7
    *
    */

    root->left = n2;
    root->right = n3;
    n2->right = n4;
    n3->left = n5;
    n4->left = n6;
    n5->right = n7;
    ptr=root;

    // Skewed Node
    /*
    *       1
    *        \
    *          2
    *         / \
    *       3     4
    *            /
    *          5
    *           \
    *            6
    *            /
    *           7
    */

    root->right = n2;
    n2->left = n3;
    n2->right = n4;
    n4->left = n5;
    n5->right = n6;
    n6->left = n7;
    ptr=root;

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
}
