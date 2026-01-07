// Our Task: Given an array arr[], the task is to find the elements of a contiguous subarray of numbers that has the largest sum.
// Examples:

// Input: arr = [-2, -3, 4, -1, -2, 1, 5, -3]
// Output:7 
// Explanation: [4, -1, -2, 1, 5] 
// In the above input, the maximum contiguous subarray sum is 7 and the elements of the subarray are [4, -1, -2, 1, 5]

#include<iostream>
#include<cmath>
using namespace std;
 
int largestSubarraySum(int arr[], int n)
{
    int res = arr[0];
    // why it is initialised as arr[i] and not 0 because to handle negative values too. 
    // Initialized res as  0. If the array contains all negative numbers, the output will be 0, which is incorrect.
    // For example, for input {-5, -2, -3}, the largest subarray sum should be -2 (which is the largest single element).
    // Your code will return 0 because 0 is greater than any negative sum you find.
    for(int i = 0; i<n; i++)
    {
        int sum = 0; 
        for (int j = i; j<n; j++)
        {
            sum += arr[j];

            // below condition is inside loop because if we encounter negative values then it should not hamper our result
            // ex {10,20,-40}. If this consition is outside the loop then sum would have calculated at the end of loop which is -10
            // but if we take it inside then sum would have updated at 10+20 = 30 and then it would have checked 10+20-40 = -10
            // max(30, -10) then we will get 30 as correct ans
            res = max(res, sum); 
        }
        
    }
    return res;
    
}


int main()
{
 

    int arr[] ={-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<largestSubarraySum(arr, n);

    cout << " control ends " << " ";
    return 0;
}









// // Time complexity: O(n2) 
// // Auxiliary Space: O(1)

 