#include<iostream>
using namespace std;

bool checkIfArrayIsSorted(int arr[], int n)
{
    if(n==1)
        return true;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
                return false;

        }
    }
    return true;
}


int main()
{
    int arr[] = {3,5,77,8};
    int n = 4;
    cout<<checkIfArrayIsSorted(arr, n);

    cout << " control ends " << " ";
    return 0;
}
// time : O(n^2)
// space : O(1)