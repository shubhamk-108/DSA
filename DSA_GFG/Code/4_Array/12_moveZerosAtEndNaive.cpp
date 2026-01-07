#include<iostream>
using namespace std;
#include<algorithm>
void moveZeros(int arr[], int n)
{
    for(int i = 0; i<n ; i++)
    {
        if(arr[i]==0)
        {
            for(int j = i+1; j<n;j++)
            {
                if(arr[j] != 0)
                {
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
}

int main()
{
 
    int arr[] = {10, 20, 0,0 , 30, 21, 0},
    n = 7;
    moveZeros(arr, n);
    for(int i =0; i<n; i++)
        cout<<arr[i]<<" ";
    cout << " control ends " << " ";
    return 0;
}

// time O(n^2)
// space O(1)