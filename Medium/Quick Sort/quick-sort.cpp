//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        while (low < high) {
            int pivotIndex = partition(arr, low, high);
    
            
            if (pivotIndex - low < high - pivotIndex) {
                quickSort(arr, low, pivotIndex - 1);
                low = pivotIndex + 1;
            }
            else {
                quickSort(arr, pivotIndex + 1, high);
                high = pivotIndex - 1;
            }
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot = arr[low];
        int i = low + 1;
        int j = high;
    
        while (i <= j) {
            while (i <= j && arr[i] <= pivot)
                i++;
    
            while (i <= j && arr[j] > pivot)
                j--;
    
            if (i < j)
                swap(arr[i], arr[j]);
        }
    
        swap(arr[low], arr[j]);
        return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends