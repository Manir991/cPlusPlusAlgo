#include <iostream>
#include <vector>
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

void inorder(Node*, vector<int>&);
void preorder(Node*, vector<int>&);
void postorder(Node*, vector<int>&);
void levelorder(Node*, vector<int>&);
void nodeHeightIterative(Node*, int&);
int maxHeightRecursive(Node*);
void display(vector<int> &);


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

    vector<int> result;

    cout << "Inorder" << endl;
    inorder(ptr, result);
    display(result);

    cout << "Preorder" << endl;
    preorder(ptr, result);
    display(result);

    cout << "Postorder" << endl;
    postorder(ptr, result);
    display(result);

    cout << "Levelorder" << endl;
    levelorder(ptr, result);
    display(result);

    cout << "Height" << endl;
    int h{};
    h = maxHeightRecursive(ptr);
    cout << h << endl;
    // cout << h << endl;

    return 0;
}

int maxHeightRecursive(Node* head)
{
    // Base Condition
    if(!head){
        return 0;
    }
    return 1 + max(maxHeightRecursive(head->left), maxHeightRecursive(head->right));
}

void maxHeightIterative(Node* head, int& height)
{
    queue<Node*> qNodes;
    if(head == nullptr){
        return;
    }
    qNodes.push(head);
    while(!qNodes.empty())
    {
        int size = qNodes.size();

        // Iterate via that level of tree
        for(int i{}; i < size; i++){
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
}

void display(vector<int> &result)
{
    for(int i{}; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    result.clear(); // clean vector and then add elems
}

void inorder(Node *head, vector<int>& result)
{
    // Base case
    if(!head){
        return;
    }
    // Leaf Nodes
    if(head->left == nullptr && head->right == nullptr){
        result.push_back(head->num);
        return;
    }
    inorder(head->left, result);
    result.push_back(head->num);
    inorder(head->right, result);
}

void preorder(Node* head, vector<int>& result)
{
    // Base Case
    if(!head){
        return;
    }
    // Leaf Nodes
    if(head->left == nullptr && head->right == nullptr){
        result.push_back(head->num);
        return;
    }
    result.push_back(head->num);
    preorder(head->left, result);
    preorder(head->right, result);
}

void postorder(Node *head, vector<int>& result)
{
    if(!head){
        return;
    }
    // Leaf Nodes
    if(head->left == nullptr && head->right == nullptr){
        result.push_back(head->num);
        return;
    }
    postorder(head->left, result);
    postorder(head->right, result);
    result.push_back(head->num);
}

void levelorder(Node *head, vector<int>& result)
{
    queue<Node> qNodes;
    if(head == nullptr){
        return;
    }

    qNodes.push(*head);
    while(!qNodes.empty())
    {
        Node n = qNodes.front();
        result.push_back(n.num);
        qNodes.pop();
        // Left child exists
        if(n.left){
            qNodes.push(*n.left);
        }
        // Right child exists
        if(n.right){
            qNodes.push(*n.right);
        }
    }
}


