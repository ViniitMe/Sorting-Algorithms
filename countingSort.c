/** VINIT KUMAR
    ROLL NO: 15MI33017
    counting sort  
**/


#include<stdio.h>
#include<stdlib.h>

void countingsort(int A[],int k,int n)
{
	int j,i,B[n],c[k];

	for(j=0;j<k;j++)
	{
		c[j]=0;
	}

	for(i=0;i<n;i++)
	{
		c[A[i]-1]=c[A[i]-1] + 1;
	}

	for(j=1;j<k;j++)
	{
		c[j]=c[j]+c[j-1];
	}

	for(i=n-1;i>=0;i--)
	{
		B[c[A[i]-1]-1]=A[i];
		c[A[i]-1]=c[A[i]-1]-1;
	}

	for(i=0;i<n;i++)
	{
		printf("%d ",B[i]);
	}
	printf("\n");
}

void printarray(int A[], int n)
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
	int A[100],C[100],n,k,i;
	printf("Enter the no. of Elements you want to sort:");
	scanf("%d",& n);
	printf("Enter the Elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",& A[i]);
	}

	printf("Entered list of no.:");
	printarray(A,n);

	k=A[0];
	for(i=1;i<n;i++) //Finding K which is the index of largest value in A
	{
		if(A[i]>k)
		{
			k=A[i];
		}
	}

	printf("Sorted list of no.:");
	countingsort(A,k,n);
	return 0;
}