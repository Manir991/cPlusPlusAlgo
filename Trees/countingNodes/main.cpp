#include <iostream>
#include <queue>

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

int totalNodes(Node* ptr);
int totalNodesIter(Node *ptr);
int leafNodes(Node* ptr);
int internalNodes(Node *ptr);
int strictNodes(Node *ptr);
int oneEdge(Node* ptr);


int main()
{
    // Balanced Node
    Node *ptr {nullptr};
    Node *root = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node (7);

    root->right = n2;
    n2->left = n3;
    n2->right = n4;
    n4->left = n5;
    n5->right = n6;
    n6->left = n7;
    ptr=root;

    cout << oneEdge(ptr) << flush;
    cout << endl;

    return 0;
}

// Total number of nodes recursive
int totalNodes(Node* ptr)
{
    // Base Case
    if(!ptr){
        return 0;
    }
    return 1 + totalNodes(ptr->left) + totalNodes(ptr->right);
}

// Total number of nodes iterative
int totalNodesIter(Node *ptr)
{
    int count{0};
    queue<Node*> qNodes;
    if(!ptr){
        return 0;
    }
    qNodes.push(ptr);
    while(!qNodes.empty())
    {
        Node* n = qNodes.front();
        qNodes.pop(); count++;
        if(n->left){
            qNodes.push(n->left);
        }
        if(n->right){
            qNodes.push(n->right);
        }
    }
    return count;
}

// Display and Return count of all leaf nodes - external nodes
int leafNodes(Node* ptr)
{
    if(!ptr){
        return 0;
    }
    if(!ptr->left && !ptr->right){
        cout << ptr->num << " ";
        return 1;
    }
    return leafNodes(ptr->left) + leafNodes(ptr->right);

}

// Display and Return count of all internal nodes Degree[1] or Degree[2]
int internalNodes(Node *ptr)
{
    if(!ptr){
        return 0;
    }
    // Internal Nodes
    if(ptr->left || ptr->right){
        cout << ptr->num << " ";
        return 1 + internalNodes(ptr->left) + internalNodes(ptr->right);
    }
    return 0;
}

// Display and Return count of all internal nodes with Degree[2]
int strictNodes(Node *ptr)
{
    if(!ptr){
        return 0;
    }
    if(ptr->left && ptr->right){
        return 1 + strictNodes(ptr->left) + strictNodes(ptr->right);
    }
    else{
        return strictNodes(ptr->left) + strictNodes(ptr->right);
    }
    return 0;
}

// Display and Return count of exactly nodes with 1 edge Degree[1]
int oneEdge(Node* ptr)
{
    int leftChild{}, rightChild{};
    if(!ptr){
        return 0;
    }
    // Condition for 1 edge - use XOR condition
    if(ptr->left != nullptr ^ ptr->right != nullptr){
        return 1 + oneEdge(ptr->left) + oneEdge(ptr->right);
    }
    else{
        return oneEdge(ptr->left) + oneEdge(ptr->right);
    }
    return 0;
}
