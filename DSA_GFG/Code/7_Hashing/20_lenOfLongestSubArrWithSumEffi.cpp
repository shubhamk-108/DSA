//  return length of  Longest subarray with given sum
// Input Array: [10, 5, 2, 7, 1, 9]
// Given Sum (k): 15
// Reasoning: There are two subarrays that sum to 15:
// {10, 5} has a length of 2.
// {5, 2, 7, 1} has a length of 4.
// Output: 4 (the length of the longest one)

// You must see 18_subarrayWithGivenSumEffi.cpp Without doing that code first you will not understand this

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int LengthOfLongestSubarrayWithGivenSum(int arr[], int n, int sum)
{

    unordered_map <int, int> um;
    vector<int> prefix_sum(n);

    prefix_sum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = arr[i] + prefix_sum[i - 1];
    }

    int longest_length = 0;

    for (int i = 0; i < n; i++)
    {
        int current_length ; 

        if (arr[i] == sum)
        {
            current_length = 1;
            longest_length = max(current_length, longest_length);
        }
        if (prefix_sum[i] == sum)
        {
            current_length = i+1;
            longest_length = max(current_length, longest_length);
        }

        


        if (um.find(prefix_sum[i] - sum) != um.end())
        {
            int idx = um[prefix_sum[i] - sum];
            current_length = i - idx ; 
            longest_length = max(current_length, longest_length);

        }
        else
        {
            if (um.find(prefix_sum[i]) == um.end())
            um[prefix_sum[i]] = i;
        }
            
    }

    return longest_length;
}

int main()
{
    int arr1[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    int sum = 15;

    cout << LengthOfLongestSubarrayWithGivenSum(arr1, n, sum);

    return 0;
}


/*

Time Complexity
Building prefix_sum array → O(n)
Traversing array and checking map → O(n)
Each lookup/insert in unordered_map is O(1) average case.
Worst case (hash collisions) can be O(n), but usually considered O(1) expected.
Total → O(n) average case

Space Complexity
prefix_sum array → O(n)

unordered_map → stores at most n prefix sums → O(n)

Total → O(n)

*/




// Logic:
// You must see 18_subarrayWithGivenSumEffi.cpp Without doing that code first you will not understand this. Please watch that logic


/*


int LengthOfLongestSubarrayWithGivenSum(int arr[], int n, int sum)
{
    // Map will store prefix_sum value → earliest index where it occurs
    unordered_map<int, int> um;

    // Store prefix sums of the array
    vector<int> prefix_sum(n);

    // First prefix_sum is just the first element
    prefix_sum[0] = arr[0];

    // Build prefix_sum array: prefix_sum[i] = sum(arr[0..i])
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = arr[i] + prefix_sum[i - 1];
    }

    int longest_length = 0; // result

    // Traverse each index
    for (int i = 0; i < n; i++)
    {
        int current_length; 

        // Case 1: single element matches target
        if (arr[i] == sum)
        {
            current_length = 1;
            longest_length = max(current_length, longest_length);
        }

        // Case 2: subarray from index 0..i matches target
        // ex : {5,5,5} givenSum = 15. Then prefix will be {5,10,15}. So we got givenSum 15 at index 2 that is i was 2.
        // But there were total 3 elements or length so we did i + 1.
        if (prefix_sum[i] == sum)
        {
            current_length = i + 1; // length = i-0+1
            longest_length = max(current_length, longest_length);
        }

        // Case 3: subarray between two indices matches target
        // If prefix_sum[i] - sum = some previous prefix_sum[j]
        // then subarray (j+1 .. i) has sum = target
        if (um.find(prefix_sum[i] - sum) != um.end())
        {
            int idx = um[prefix_sum[i] - sum]; 
            current_length = i - idx; // length of (j+1..i)
            longest_length = max(current_length, longest_length);
        }
        else
        {
            // Store prefix_sum[i] → index i, but only if not already stored
            // (so we keep the earliest occurrence to maximize length). 
            // If at index 2 we need to insert value 5 and its key 2. Suppose at index 6 we again have to insert  value 5 and key 6, then
            // here 5 was already there but if we found it already there then we do not insert new index or value because we need 
            // earlier index of 5. The more earlier index will be of 5 the longest subarray we will have as per our problem requirement.
            if (um.find(prefix_sum[i]) == um.end())
                um[prefix_sum[i]] = i;
        }
    }

    return longest_length;
}


*/