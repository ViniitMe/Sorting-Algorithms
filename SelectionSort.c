#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void selection_sort(int A[], int n)
{
	int i,j,min;

	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])
		      {
			      min=j;
		      }  
		    swap(&A[i],&A[min]);
		}
	}
	printf("Sorted list:");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}

int main()
{
	int A[100],i,n;
	printf("Enter the no. of Elements you want to sort:");
	scanf("%d",&n);
	printf("Enter the Elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Entred list is:");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	selection_sort(A,n);
	return 0;
}