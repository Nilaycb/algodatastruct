#include<bits/stdc++.h>
using namespace std;

void dispArr(int arr[], int n)
{
    int i;
    cout << "The Array: ";

    for(i=0; i<n; i++)
    {
        cout << arr[i];
        if(i != n-1)
            cout << " ";
    }
    cout << endl;
}

int firstFit(int arr[], int n, int c)
{
    int bins=0, i, bin_rem[n];

    for(i=0; i<n; i++)
    {
        int j;
        for(j=0; j<bins; j++)
        {
            if(bin_rem[j] >= arr[i])
            {
                bin_rem[j] -= arr[i];
                break;
            }
        }

        if(j == bins)
        {
            bin_rem[bins] = c - arr[i];
            bins++;
        }
    }

    return bins;
}

int firstFitDec(int arr[], int n, int c)
{
    sort(arr, arr+n, greater<int>());

    return firstFit(arr, n, c);
}

int main()
{
    int i, n, c;

    cout << "Enter Bin capacity: ";
    cin >> c;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array data: ";
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    dispArr(arr, n);

    int low_bnd = firstFitDec(arr, n, c);

    cout << "Minimum Bin required: " << low_bnd << endl;

    return 0;
}

// Special Thanks to GeeksforGeeks
