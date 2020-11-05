// Matrix chain multiplication
#include <stdio.h>
int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = 999999;
    int Matrix_Cost;

    for (k = i; k < j; k++)
    {
        Matrix_Cost= MatrixChainOrder(p, i, k)
                + MatrixChainOrder(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];

        if (Matrix_Cost < min)
            min = Matrix_Cost;
    }

    return min;
}


int main()
{
    int arr[] = {30,35,15,5,10,20,25};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of scaler multiplications are :\t %d",
           MatrixChainOrder(arr, 1, n - 1));

    getchar();
    return 0;
}
