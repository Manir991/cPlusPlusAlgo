/**
 * Insertion sort is very similar to bubble sort but there are some critical differences
 * Insertion
 * - Here going via first pass, or second pass doesn't really provide any valuable information
 * - Insertion sort is more linked list friendly as the values are being literally inserted
 * - between elems. Elem to be inserted is compared across the nodes and then inserted inbetween
 * - First elem in the array is considered to be sorted
 * - Starting from index 1 for both inner and outer loop (i,j)
 *
 * Bubble
 * - Going over first pass would reveal the highest element that is present in the array
 * - Similar k number of passes would reveal kth highest element in the array
 * - Bubble sort is array friendly,
 * - Outer loop sets the iterative index
 * - All of the scanning is done by the inner loop up until the tail index which shrinks with every pass
 * - Array[currentIndex] > Array[nextIndex], swap the values until it reaches the end of the array
 *
 * Bubble and Insertion are both stable and adaptable
 *
 */



#include <iostream>
#include <string>

using namespace std;

template <class T>
void print(T arr[], int size, string id)
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

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void insertion(int arr[], int n)
{
    // First elem is considered to be sorted
    for(int i{1}; i < n; i++){
        // Index positions
        int j = i-1; int elem = arr[i];

        while(j > -1 && elem < arr[j])
        {
            arr[j+1] = arr[j]; // Replace current with previous
            j--;    // Decrement jth index
        }
        arr[j+1] = elem; // Replace with smallest element
    }

}



int main()
{
    int elems[]{9,5,7,4,1,2,6,3,0,8};
    int sorted[] {0,1,2,3,4,5,6,8,8,9};

    int n = sizeof(elems) / sizeof(elems[0]);
    int s = sizeof(sorted) / sizeof(sorted[0]);

    print(elems, n, "Unsorted");
    insertion(elems, n);
    print(elems, n, "Sorted");
    return 0;
}
