/**   VINIT KUMAR
      ROLL NO: 15MI33017
      Radix sort
**/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int largest(int a[], int n)
{
    int large = a[0], i;
    for(i = 1; i < n; i++)
    {
        if(large < a[i])
            large = a[i];
    }
    return large;
}
 
void RadixSort(int a[], int n)
{
    int bucket[10][10], bucket_count[10];
    int i, j, k, remainder, NP=0, divisor=1, large, p;
 
    large = largest(a, n);  //to know the no. of digits
    while(large > 0)
    {
        NP++;
        large/=10;
    }
 
    for(p = 0; p < NP; p++)
    {
        for(i = 0; i < 10; i++)
        {
            bucket_count[i] = 0;
        }
        for(i = 0; i < n; i++)
        {
            remainder = (a[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = a[i];
            bucket_count[remainder] += 1;
        }
 
        i = 0;
        for(k = 0; k < 10; k++)
        {
            for(j = 0; j < bucket_count[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;

    }
}
 
int main()
{
    int i, n, a[10];
    printf("Enter the number of elements you want to sort: ");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    RadixSort(a,n);
    printf("The sorted elements are:");
    for(i = 0; i < n; i++)
        printf("%d  ",a[i]);
    printf("\n");
    return 0;
}
