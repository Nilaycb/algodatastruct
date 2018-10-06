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


int bsearch(int arr_0[], int l, int r, int d)
{
    if(l <= r)
    {
        int m = l+(r-l)/2;

        if(arr_0[m] == d)
            return m;
        else if(d < arr_0[m])
            return bsearch(arr_0, l, m-1, d);
        else
            return bsearch(arr_0, m+1, r, d);
    }

    return -1;
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

    printf("Enter search data: ");
    int d, res;
    scanf("%d", &d);
    res = bsearch(arr_0, 0, n-1, d);
    (res != -1) ? printf("%d found at position %d\n", d, res) : printf("%d not found in the array\n", d);

    return 0;
}
