/*

-- HEAPIFY APPROACH
- Heapify only works during the insertion process
- Instead of nlogn it can be reduced to n
- Trick is to start from the tail end where the leaves are
and work backwards. And always compare the node with its child nodes
as opposed to parent nodes (similar to delete operation when the lowest
priority is positioned at the highest priority position and trickeled down
wards based on comparison with child nodes)

-- TRADITIONAL APPROACH
- Traditionally, the insertion operation works by inserting elem at the leaf end
and then moving it upwards by comparing it with its parent node. Hence, log(n) time
- Deletion works by replacing the highest priority elem with last most node and comparing
the max of its child nodes and trickling it down it the parent is smaller than max(left, right).
Hence, log(n) time as well.

*/

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Insert Nodes
void Heapify(vector<int>& heap, int n)
{
    // Ignore the leaf's
    for(int i = (n/2)-1; i >= 0; i--)
    {
        int k = i;
        int j{2*i+1}; // left child
        // Compare left and right subtree
        while(j < n)
        {
            // Determine max of left and right child
            if(j+1 < n){
                if(heap[j] < heap[j+1]){
                    j = j+1;
                }
            }
            // Compare parent to child nodes
            if(heap[k] < heap[j]){
                swap(heap[k], heap[j]);
                k = j;
                j = 2*j+1; // left child
            }
            else{
                break;
            }
        }
    }
}

// Delete node and sort
int deleteNode(vector<int>&heap, int tail)
{
    // Swap with highest priority
    int i{0};  //root node
    int j{1}; //left child
    swap(heap[i], heap[tail]);

    while(j < tail)
    {
        // Derive max(leftchild, rightchild)
        if(j+1 < tail){
            if(heap[j] < heap[j+1]){
                j = j+1;
            }
        }
        // Compare parent with max(subTree)
        if(heap[i] < heap[j]){
            swap(heap[i], heap[j]);
            i = j;
            j = 2*i+1;
        }
        else{
            break;
        }
    }
    return heap[tail];

}


int main()
{
    vector<int> maxHeap{10,30,25,5,40,20,35,50,19,15};
    Heapify(maxHeap, maxHeap.size());

    // Heap Sort
    for(int i = (maxHeap.size()) - 1; i > 0; i--){
        cout << deleteNode(maxHeap, i) << endl;
    }
    cout << endl;


    return 0;
}

