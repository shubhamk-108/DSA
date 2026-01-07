// A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element). 

// Examples : 

// Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
// Output : 4
// Explanation: The frequency of 4 is 5 which is greater than the half of the size of the array size. 

// Input : {3, 3, 4, 2, 4, 4, 2, 4}
// Output : No Majority Element
// Explanation: There is no element whose frequency is greater than the half of the size of the array size.

#include<iostream>
using namespace std;


int majorityELement(int arr[], int n)
{

    for(int i=0; i<n; i++)
    {
        int count = 1;

        for(int j=i+1; j<n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        if(count> n/2)
            return arr[i];
    }
    return -1;
}

int main()
{
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<majorityELement(arr,n);
    return 0;
}




// Time Complexity: O(n2), A nested loop is needed where both the loops traverse the array from start to end.
// Auxiliary Space: O(1), No extra space is required.