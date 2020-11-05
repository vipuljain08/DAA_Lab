// Linear Search
#include <stdio.h>
void main()
{
    int a[10],i,n,element;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:\n");
    scanf("%d",&element);
    for(i=0;i<n;i++)
    {
        if(element==a[i])
        {
            printf("Element %d found at location %d",element,i+1);
        }
    }

}
