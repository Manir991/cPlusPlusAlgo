#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
- Bubble sort is kinda like the bubble effect when a pebble is thrown into water i.e. head
- Smaller elems bubble up at the top and heavier elements settle down at the bottom i.e. tail
- Time Complexity - O(n^2)
- Space Complexity - O(n) - Size of elems
- Adaptable - The algorithm should be able to take min time if the elems are sorted in the array
- Stable - If there are common elems in the array, the order of those elems is kept
- Bubble sort is good to determine the max kth element. With every pass, the max elem is sorted
- Bubble is array friendly only
*/

template <class T>
void print(T& arr, int size, string id)
{
    cout << id << ": ";
    for(int i{0}; i < size; i++){
        cout << arr[i];
        if(i < size-1){
            cout << ", ";
        }
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void bubble(vector<int>& elems, int n)
{   // This is to set the bounds at the end
    for(int i{0}; i < n; i++){
        bool sorted{true};
        
        // This is to iterate from the beginning to the end (minus the sorted heavier elems)
        for(int j{0}; j < n-1-i; j++){
            if(elems[j] > elems[j+1]){
                swap(elems[j], elems[j+1]);
                sorted=false;
            }
        }

        if(sorted){
            break;
        }
    }
}

int main()
{
    vector<int> elems{9,5,7,4,1,2,6,3,0,8};
    vector<int> sorted{0,1,2,3,4,5,6,7,8,9};

    int size = elems.size();

    print(elems, size, "Unsorted");

    bubble(sorted, size);

    print(sorted, size, "Sorted");

    return 0;
}

