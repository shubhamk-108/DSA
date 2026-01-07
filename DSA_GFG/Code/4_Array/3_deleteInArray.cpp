#include<iostream>
using namespace std;
 
int deleteArr(int arr[], int n, int x)
{
    int i = 0;
    for(i; i<n; i++)
    {
        if(arr[i] == x)
            break;
    }
    if(i==n)
        return n;
    
    for(int j = i; j < n-1; j++)
    {
        arr[j] = arr[j+ 1];
    }
    return n -1;
}

int main()
{
    // check delete functionality if element is present
    int arr[] = {2,33,63, 4, 7};
    int n = 5;
    int x = 4;
    
    cout<<"Before deletion\n";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    

    n = deleteArr(arr,n,x);


    cout<<"\nAfter deletion\n";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    // check delete functionality if element is absent
    
    // int arr[] = {2,33,63, 4, 7};
    // int n = 5;
    // int x = 88;
    
    // cout<<"Before deletion\n";
    // for(int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    

    // n = deleteArr(arr,n,x);


    // cout<<"\nAfter deletion\n";
    // for(int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";


    cout << " control ends " << " ";
    return 0;
}

// Time : O(n)
// space :O(1)

// Space Complexity Analysis
// Input array is passed by pointer → no new copy is created

// Only variables used:

// i and j: integers

// No extra arrays, vectors, or recursion stack

// Because:

// No matter how large n is, the function only uses a fixed amount of extra memory (just a few integers)

// Array is modified in-place

// so even if we use array of n size but inside loop if constant operation is being performed on 
// array then like above deleteArr funtion then sapce complexity still remain O(1). right or wrong

// Yes are absolutely right.

// Even if the input is an array of size n, as long as:

// You don't create any new array or use extra space proportional to n, and

// All operations (like access, update, swap, shift) are done on the same array in-place,

// And you're using only a constant number of extra variables (int i, j, etc.),

// Then the space complexity is O(1), i.e., constant space.