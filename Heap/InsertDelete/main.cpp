#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Deleting 1 node at a time
int deleteNode(vector<int>& heap, int tail)
{
    // Starting index = heap[0]
    // Ending index = heap[tail]
    swap(heap[0], heap[tail]);

    int i{0}, j{2*i+1}; //left child node
    while(j < tail - 1)
    {
        // Find max between leftchild and rightchild
        if((j+1 < tail-1) && heap[j] < heap[j+1]){
            j = j+1; // right child
        }
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

// Inserting one node at a time
void insertNode(vector<int>& heap, int tail)
{
    int i{tail};
    int parent = tail % 2 == 0?(tail/2)-1:(tail/2);
    while(i > 0 && heap[i] > heap[parent]){
        swap(heap[i], heap[parent]);
        i = parent;
        parent = parent % 2 == 0?(parent/2)-1:(parent/2);
    }
}

void print(vector<int>& heap)
{
  // Print all elems
    for (int i{0}; i < heap.size(); i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> maxHeap{10,30,25,5,40,20,35};
    for(int i = 1; i < maxHeap.size(); i++){
        insertNode(maxHeap, i);
    }
    print(maxHeap);
    for(int i = maxHeap.size()-1; i >= 0; i--){
        cout << deleteNode(maxHeap, i) << endl;
    }
    print(maxHeap);

    return 0;
}

