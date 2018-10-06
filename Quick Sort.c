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


//first element as pivot
int qPartion_f(int arr_0[], int l, int r)
{
    int p = arr_0[l];

    int i=r, j, temp;

    for(j=l+1; j <= r; j++)
    {
        if(arr_0[j] >= p)
        {
            temp = arr_0[j];
            arr_0[j] = arr_0[i];
            arr_0[i] = temp;
            i--;
        }
    }

    //now set pivot to it's correct position
    temp = arr_0[i];
    arr_0[i] = arr_0[l]; // pivot placed on correct position
    arr_0[l] = temp;

    return i;
}


//last element as pivot
int qPartion_l(int arr_0[], int l, int r)
{
    int p = arr_0[r];

    int i=0, j=0, temp;

    for(j=0; j <= r-1; j++)
    {
        if(arr_0[j] <= p)
        {
            temp = arr_0[j];
            arr_0[j] = arr_0[i];
            arr_0[i] = temp;
            i++;
        }
    }

    //now set pivot to it's correct position
    temp = arr_0[i];
    arr_0[i] = arr_0[r]; // pivot placed on correct position
    arr_0[r] = temp;

    return i;
}


void quickSort(int arr_0[], int l, int r)
{
    if(l < r)
    {
        int p = qPartion_l(arr_0, l, r); //change this function according to pivot position

        quickSort(arr_0, l, p-1);
        quickSort(arr_0, p+1, r);
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

    quickSort(arr_0, 0, n-1);
    printf("After Quick Sorting: ");
    dispArr(arr_0, n);

    return 0;
}
