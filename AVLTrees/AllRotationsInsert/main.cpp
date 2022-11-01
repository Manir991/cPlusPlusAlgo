#include <iostream>

using namespace std;

class Node{
    public:
        int num;
        int height;
        Node* left;
        Node* right;

    Node(int num)
    {
        this->num = num;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
    ~Node(){};
};

void inorder(Node* ptr)
{
    // Base Case
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

Node* inorderPred(Node* ptr)
{
    ptr = ptr->left->right ? ptr->left->right : nullptr;
    return ptr;
}

Node* inorderSuccess(Node* ptr)
{
    ptr = ptr->right->left ? ptr->right->left : nullptr;
    return ptr;

}

int bf(Node* ptr)
{
    if(!ptr){
        return 0;
    }
    int leftChild{0}, rightChild{0};
    // bf = leftSub - rightSub;
    leftChild = ptr && ptr->left ? ptr->left->height : 0;
    rightChild = ptr && ptr->right ? ptr->right->height : 0;

    return leftChild - rightChild;
}

int height(Node* ptr)
{
    // Base Case
    if(!ptr){
        return 0;
    }
    // Leaf Condition
    if(!ptr->left && !ptr->right){
        return 1;
    }
    return 1 + max(height(ptr->left), height(ptr->right));
}

Node* llRotate(Node* ptr)
{
    Node* ptrL = ptr && ptr->left ? ptr->left : nullptr;
    Node* ptrLR = ptr && ptr->left && ptr->left->right ? ptr->left->right : nullptr;
    if(ptrL){
        ptrL->right = ptr;
    }
    ptr->left = ptrLR;

    // Update heights
    ptr->height = height(ptr);
    ptrL->height = height(ptrL);

    ptr = ptrL;
    return ptr;
}

Node* rrRotate(Node* ptr)
{
    Node* ptrR = ptr && ptr->right ? ptr->right : nullptr;
    Node* ptrRL = ptr && ptr->right && ptr->right->left ? ptr->right->left : nullptr;
    if(ptrR){
        ptrR->left = ptr;
    }
    ptr->right = ptrRL;
    // Update heights
    ptr->height = height(ptr);
    ptrR->height = height(ptrR);

    ptr = ptrR;
    return ptr;
}

Node* lrRotate(Node* ptr)
{
    Node* ptrRoot = inorderPred(ptr);
    Node* leftptrChild = ptr->left;

    ptr->left = ptrRoot->right ? ptrRoot->right : nullptr; //CR
    leftptrChild->right = ptrRoot->left ? ptrRoot->left : nullptr; //CL

    ptrRoot->left = leftptrChild;
    ptrRoot->right = ptr;

    // Update heights
    ptrRoot->height = height(ptrRoot);
    ptr->height = height(ptr);

    ptr = ptrRoot;
    return ptr;

}

Node* rlRotate(Node* ptr)
{
    Node* ptrRoot = inorderSuccess(ptr);
    Node* rightptrChild = ptr->right;

    ptr->right = ptrRoot->left ? ptrRoot->left : nullptr; //CR
    rightptrChild->left = ptrRoot->right ? ptrRoot->right : nullptr; //CL

    ptrRoot->right = rightptrChild;
    ptrRoot->left = ptr;

    // Update heights
    ptrRoot->height = height(ptrRoot);
    ptr->height = height(ptr);

    ptr = ptrRoot;
    return ptr;

}


Node* insert(Node* ptr, int key)
{
    // Base Condition
    if(!ptr){
        // Node Creation
        Node* n = new Node(key);
        return n;
    }
    // Move to left subtree
    if(key < ptr->num){
        ptr->left = insert(ptr->left, key);
    }
    // Move to right subtree
    else{
        ptr->right = insert(ptr->right, key);
    }

    // Height Balancing update
    ptr->height = height(ptr);
    if(bf(ptr) == 2 && bf(ptr->left) == 1){
        ptr = llRotate(ptr);
    }
    else if(bf(ptr) == -2 && bf(ptr->right) == -1){
        ptr = rrRotate(ptr);
    }
    else if(bf(ptr) == 2 && bf(ptr->left) == -1){
        ptr = lrRotate(ptr);
    }
    else if(bf(ptr) == -2 && bf(ptr->right) == 1){
        ptr = rlRotate(ptr);
    }

    return ptr;

}

int main()
{
    Node* ptr{nullptr};
    
    int elems[] {10,20,30,25,28,27,5};
    // int elems[] {20,10,15};
    int size = sizeof(elems)/ sizeof(elems[0]);
    for(int i = 0; i < size; i++){
        ptr = insert(ptr, elems[i]);
    }

    inorder(ptr);
    cout << endl;
    return 0;
}
