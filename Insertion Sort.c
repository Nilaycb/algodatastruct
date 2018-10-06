#include<stdio.h>

void dispArr(int arr_0[], int n)
{
    int i;

    printf("The Array: ");
    for(i=0; i<n; i++)
    {
        printf("%d", arr_0[i]);
        (i != n-1) ? printf(" ") : printf("\n");
    }
}


void insertionSort(int arr_0[], int n)
{
    int i, j, k;

    for(i=1; i<n; i++)
    {
        k=arr_0[i];
        j = i-1;

        while(j>=0 && arr_0[j]>k)
        {
            arr_0[j+1] = arr_0[j];
            j = j-1;
        }
        arr_0[j+1] = k;
    }
}


int main()
{
    int n, i, j;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr_0[n];

    printf("Enter array data: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr_0[i]);
    }
    printf("\n");

    dispArr(arr_0, n);
    printf("\n");

    insertionSort(arr_0, n);
    printf("After Insertion Sorting: ");
    dispArr(arr_0, n);

    return 0;
}

