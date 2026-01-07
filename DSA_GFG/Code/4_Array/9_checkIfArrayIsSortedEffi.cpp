#include<iostream>
using namespace std;

bool checkIfArrayIsSorted(int arr[], int n)
{
    if(n==1)
        return true;
    for(int i = 1; i < n; i++)
    {
        if(arr[i-1] > arr[i])
            return false;
    }
    return true;
}


int main()
{
    int arr[] = {3,5,7,8};
    int n = 4;
    cout<<checkIfArrayIsSorted(arr, n);

    cout << " control ends " << " ";
    return 0;
}

// time : O(n)
// space : O(1)