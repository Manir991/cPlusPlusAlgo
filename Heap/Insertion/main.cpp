#include <iostream>
#include <vector>

/*
1. Heaps are COMPLETE binary trees
2. Duplicate values are allowed in HEAP
3. COMPLETE refers to when values are laid out while performing BFS,
    there shouldn't be any gaps in the indexes of an array
4. Array is used for HEAP and hence need to be a COMPLETE binary tree
5. Nodes are inserted from left to right
6. Max Heap - Parent node is >= than all of its descendants
7. Min Heap - Parent node is < than all of its descendants
8. Inserting Elements
    - Elements are usually inserted at the next available index in the array
    - Iteration is performed on that element with the parent element by index/2
    - If the element is greater than the parent, elem is swapped with the parent
9. Deleting Elements
    - Deletion is ALWAYS done at the root node and placed at the end of the array
    - Exchange the element at ROOT with last element of the array
    - Once the last elem is at the ROOT, compare the left and right childtrees of the parent node
    - Take the MAX of the two and compare that with the parent node
    - If the value > parent node, then swap
    - Keep on repeating this until the index is out of bounds
*/

using namespace std;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void insertSingleNode(vector<int> &heap, int elem)
{
    if(heap.empty()){
        heap.push_back(elem);
        return;
    }
    // Add to end of vector;
    heap.push_back(elem);

    int nodeIndex = heap.size() - 1;
    int parentIndex = (nodeIndex % 2 == 0 ? (nodeIndex/2)-1 : (nodeIndex/2));
    while(nodeIndex > 0 && elem > heap[parentIndex]){
        // Condition to swap
        swap(heap[parentIndex], heap[nodeIndex]);
        nodeIndex = parentIndex;
        // Even
        if(nodeIndex % 2 == 0){
            parentIndex = (nodeIndex / 2)-1;
        }
        // Odd
        else{
            parentIndex = (nodeIndex / 2);
        }
    }
    if(heap[nodeIndex] < elem){
        swap(heap[0], heap[1]);
    }
}

void insertNode(vector<int> &heap)
{
    int head{0}, tail{0};
    if(heap.size() > 1){
        tail++;
    }
    // Iterate via all elems O(n)
    for(int i{tail}; tail < heap.size(); i = ++tail)
    {
        // Swap between elems (log(n))
        while(i > 0 && heap[i] > heap[i%2==0?(i/2)-1:i/2]){
            swap(heap[i], heap[i%2==0?(i/2)-1:i/2]);
            i = i%2==0?(i/2)-1:i/2;
        }
    }
}


int main()
{
    vector<int> maxHeap{10,20,30,25,5,40,35};
    insertNode(maxHeap);

    // Print all elems
    for (int i{0}; i < maxHeap.size(); i++){
        cout << maxHeap[i] << " ";
    }
    cout << endl;

    return 0;
}


