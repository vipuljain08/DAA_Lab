// Binary Search
#include <stdio.h>
void main()
{
    int a[10],i,n,element,loc,c=0,l,u,mid;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter elements in array in sorted order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d",&element);
    l=0,u=n-1;
    while(l<=u)
    {
        mid=(l+u)/2;
    if(element==a[mid])
    {
        c=1;
        loc=mid;
        break;
    }
    else if(element<a[mid])
    {
        u=mid-1;
    }
    else
    {
        l=mid+1;
    }
    }
    if(c==1)
    {
        printf("%d found at location %d",element,loc+1);
    }
    else
        printf("%d not found",element);
}
