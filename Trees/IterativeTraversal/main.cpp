#include <iostream>
#include <stack>
#include <vector>

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

void inorder(Node*, vector<int>&);
void preorder(Node*, vector<int>&);
void postorder(Node*, vector<int>&);
void display(vector<int>&);

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

    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    ptr=root;

    vector<int> result;
    postorder(ptr, result);
    display(result);

    return 0;
}

void display(vector<int>& result)
{
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}

void inorder(Node* ptr, vector<int>& result)
{
    //Stack to push all nodes during iteration
    stack<Node*> stk;
    //Base Condition
    if(ptr==nullptr){
        return;
    }
    while(!stk.empty() || ptr != nullptr){
        if(ptr){
            stk.push(ptr);
            ptr = ptr->left;
        }
        else{
            Node* n = stk.top();
            stk.pop();
            result.push_back(n->num);
            ptr = n->right;
        }
    }
}

void preorder(Node* ptr, vector<int>& result)
{
    stack<Node*> stk;
    if(ptr == nullptr){
        return;
    }
    while(!stk.empty() || ptr != nullptr){
        if(ptr){
            stk.push(ptr);
            result.push_back(ptr->num);
            ptr = ptr->left;
        }
        else{
            Node* n = stk.top();
            stk.pop();
            ptr = n->right;
        }
    }
}

void postorder(Node* ptr, vector<int>& result)
{
    // Address pointer
    long long int memID{};
    // Base Condition
    if(!ptr){
        return;
    }
    stack<long long int> nodeStk;
    while(!nodeStk.empty() || ptr){
        if(ptr){
            nodeStk.push((long long int)ptr);  // Typecasting to long long int
            ptr = ptr->left;
        }
        else{
            memID = nodeStk.top();  // Address of node
            nodeStk.pop();
            if(memID > 0){
                nodeStk.push(-memID); // Typecasted to long long int and pushed
                ptr = ((Node*)memID)->right;    // Typecasted to Node* and moved to right
            }
            else{
                result.push_back(((Node*)(-1*memID))->num);
                ptr == nullptr;
            }
        }
    }
}

