#include<stdio.h>
#include<stdlib.h>

void swap(int *i,int *j)
{
	int k=*i;
	*i=*j;
	*j=k;
}

int partition(int A[],int p,int q)
{
	int i,j,x,key;
	x=A[p];
	i=p;
	

	for(j=p+1;j<=q;j++)
	{
		key=A[j];
		if (x>=key)
		{
			i=i+1;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i],&A[p]);
	return i+1;      //note here
}

void quicksort(int A[],int p,int q)
{
	int r;
	int n=q-p+1;
	if (n>=1)
	{
		r=partition(A,p,q);
		quicksort(A,p,r-1);
		quicksort(A,r+1,q);
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
	int A[100],i,n;
	printf("Enter the no. of elements you want to sort:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("\nThe given array is:");
	printarray(A,n);
	printf("\nThe sorted array is:");
	quicksort(A,0,n-1);
	printarray(A,n);
	return 0;
}

 
