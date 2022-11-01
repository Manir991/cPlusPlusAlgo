#include <iostream>

/**
 * @brief Selection sort
 * Selectin sort is the opposite of bubble sort
 * Where bubble sort returns the kth max element after each pass,
 * Selection sort returns the kth min element per pass
 * Time Complexity - O(n2)
 * Algorithm is not adaptable but stable
 * During each pass the number of swaps is only 1
 * Therefore, viaout the entire set of passes, the number of swaps is O(n)
 */

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

template <class T>
void print(T array[], int size)
{
    for(int i=0; i < size; i++){
        cout << array[i];
        if(i < size-1){
            cout << ",";
        }
    }
    cout << endl;
}

void selection(int array[], int size)
{
    // i starts off by selecting index position 0
    for(int i=0; i < size-1; i++){
        // elem is initially indexed to i and moved when next  
        // elem is smaller
        int elem = i;
        for(int j=i; j < size; j++){
            if(array[j] < array[elem]){
                elem=j;
            }
        }
        if(array[i] != array[elem]){
            swap(array[i], array[elem]);
        }
    }
}


int main()
{
    int elems[]{9,5,7,4,1,2,6,3,0,8};
    int size = sizeof(elems)/ sizeof(elems[0]);

    selection(elems, size);
    print(elems, size);

    return 0;
}