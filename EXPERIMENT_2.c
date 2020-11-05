// Bubble Sort
#include <stdio.h>
void main()
{
    int n,i,j,temp;
    int a[20];

    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=1;i<=n;i++)
    {
        j=i;
        while(j>0 && a[j-1]>a[j])
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--;

        }
    }
    printf("Sorted list is as follows\n");
    for(i=0;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
}
