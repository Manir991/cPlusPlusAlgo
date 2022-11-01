#include <iostream>

using namespace std;

class Node
{
    public:
        int num;
        int height{1};
        Node* left{nullptr};
        Node* right{nullptr};

        // Definition of Node
        Node(int num){
            this->num = num;
            height = 1;
            left = nullptr;
            right = nullptr;
        }

        ~Node(){}
};

Node* insert(Node* ptr, int num);
void inorder(Node* ptr);
int height(Node* ptr);
Node* LLOperation(Node* ptr);
int bf(Node* ptr);

int main()
{
    // int elems[] {10,20,30,25,28,27,5};
    int elems[] {10,5,2};
    int size = sizeof(elems)/ sizeof(elems[0]);

    Node* ptr{nullptr};

    for(int i{0}; i < size; i++){
        ptr = insert(ptr, elems[i]);
    }

    inorder(ptr);
    cout << endl;

    return 0;
}

Node* insert(Node* ptr, int num)
{
    if(!ptr){
        Node* n = new Node(num);
        return n;
    }
    // Move to left subtree
    if(num < ptr->num){
        ptr->left = insert(ptr->left, num);
    }
    else{
        ptr->right = insert(ptr->right, num);
    }
    // Update height across each node
    ptr->height = height(ptr);

    // Determine balance factor
    if(bf(ptr) == 2 && bf(ptr->left) == 1){
        ptr = LLOperation(ptr);
    }
    else if(bf(ptr) == -2 && bf(ptr->right) == -1){
        return nullptr;    }
    else if(bf(ptr) == 2 && bf(ptr->left) == -1){
        return nullptr;
    }
    else if(bf(ptr) == -2 && bf(ptr->right) == 1){
        return nullptr;
    }
    return ptr;
}

Node* LROperation(Node* ptr)
{
    
}

Node* RLOperation(Node* ptr)
{

}

Node* RROperation(Node* ptr)
{
    Node* ptrR = ptr && ptr->right ? ptr->right : nullptr;
    Node* ptrRL = ptr && ptr->right && ptr->right->left ? ptr->right->left : nullptr;

    if(ptrR){
        ptrR->left = ptr;
    }
    ptr->right = ptrRL;
    ptr = ptrR;
    return ptr;
}

Node* LLOperation(Node* ptr)
{
    Node* ptrL = ptr && ptr->left ? ptr->left : nullptr;
    Node* ptrLR = ptr && ptr->left && ptr->left->right ? ptr->left->right : nullptr;
    if(ptrL){
        ptrL->right = ptr;
    }
    ptr->left = ptrLR;
    ptr = ptrL;

    // Update heights
    ptr->height = height(ptr);
    ptr->left->height = height(ptr->left);
    return ptr;
}

int bf(Node* ptr)
{
    int lSub, rSub;
    lSub = ptr && ptr->left ? ptr->left->height : 0;
    rSub = ptr && ptr->right ? ptr->right->height : 0;

    return lSub - rSub;
}

void inorder(Node* ptr)
{
    if(!ptr){
        return;
    }
    if(!ptr->left && !ptr->right){
        cout << ptr->num << " ";
        return;
    }
    inorder(ptr->left);
    cout << ptr->num << " ";
    inorder(ptr->right);
}

int height(Node* ptr)
{
    if(!ptr){
        return 0;
    }
    if(!ptr->left && !ptr->right){
        return 1;
    }
    return 1 + max(height(ptr->left), height(ptr->right));
}
