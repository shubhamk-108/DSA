// ip = {1,2,3,4,5}
// op = {2,3,4,5,1}
// Anticlockwise direction madhe rotate karayache aahe element by 1 position

#include<iostream>
using namespace std;
#include<algorithm>
void leftRotate(int arr[], int n)
{
    int temp = arr[0];
    for(int i = 1; i<n ; i++)
    {
        arr[i-1] = arr[i];
        
    }
    arr[n-1] = temp;
}

int main()
{
 
    int arr[] = {10, 20, 30, 21, 0},
    n = 5;
    leftRotate(arr, n);
    for(int i =0; i<n; i++)
        cout<<arr[i]<<" ";
    cout << " control ends " << " ";
    return 0;
}

// time O(n)
// space O(1)