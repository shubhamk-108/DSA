// arr = {1, 4, 20, 3, 10, 5}
// target_sum = 33
// op = true
// expln: found from index 2 to 4

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool subarrayWithGivenSum(int arr[], int n, int sum)
{

    unordered_set<int> us;
    vector<int> prefix_sum(n);

    prefix_sum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = arr[i] + prefix_sum[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        if(prefix_sum[i] == sum || arr[i] == sum)
            return true;

        if (us.find(prefix_sum[i] - sum) != us.end())
            return true;
        else
            us.insert(prefix_sum[i]);
    }

    return false;
}

int main()
{
    int arr1[] = {4, 8, 3, 15, 4, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    int sum = 22;

    cout << subarrayWithGivenSum(arr1, n, sum);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)



// Logic 1:

/*

I took below example on the pen and paper and then experimented with below logic or pattern. Though i already saw hint that 
prefix sum is what we are going to use here. But still i solved it on paper and gotten the formula or expression. 
Please read this and try dry run on paper. You will surely understand.


take a example : {4,8,3,15,4,7} sum = 22
Its prefix sum will be : {4, 12, 15, 30, 34, 37}
See we will get sum 22 from {3,15,4}
4 from this  {3,15,4} is at index 4. At index 4 we have prefix sum as 34. 
Now if you see that if you subtract so far occured prefix sum from where we are currently pointing then we get sum. I mean to say
I am pointing at 34. If i minus 12 from 34, i get sum as 22. 
That means whereever you are pointing, take that prefix_sum element and subtract one by one so far occured prefix sum. If we get this expression 
equal to sum then we have a subarray which has sum as given sum.
like 34-4 = 30. No, this is not given sum. check next
34 - 12 = 22. Yes this is our given sum. Return true.
if the prefix_sum - so_far_prefix_sums != given_sum then we 
put that element in the hashtable so that we can check that particular prefix_sum for future iterations.
But to do this  prefix_sum - so_far_prefix_sums ==  given_sum we need to check one by one from hash table. 
But we can not check one by one every element from hashtable. Insted we rearrange the expression. see.
prefix_sum - so_far_prefix_sums ==  given_sum. Check this expression we know that given_sum is constant here and we do not need to check it traverse
from somewhere to get given_sum. So we just change LHS and RHS of this expression. And the new expression becomes - 
prefix_sum - given_sum = so_far_prefix_sums. So here prefix_sum is where we are currently pointing and given sum is already given.
so just need to check that prefix_sum - given_sum this expression's value is there or not in the hash table. If it is there then
we have our answer that there exist subarray sum. And if not then we are going to insert that prefix_sum into hash table so that
we can check for future expressions that prefix_sum - given_sum = so_far_prefix_sums. We have to check that this so_far_prefix_sums
whether or not exist in the hash table. And we have inserted this value, so_far_prefix_sums, into hash table when we did not satisfy this 
expression prefix_sum - given_sum = so_far_prefix_sums


*/




// logic 2

/*


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// This function correctly checks if a subarray with a given sum exists.
// It uses the optimized two-pass prefix sum and hash set technique.
bool subarrayWithGivenSum(int arr[], int n, int sum)
{
    // Handle the edge case of an empty array.
    if (n == 0)
    {
        return false;
    }

    unordered_set<int> us;
    vector<int> prefix_sum(n);

    // --- Pass 1: Build the prefix sum vector ---
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = arr[i] + prefix_sum[i - 1];
    }

    // --- Pass 2: Check for conditions using the hash set ---
    for (int i = 0; i < n; i++)
    {
        // Condition 1: Check if the prefix sum itself equals the target sum.
        // This covers all subarrays that start from index 0.
        // Example: arr=[1, 4, 2], sum=5. prefix_sum[1] is 5.
        if (prefix_sum[i] == sum)
        {
            return true;
        }
        
        // Condition 2: The main hash set logic.
        // We are looking for a previously seen prefix sum that is equal to
        // the current prefix sum minus the target sum.
        if (us.find(prefix_sum[i] - sum) != us.end())
        {
            return true;
        }

        // If no match is found, insert the current prefix sum into the set
        // to be used as a potential complement for future elements.
        us.insert(prefix_sum[i]);
    }

    // If the loops complete, no subarray with the given sum was found.
    return false;
}


*/