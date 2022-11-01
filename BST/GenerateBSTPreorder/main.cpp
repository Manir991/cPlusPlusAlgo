#include <iostream>
#include <stack>

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
Node* bst(int *preorder, int size);

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
    */
    Node *ptr {nullptr};
    Node *root = new Node(30);
    Node *n2 = new Node(15);
    Node *n3 = new Node(50);
    Node *n4 = new Node(10);
    Node *n5 = new Node(20);
    Node *n6 = new Node(40);
    Node *n7 = new Node (60);

    // root->left = n2;
    // root->right = n3;
    // n2->left = n4;
    // n2->right = n5;
    // n3->left = n6;
    // n3->right = n7;
    // ptr=root;

    int preorder[]{30,20,10,25,40,35,45,42,43};
    int size =sizeof(preorder) / sizeof(preorder[0]);
    ptr = bst(preorder, size);
    inorder(ptr);

    cout << endl;


    return 0;
}

Node* bst(int *preorder, int size)
{
    Node* ptr{nullptr};
    Node* root{nullptr};
    stack<Node*> stk;
    // return nullptr
    if(size < 0){
        return nullptr;
    }
    int i{1};
    Node* n = new Node(preorder[0]);    // Root node
    ptr = n; root = n;
    while(i < size){
        n = new Node(preorder[i]);
        // Move to left node
        if(preorder[i] < ptr->num){
            ptr->left = n;
            stk.push(ptr);
            ptr = n;
        }
        // Move to right node
        else{
            if(preorder[i] > (stk.top())->num){
                ptr = stk.top();
                stk.pop();
                ptr->right = n;
                ptr = n;
            }
            else{
                ptr->right = n;
                ptr=n;
            }
        }
        i++;
    }
    return root;
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


