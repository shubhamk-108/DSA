#include<iostream>
using namespace std;
#include<algorithm>
void moveZeros(int arr[], int n)
{
    int count = 0;
    for(int i = 0; i<n ; i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
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

// time O(n)
// space O(1)

// Logic:
// This is a classic two-pointer pattern:
// i scans the array
// count tracks where the next non-zero element should go

// We are incrementing count pointer only when we got non zero element
// That means when we get zero as element then we do not increment count pointer thereby count is still on 0 element means
// count is still pointing zero element and 
// count is still waiting for next non zero element because when next non zero element will occur the swap condition will
// trigger and count was already waiting on zero element. so we will swap this current arr[i] element with count arr[count]
// element or count pointer

// jevha-jevha zero element bhetel, count pointer ha increment ch honar nahi aani to tyach position la mhanje 0 element la
// vat baghat basel. As soon as we get non zero element, we swap it with count because count was pointing zero element and we 
// increment count