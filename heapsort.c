#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void max_heapify(int A[],int i,int n)
{
	int largest=i;
	int l= 2*i+1;
	int r= 2*i+2;

	if(l<n && A[l]>A[largest])
	{
		largest=l;
	}

	if(r<n && A[r]>A[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		swap(&A[i],&A[largest]);
		max_heapify(A,largest,n);
	}
}

void build_max_heap(int A[],int n)
{
	int i;
	for(i=n/2;i>=0;i--)
	{
		max_heapify(A,i,n);
	}
}

void heapsort(int A[], int n)
{
	int i;
	while(n!=0)
	{
		swap(&A[n-1],&A[0]);
		n=n-1;
		build_max_heap(A,n);
	}
}

void printarray(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}

int main()
{
	int i,n,A[100];
	printf("Enter the no. of elements:");
	scanf("%d",& n);

	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",& A[i]);
	}

	printf("The given input is:");
	printarray(A,n);

	printf("The maxheap is:");
	build_max_heap(A,n);
	printarray(A,n);

	printf("Sorted array is:");
	heapsort(A,n);
	printarray(A,n);
	return 0;
}