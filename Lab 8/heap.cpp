#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify
    int max = root;  
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    
    if (left < n && arr[left] > arr[max])
        max = left;
    
    if (right < n && arr[right] > arr[max])
        max = right;
    
    // If max is not root
    if (max != root) {
        // swap arr[root] with arr[max]
        swap(arr[root], arr[max]);
        
        //heapify recursively
        heapify(arr, n, max);
    }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
  
    // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   /*Assign random values for the array*/
   int size;
   cout << "Enter the size of the array: ";
   cin >> size;
   int heap_arr[size];
   for (int i = 0; i < size; i++) {
        cin >> heap_arr[i];
   }
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}