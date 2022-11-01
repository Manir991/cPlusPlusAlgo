#include <iostream>
#include <stack>

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

int inorderIndex(int *inorder, int elem, int inStart, int inEnd);
Node* inorderPreorder(int* inorder, int* preorder, int start, int end);
void inorderIter(Node* ptr);

int main()
{
    Node* ptr{nullptr};
    int inorder[] = {4,2,5,1,6,3,7};
    int preorder[] = {1,2,4,5,3,6,7};

    ptr = inorderPreorder(inorder, preorder, 0, (sizeof(inorder)/sizeof(inorder[0]))-1);

    inorderIter(ptr);


    return 0;

}

void inorderIter(Node* ptr)
{
    stack<Node*> nodeStk;
    // Base Condition
    if(!ptr){
        return;
    }
    while(!nodeStk.empty() || ptr){
        if(ptr){
            nodeStk.push(ptr);
            ptr=ptr->left;
        }
        else{
            Node* n = nodeStk.top();
            nodeStk.pop();
            cout << n->num << " ";
            ptr = n->right;
        }
    }
    cout << endl;
}

Node* inorderPreorder(int* inorder, int* preorder, int start, int end)
{
    static int preIndex{0};
    // Base Condition
    if(start > end){
        return nullptr;
    }

    Node* newNode = new Node(preorder[preIndex++]);

    // Reaching leaf nodes
    if(start == end){
        return newNode;
    }

    // Find elem in inorder array
    int inIndex = inorderIndex(inorder, newNode->num, start, end);

    newNode->left = inorderPreorder(inorder, preorder, start, inIndex-1);
    newNode->right = inorderPreorder(inorder, preorder, inIndex+1, end);

    return newNode;
}

int inorderIndex(int *inorder, int elem, int inStart, int inEnd)
{
    for(int i = inStart; i <= inEnd; i++){
        if(inorder[i] == elem){
            return i;
        }
    }
    return -1;
}
