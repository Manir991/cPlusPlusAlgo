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


int maxHeight(Node *ptr, int& height);
int maxHeightIter(Node *ptr, int& height);

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

    root->right = n2;
    n2->left = n3;
    n2->right = n4;
    n4->left = n5;
    n5->right = n6;
    n6->left = n7;
    ptr=root;

    ptr = root;



    int h{};
    cout << maxHeightIter(ptr, h) << endl;
    return 0;

}

int maxHeight(Node* ptr, int& height)
{
    if(!ptr){
        return 0;
    }
    return 1 + max(maxHeight(ptr->left, height), maxHeight(ptr->right, height));
}

int maxHeightIter(Node* ptr, int& height)
{
    if(!ptr){
        return 0;
    }
    queue<Node*> qNodes;
    qNodes.push(ptr);

    while(!qNodes.empty()){
        int numNodes = qNodes.size();
        for(int i{}; i < numNodes; i++){
            Node* n = qNodes.front();
            qNodes.pop();
            if(n->left){
                qNodes.push(n->left);
            }
            if(n->right){
                qNodes.push(n->right);
            }
        }
        height++;
    }
    return height;
}


