#include <iostream>
#include <queue>

// NOTES:
// Total number of activation record on the stack = height + 1
// Total number of recursive call = Nodes of nodes + (Number of null pointers + 1) = 2n + 1

using namespace std;

class Node{
    public:
        int num;
        Node* left{nullptr};
        Node* right{nullptr};

        // Default constructor
        Node(int num){
            this->num = num;
        }
};

Node* reverseNodes(Node* ptr);
void reverseNodeIter(Node* ptr);
void inorder(Node *head);

int main()
{
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

    ptr = root;

    inorder(ptr);
    cout << endl;
    reverseNodeIter(ptr);
    inorder(ptr);

    return 0;
}

// Recursive means
Node* reverseNodes(Node* ptr)
{
    // Base Condition
    if(ptr == nullptr){
        return nullptr;
    }
    if(ptr->left == nullptr && ptr->right == nullptr){
        return ptr;
    }
    Node* leftchild = reverseNodes(ptr->left);
    Node* rightchild = reverseNodes(ptr->right);

    ptr->left = rightchild;
    ptr->right = leftchild;

    return ptr;
}

// Iteration
void reverseNodeIter(Node* ptr)
{
    // This can be achieved level order
    queue<Node*> qNodes;
    if(ptr == nullptr){
        return;
    }
    qNodes.push(ptr);
    while(!qNodes.empty())
    {
        Node* n = qNodes.front();
        qNodes.pop();

        // Swap childnodes
        Node* tmp;
        tmp = n->left;
        n->left = n->right;
        n->right = tmp;

        if(n->left){
            qNodes.push(n->left);
        }
        if(n->right){
            qNodes.push(n->right);
        }
    }
}

void inorder(Node *head)
{
    // Base case
    if(!head){
        return;
    }
    // Leaf Nodes
    if(head->left == nullptr && head->right == nullptr){
        cout << (head->num) << " ";
        return;
    }
    inorder(head->left);
    cout << (head->num) << " ";
    inorder(head->right);
}
