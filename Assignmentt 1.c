#include <stdio.h> 
  
int findPivot(int[], int, int); 
int BS(int[], int, int, int); 
  

int pivotedBS(int arr[], int n, int target) 
{ 
    int pivot = findPivot(arr, 0, n - 1); 
  
    
    if (pivot == -1) 
        return BS(arr, 0, n - 1, target); 
  
     
    if (arr[pivot] == target) 
        return pivot; 
    if (arr[0] <= target) 
        return BS(arr, 0, pivot - 1, target); 
    return BS(arr, pivot + 1, n - 1, target); 
} 
  

int findPivot(int arr[], int low, int high) 
{ 
     
    if (high < low) 
        return -1; 
    if (high == low) 
        return low; 
  
    int mid = (low + high) / 2; 
    if (mid < high && arr[mid] > arr[mid + 1]) 
        return mid; 
    if (mid > low && arr[mid] < arr[mid - 1]) 
        return (mid - 1); 
    if (arr[low] >= arr[mid]) 
        return findPivot(arr, low, mid - 1); 
    return findPivot(arr, mid + 1, high); 
} 
  

int BS(int arr[], int low, int high, int target) 
{ 
    if (high < low) 
        return -1; 
    int mid = (low + high) / 2;
    if (target == arr[mid]) 
        return mid; 
    if (target > arr[mid]) 
        return BS(arr, (mid + 1), high, target); 
    return BS(arr, low, (mid - 1), target); 
} 
  

int main() 
{ 
    
    int arr1[] = { 4,5,6,7,0,1,2 }; 
    int n = sizeof(arr1) / sizeof(arr1[0]); 
    int target = 3; 
    printf(" %d", 
           pivotedBS(arr1, n, target)); 
    return 0; 
} 
