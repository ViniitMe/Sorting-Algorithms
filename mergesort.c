#include<stdlib.h>
#include<stdio.h>
#include<time.h>
 
void merge(int A[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];      //creating left and right subarray
 
    for (i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1+ j];
 
    i = 0; // Initial index
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
 
   
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
 
   
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int A[], int l, int r)
{
    if (l < r)
    {
       
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
 
        merge(A, l, m, r);
    }
}

//function for printing arrays 
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
int main()
{
    clock_t t;
    t = clock();
    int arr[] = {9,7,6,5,4,3,2};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("The given array:\n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nThe Sorted array is \n");
    printArray(arr, arr_size);

    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("mergeSort() took %f seconds to execute \n", time_taken);
    return 0;
}
