// Quick Sort
#include <stdio.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int arr[],int p,int r)
{
    int x=arr[r];
    int i=(p-1);
    for(int j=p;j<=r-1;j++)
    {
        if(arr[j]<x)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return(i+1);
}
void quicksort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q=partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d",arr[i]);
        printf("\n");
    }
}
int main()
{
    int arr[]={2,7,3,8,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    printf("Sorted Array:\n");
    printArray(arr,n);
    return 0;
}
