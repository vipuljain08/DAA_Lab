// Selected Activities
#include<stdio.h>
void Selected_Activities(int start[], int finish[], int n)
{
    int i=0, j;
    printf ("Activities that will be selected are as follows :\t");
    printf("{ ");
    printf("%d ", i);
    for(j = 1; j < n; j++)
    {
      if (start[j] >= finish[i])
      {
          printf ("%d ", j);
          i = j;
      }
    }
    printf(" }");
}
int main()
{
    int start[] =  {1,3,0,5,3,5,6,8,8,2,12};
    int finish[] =  {4,5,6,7,9,9,10,11,12,14,16};
    int n = sizeof(start)/sizeof(start[0]);
    Selected_Activities(start, finish, n);
    return 0;
}