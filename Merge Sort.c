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


void merge(int arr_0[], int l, int m, int r)
{
    int n1, n2, i, j, k;

    n1 = m-l+1;
    n2 = r-m;

    int L[n1], R[n2];

    for(i=0; i<n1; i++)
    {
        L[i] = arr_0[l+i];
    }

    for(j=0; j<n2; j++)
    {
        R[j] = arr_0[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            arr_0[k] = L[i];
            i++;
        }
        else
        {
            arr_0[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr_0[k]=L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr_0[k]=R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr_0[], int l, int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2; // m = (l+r)/2

        mergeSort(arr_0, l, m);
        mergeSort(arr_0, m+1, r);
        merge(arr_0, l, m, r);
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

    mergeSort(arr_0, 0, n-1);
    printf("After Merge Sorting: ");
    dispArr(arr_0, n);

    return 0;
}
