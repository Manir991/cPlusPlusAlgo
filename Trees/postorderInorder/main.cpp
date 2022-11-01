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
Node* inorderPostorder(int* inorder, int* preorder, int start, int end);
void postorderIter(Node* ptr);

int main()
{
    Node *ptr {nullptr};


    int inorder[] = {4,2,5,1,6,3,7};
    int postorder[] = {4,5,2,6,7,3,1};

    ptr = inorderPostorder(inorder, postorder, 0, (sizeof(inorder)/sizeof(inorder[0]))-1);
    postorderIter(ptr);

    return 0;
}

Node* inorderPostorder(int* inorder, int* postorder, int inStart, int inEnd)
{
    static int postIndex{inEnd};
    // Base Condition
    if(inStart > inEnd){
        return nullptr;
    }
    // New Node
    Node* newNode = new Node(postorder[postIndex--]);

    // Condition for returning leaf nodes
    if(inStart == inEnd){
        return newNode;
    }

    int inIndex = inorderIndex(inorder, inStart, inEnd, newNode->num);

    newNode->right = inorderPostorder(inorder, postorder, inIndex+1, inEnd);
    newNode->left = inorderPostorder(inorder, postorder, inStart, inIndex-1);

    return newNode;
}

int inorderIndex(int *inorder, int start, int end, int elem)
{
    for(int i{start}; i <= end; i++){
        if(inorder[i] == elem){
            return i;
        }
    }
    return -1;
}

void postorderIter(Node* ptr)
{
    long long int memID;
    if(!ptr){
        return;
    }
    stack<long long int> nodeAddress;
    while(ptr || !nodeAddress.empty()){
        if(ptr){
            nodeAddress.push((long long int) ptr);
            ptr = ptr->left;
        }
        else{
            memID = nodeAddress.top();
            nodeAddress.pop();
            if(memID > 0){
                nodeAddress.push(-memID);
                ptr = ((Node*)memID)->right;
            }
            else{
                cout << ((Node*)(-1*memID))->num << " ";
                ptr = nullptr;
            }
        }
    }
    cout << endl;
}

