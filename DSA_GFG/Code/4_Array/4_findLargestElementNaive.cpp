#include<iostream>
using namespace std;
 
int findLargest(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        bool isLargest = true;
        for(int j = 0; j < n; j++)
        {
            if(arr[j] > arr[i])
            {
                isLargest = false;
                break;
            }
        }
        if(isLargest)
            return arr[i];
    }
    return -1; // only if array is empty (n == 0)
}


int main()
{
    int arr[6] = {4,0,9,1,2,8};
    int n = 6;
    int lar = findLargest(arr, n);
    cout<<lar<<endl;


    cout << " control ends " << " ";
    return 0;
}

// // Logic: 
// You're using two loops:

// 🔁 Outer Loop (i from 0 to n-1):
// For every element arr[i], you assume it might be the largest, so you set isLargest = true.

// 🔁 Inner Loop (j from 0 to n-1):
// You compare arr[i] with every other element arr[j].

// If any arr[j] is greater than arr[i], that means arr[i] is not the largest, so you set isLargest = false and break the inner loop.

// ✅ Check:
// After the inner loop, if isLargest is still true, it means arr[i] was greater than or equal to all others, so you return arr[i] as the largest

// -----------------------------------------------------------------------------------------------------------------------------


// Time Complexity: O(n²)
// space : O(1)
// You are only using one boolean variable isLargest
// No extra space based on input size is used
// So, space = constant = O(1)