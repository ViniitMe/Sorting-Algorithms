#include<stdio.h>
#include<stdlib.h>

void swap(int *i,int *j)
{
int t;
t=*i;
*i=*j;
*j=t;
}

 
int partition(int A[],int p,int q)
{
int x,key,i,j;

i=p;
x=A[i];

for(j=p+1;j<=q;j++)
{
    key=A[j];
    if(key<=x)
    {
       i=i+1;
       swap(&A[i],&A[j]);
    }
}
swap(&A[p],&A[i]);
return i;
}


void Quicksort(int A[],int p,int q)
{
//int n=q-p+1;
if (p<q)
{
int r=partition(A,p,q);
Quicksort(A,p,r-1);
Quicksort(A,r+1,q);
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

int Binarysearch(int A[],int key,int p,int q)
{

if(q>=p)
{
int mid=p+(q-p)/2;
if(key==A[mid])
{
return mid;
}
else if (key<A[mid])
{
return Binarysearch(A,key,p,mid-1);
}
else if (key>A[mid])
{
return Binarysearch(A,key,mid+1,q);
}
}
else
return -1;
}



int main()
{
int A[100],n,i,key;
printf("Enter the no. of elements you want to sort:");
scanf("%d",&n);
printf("\nEnter the elements:");
for(i=0;i<n;i++)
{
scanf("%d",&A[i]);
}
printf("\nThe input array is:");
printarray(A,n);
printf("\nThe sorted array is:");
Quicksort(A,0,n-1);
printarray(A,n);

printf("\nEnter the no. you want to search in sorted array:");
scanf("%d",&key);
int index=Binarysearch(A,key,0,n-1);
if (index==-1)
printf("Element is not present in array");
else
printf("Element is present at index %d",index);                                                
return 0;
}

