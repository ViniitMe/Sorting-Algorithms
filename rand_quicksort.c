#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *i,int *j)
{
	int k=*i;
	*i=*j;
	*j=k;
}


int partition(int A[],int p,int q)
{
	srand(time(NULL));
	int k=p + rand() %(q-p+1);
	swap(&A[k],&A[p]);

	int i,j,key,x;
	i=p;
	x=A[p];

	for(j=p+1;j<=q;j++)
	{
		key=A[j];
		if(key<x)
		{
			i=i+1;
			swap(&A[i],&A[j]);
		}
	}

	swap(&A[i],&A[p]);
	return i;
}

void rand_quicksort(int A[],int p,int q)
{
	if (q>p)
	{
		int r=partition(A,p,q);
		rand_quicksort(A,0,r-1);
		rand_quicksort(A,r+1,q);

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
	int i,j,n,A[100];
	printf("Enter the no. of elements you want to sort:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("The input array is:");
	printarray(A,n);
	printf("The sorted array is:");
	rand_quicksort(A,0,n-1);
	printarray(A,n);
	return 0;
}