#include <iostream>
#include <stack>
#include <vector>

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

// Node predecessor
Node* inPredecessor(Node* ptr)
{
    ptr = ptr->left ? ptr->left : nullptr;
    while(ptr != nullptr && ptr->right != nullptr){
        ptr = ptr->right;
    }
    return ptr;
}

Node* inPredAVL(Node* ptr)
{
    ptr = ptr->left;
    ptr = ptr && ptr->right ? ptr->right : nullptr;
    return ptr;
}

Node* inSuccessAVL(Node* ptr)
{
    ptr = ptr->right;
    ptr = ptr && ptr->left ? ptr->left : nullptr;
    return ptr;
}

// Node successor
Node* inSuccessor(Node* ptr)
{
    ptr = ptr->right ? ptr->right : nullptr;
    while(ptr != nullptr && ptr->left != nullptr){
        ptr = ptr->left;
    }
    return ptr;
}

// Balance Factor
int bf(Node* ptr){
    int lChild, rChild;
    if(!ptr){
        return  0;
    }
    lChild = ptr && ptr->left ? ptr->left->height : 0;
    rChild = ptr && ptr->right ? ptr->right->height : 0;

    return lChild - rChild;

}

// Height
int height(Node* ptr)
{
    // Base Case
    if(ptr == nullptr){
        return 0;
    }
    // Left
    if(ptr->left == nullptr && ptr->right == nullptr){
        return 1;
    }
    return 1 + max(height(ptr->left), height(ptr->right));
}

// LL Rotation
Node* ll(Node* ptr)
{
    Node* ptrL = ptr->left;
    Node* ptrLR = ptr->left && ptr->left->right ? ptr->left->right : nullptr;

    ptrL->right = ptr;
    ptr->left = ptrLR;

    // Update heights after insert/ delete
    ptr->height = height(ptr); ptrL->height= height(ptrL);
    ptr = ptrL;

    return ptr;
}

// RR Rotation
Node* rr(Node* ptr)
{
    Node* ptrR = ptr->right;
    Node* ptrRL = ptr->right && ptr->right->left ? ptr->right->left : nullptr;

    ptrR->left = ptr;
    ptr->right = ptrRL;

    // Update heights after insert/ delete
    ptr->height = height(ptr); ptrR->height= height(ptrR);
    ptr = ptrR;

    return ptr;
}

// LR Rotation
Node* lr(Node* ptr)
{
    Node* ptrL = ptr->left;
    Node* newRoot = inPredAVL(ptr);

    ptr->left = newRoot && newRoot->right ? newRoot->right : nullptr;
    ptrL->right = newRoot && newRoot->left ? newRoot->left : nullptr;

    newRoot->right = ptr;
    newRoot->left = ptrL;

    // Update heights after insert/ delete
    ptr->height = height(ptr); newRoot->height= height(newRoot);
    ptr = newRoot;

    return ptr;
}

// RL Rotation
Node* rl(Node* ptr)
{
    Node* ptrR = ptr->right;
    Node* newRoot = inSuccessAVL(ptr);

    ptr->right = newRoot && newRoot->left ? newRoot->left : nullptr;
    ptrR->left = newRoot && newRoot->right ? newRoot->right : nullptr;

    newRoot->left = ptr;
    newRoot->right = ptrR;

    // Update heights after insert/ delete
    ptr->height = height(ptr); newRoot->height= height(newRoot);
    ptr = newRoot;
    return ptr;
}


// Insert Node
Node* insertNode(Node* ptr, int elem)
{
    if(!ptr){
        Node* n = new Node(elem);
        return n;
    }
    if(elem < ptr->num){
        ptr->left = insertNode(ptr->left, elem);
    }
    else{
        ptr->right = insertNode(ptr->right, elem);
    }
    // Update height per node
    ptr->height = height(ptr);
    // AVL Balancing
    if(bf(ptr) == 2 && bf(ptr->left) == 1){
        //LLRotation;
        ptr = ll(ptr);
    }
    else if(bf(ptr) == -2 && bf(ptr->right) == -1){
        //RRRotation
        ptr = rr(ptr);
    }
    else if(bf(ptr) == 2 && bf(ptr->left) == -1){
        //LRRotation
        ptr = lr(ptr);
    }
    else if(bf(ptr) == -2 && bf(ptr->right) == 1){
        //RLRotation
        ptr = rl(ptr);
    }
    return ptr;
}

// Delete Node
Node* deleteNode(Node* ptr, int elem)
{
    // Base Case
    if(ptr == nullptr){
        return nullptr;
    }
    // Leaf Node
    if(ptr->left == nullptr && ptr->right == nullptr){
        delete ptr;
        return nullptr;

    }
    // Left Node
    if(elem < ptr->num){
        ptr->left = deleteNode(ptr->left, elem);
    }
    // Right Node
    else if(elem > ptr->num){
        ptr->right = deleteNode(ptr->right, elem);
    }
    else{
        // Elem == to present node
        if(height(ptr->left) >= height(ptr->right)){
            Node* inPreNode = inPredecessor(ptr);
            ptr->num = inPreNode->num;
            ptr->left = deleteNode(ptr->left, inPreNode->num);
        }
        else{
            Node* inSuccessNode = inSuccessor(ptr);
            ptr->num = inSuccessNode->num;
            ptr->right = deleteNode(ptr->right, inSuccessNode->num);
        }
    }
    ptr->height = height(ptr);
    // AVL Balancing
    if(bf(ptr) == 2 && bf(ptr->left) == 1){
        //LLRotation;
        ptr = ll(ptr);
    }
    else if(bf(ptr) == -2 && bf(ptr->right) == -1){
        //RRRotation
        ptr = rr(ptr);
    }
    else if(bf(ptr) == 2 && bf(ptr->left) == -1){
        //LRRotation
        ptr = lr(ptr);
    }
    else if(bf(ptr) == -2 && bf(ptr->right) == 1){
        //RLRotation
        ptr = rl(ptr);
    }

    return ptr;
}

// Inorder iteration
void inorderStk(Node* ptr)
{
    stack<Node*> stk;

    if(!ptr){
        return;
    }

    // Push root into stack
    while(ptr || !stk.empty())
    {
        if(ptr){
            ptr->height = height(ptr);
            stk.push(ptr);
            ptr = ptr->left;
        }
        else{
            Node* n = stk.top();
            cout << n->num << " ";
            stk.pop();
            ptr = n->right;
        }

    }
    cout << endl;
}
// Postorder iteration
void postorderStk(Node* ptr)
{
    stack<long long int> stk;
    if(!ptr){
        return;
    }

    while(ptr || !stk.empty())
    {
        if(ptr)
        {
            stk.push((long long int)ptr);
            ptr = ptr->left;
        }
        else
        {
            long long int n = stk.top();
            stk.pop();
            if(n > 0){
                stk.push(-n);
                ptr = ((Node*)n)->right;
            }
            else{
                cout << ((Node*)(-1*n))->num << " ";
                ptr = nullptr;
            }
        }
    }
    cout << endl;
}

int main()
{
   // BST Node
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
    // Node *root = new Node(30);
    // Node *n2 = new Node(20);
    // Node *n3 = new Node(40);
    // Node *n4 = new Node(10);
    // Node *n5 = new Node(25);
    // Node *n6 = new Node(35);
    // Node *n7 = new Node(45);
    // Node *n8 = new Node(42);
    // Node *n9 = new Node(43);

    // root->left = n2;
    // root->right = n3;
    // n2->left = n4;
    // n2->right = n5;
    // n3->left = n6;
    // n3->right = n7;
    // n7->left = n8;
    // n8->right = n9;
    // ptr=root;

    int elems[] {10,20,30,25,28,27,5};
    // int elems[] {20,10,15};
    int size = sizeof(elems)/ sizeof(elems[0]);
    for(int i = 0; i < size; i++){
        ptr = insertNode(ptr, elems[i]);
    }


    inorderStk(ptr);
    postorderStk(ptr);
    cout << endl;

    ptr = deleteNode(ptr, 28);
    ptr = deleteNode(ptr, 25);
    inorderStk(ptr);
}
