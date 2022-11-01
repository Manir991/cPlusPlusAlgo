#include <climits>
#include <iostream>

using namespace std;

class Node {
public:
  int num;
  Node *next{nullptr};
};

void createList(int arr[], int n);
void printIter(Node *ptr);
void printRecursive(Node *ptr);
int countNodesRecursive(Node *ptr);
int countNodesIter(Node *ptr);
int sumAllNodesRecursive(Node *ptr);
int sumAllNodesIter(Node *ptr);
int maxNodeRecursive(Node *ptr);
int maxNodeIter(Node *ptr);
int linearSearch(Node *ptr, int elem);
int linearSearchRecursive(Node *ptr, int elem);
void append(Node *ptr, int elem);
void appendBegin(Node *ptr, int elem);
void pop(Node *ptr);
void popBegin(Node *ptr);
void insert(Node *ptr, int position, int elem);
void remove(Node *ptr, int position);
bool isSorted(Node *ptr);
void removeDuplicates(Node* ptr);
void reverseLLRecursive(Node *ptr, Node* tailPtr);
void reverseLLIter(Node *ptr);
void concatenatingLL(Node *ptr1, Node *ptr2);



Node *head = nullptr;
int main() {
  Node *n1 = new Node;
  Node *n2 = new Node;
  Node *n3 = new Node;

  n1->num = 3;
  n2->num = 1;
  n3->num = -5;

  n1->next = n2;
  n2->next = n3;
  head = n1;

  //* Function Testing
    int arr[] = {1, 2, 5, 5, 6, 6, 7};

    createList(arr, 7);
    printRecursive(head);
	removeDuplicates(head);
	printIter(head);

    reverseLLIter(head);
    printIter(head);


  return 0;
}

void createList(int arr[], int n) {
  Node *ptr = new Node;
  ptr->num = arr[0];
  head = ptr;

  for (int i = 1; i < n; i++) {
    Node *n = new Node;
    n->num = arr[i];
    ptr->next = n;
    ptr = ptr->next;
  }
  cout << "All nodes created" << endl;
}
void printIter(Node *ptr) {
  while (ptr != nullptr) {
    cout << ptr->num << " ";
    ptr = ptr->next;
  }
  cout << endl;
}
void printRecursive(Node *ptr) {
  // Base Case
  if (ptr == nullptr) {
    cout << endl;
    return;
  }
  cout << ptr->num << " ";
  printRecursive(ptr->next);
}
int countNodesRecursive(Node *ptr) {
  // Base Case
  if (ptr == nullptr) {
    return 0;
  }
  return 1 + countNodesRecursive(ptr->next);
}
int countNodesIter(Node *ptr) {
  int count{};
  while (ptr != nullptr) {
    ptr = ptr->next;
    count++;
  }
  return count;
}
int sumAllNodesRecursive(Node *ptr) {
  // Base Case
  if (ptr == nullptr) {
    return 0;
  }
  return ptr->num + sumAllNodesRecursive(ptr->next);
}
int sumAllNodesIter(Node *ptr) {
  int sum{};
  while (ptr != nullptr) {
    sum += ptr->num;
    ptr = ptr->next;
  }
  return sum;
}
int maxNodeRecursive(Node *ptr) {
  static int max = INT_MIN;
  // Base Case
  if (ptr == nullptr) {
    return max;
  } else if (max < ptr->num) {
    max = ptr->num;
  }
  return maxNodeRecursive(ptr->next);
}
int maxNodeIter(Node *ptr) {
  int max = INT_MIN;
  while (ptr != nullptr) {
    if (max < ptr->num) {
      max = ptr->num;
    }
    ptr = ptr->next;
  }
  return max;
}
int linearSearch(Node *ptr, int elem) {
  int index{};
  Node *prev = nullptr;
  while (ptr != nullptr) {
    if (elem == ptr->num) {
      prev->next = ptr->next;
      ptr->next = head;
      head = ptr;
      return index;
    }
    prev = ptr;
    ptr = ptr->next;
    index++;
  }
  return -1;
}
int linearSearchRecursive(Node *ptr, int elem) {
  static int index{};
	static Node* prev = nullptr;
  // Base case
  if (ptr == nullptr) {
    return -1;
  }
  if (ptr->num == elem) {
  	prev->next = ptr->next;
		ptr->next = head;
		head = ptr;
		return index;
  }
	prev=ptr;
	index++;
	linearSearchRecursive(ptr->next, elem);
  return index;
}
void append(Node *ptr, int elem){
	// Base Case
	if (ptr == nullptr)
	{
		return;
	}
	else if(ptr->next == nullptr)
	{
		Node* newPtr = new Node;
		newPtr->num = elem;
		ptr->next = newPtr;
		cout << elem << " was appended" << endl;
		return;
	}
	append(ptr->next, elem);
}
void appendBegin(Node *ptr, int elem){
	Node *newPtr = new Node;
	newPtr->num = elem;
	newPtr->next = head;
	head = newPtr;
	cout << elem << " appended to beginning" << endl;
}
void pop(Node *ptr){
	// Base Case - zero nodes
	if(ptr == nullptr)
	{
		cout << "Nothing to pop. List empty" << endl;
	}
	// 1 node
	else if(ptr->next == nullptr)
	{
		cout << ptr->num << " popped out of list" << endl;
		delete ptr;
		head = nullptr;
		return;
	}
	if(ptr->next->next == nullptr) // second last element
	{
		cout << ptr->next->num << " popped out of list" << endl;
		delete ptr->next;
		ptr->next = nullptr;
		return;
	}
	pop(ptr->next);
}
void popBegin(Node *ptr){
	// Check
	if(ptr == nullptr)
	{
		cout << "List is empty. Nothing to pop" << endl;
	}
	else
	{
		cout << ptr->num << " elem is popped" << endl;
		head = ptr->next;
		delete ptr;
	}
}
void insert(Node *ptr, int position, int elem){
	// Base Case
	int static index{};
	Node static *prevPtr{nullptr};
	Node static *newPtr = new Node;
	newPtr->num = elem;
	if(ptr == nullptr || position == 0) // list itself is empty
	{
		newPtr->next = head;
		head = newPtr;
		cout << elem << " inserted to the beginning of list" << endl;
	}
	else if(ptr->next == nullptr && index < position) // end of the list
	{
		ptr->next = newPtr;
		cout << elem << " appended to the end of list" << endl;
	}
	else if(position == index) // position is at the index
	{
		newPtr->next= ptr;
		prevPtr->next = newPtr;
		cout << elem << " inserted in position " << index << endl;
	}
	else
	{
		index++;
		prevPtr = ptr;
		insert(ptr->next, position, elem);
	}
}
void remove(Node *ptr, int position){
	// Base Case
	static Node* prevPtr{nullptr};
	static int index{};
	if(ptr == nullptr || position == 0)
	{
		head = ptr->next;
		cout << "Eliminated " << ptr->num << endl;
		delete ptr;
	}
	else if(ptr->next == nullptr && index < position)
	{
		cout << "Invalid position. Tail index " << index << endl;
	}
	else if(position == index)
	{
		prevPtr->next = ptr->next;
		cout << "Eliminated " << ptr->num << endl;
		delete ptr;
	}
	else
	{
		prevPtr = ptr;
		index++;
		remove(ptr->next, position);
	}
}
bool isSorted(Node *ptr){
	static int prev = INT_MIN;
	// Base Case
	if(ptr == nullptr)
	{
		return true;
	}
	else if(prev <= ptr->num)
	{
		prev = ptr->num;
		return true && isSorted(ptr->next);
	}
	else
	{
		return false;
	}
}
void removeDuplicates(Node* ptr){
	if(ptr == nullptr)
    {
        return;
    }
    Node* fwd = ptr->next;
    while(fwd != nullptr)
    {
        if(ptr->num == fwd->num){
            ptr->next = fwd->next;
            delete fwd;
            fwd = ptr->next;
        }
        else{
            ptr = fwd;
            fwd = fwd->next;
        }
    }
}
void reverseLLRecursive(Node *ptr, Node* tailPtr)
{
    if(ptr -> next == nullptr)
    {
        head = ptr;
        ptr->next = tailPtr;
        return;
    }
    reverseLLRecursive(ptr->next, ptr);
    ptr->next = tailPtr;
}
void reverseLLIter(Node *ptr)
{
    Node* tailptr{nullptr};
    Node* fwdptr{ptr->next};
    if (ptr == nullptr || ptr->next == nullptr)
    {
        return;
    }
    while(fwdptr != nullptr)
    {
        ptr->next = tailptr;
        tailptr = ptr;
        ptr = fwdptr;
        fwdptr=fwdptr->next;
    }
    ptr->next = tailptr;
    head = ptr;
}
void concatenatingLL(Node *ptr1, Node *ptr2)
{

}
