// Pair with given sum in unsorted array 

/*
Sample 1 (Pair Found)
Input Array: [8, 7, 2, 5, 3, 1]
Given Sum: 10
Reasoning: The pairs (8, 2) and (7, 3) both add up to 10. Since at least one pair exists, the condition is met.
Output: true

Sample 2 (Pair Not Found)
Input Array: [5, 2, 6, 8, 1, 9]
Given Sum: 12
Reasoning: No two numbers in this array add up to 12. For example, 5+2=7, 5+6=11, 9+2=11, 9+1=10, etc. After checking all
combinations, none equal 12.
Output: false

*/


#include <iostream>
#include<unordered_set>
using namespace std;

bool pairWithGivenSum(int arr[], int n, int sum)
{
    unordered_set<int>us;

    for(int i = 0; i<n; i++)
    {
        int first_element_of_pair = arr[i];
        int second_element_of_pair = sum - arr[i];

        if(us.find(second_element_of_pair) != us.end())
            return true;
        else
            us.insert(arr[i]);


    }
    return false;
}

int main()
{
    int arr1[] = {1,6, 2, 7, 8, 15, 15};
    
    int n = sizeof(arr1) / sizeof(arr1[0]);

    int sum = 8;

    cout<< pairWithGivenSum(arr1, n, sum);

    return 0;
}


// time space

/*

Time Complexity: O(n)
The reason this solution is so efficient is that it eliminates the nested loop.

The Loop: You iterate through the input array of size n exactly one time.

Inside the Loop: For each of the n elements, you perform two main operations:

us.find(): A lookup operation in a hash set.

us.insert(): An insertion operation into a hash set.

Hash Set Speed: Both find and insert in an unordered_set take O(1) time on average.

Total: Since you are performing a constant amount of work n times, the total time complexity is O(n) * O(1), which simplifies to O(n). 
This is also known as linear time complexity.

Space Complexity: O(n)
The space complexity is determined by the extra memory required by the unordered_set.

The unordered_set: In the worst-case scenario, if no pair is found, the hash set will store every single element from the input array

*/



// logic

/*

#include <iostream>
#include <unordered_set>
using namespace std;

// This function checks if a pair with a given sum exists in an array.
// It uses an unordered_set (hash set) for an efficient O(n) time complexity solution.
bool pairWithGivenSum(int arr[], int n, int sum)
{
    // Create an unordered_set to store the elements we have seen so far.
    // This gives us O(1) average time complexity for insertion and lookup.
    unordered_set<int> us;

    // Iterate through the array one element at a time.
    for (int i = 0; i < n; i++)
    {
        // For the current element, arr[i], we calculate what its "partner" or "complement"
        // would need to be to form the target sum.
        int first_element_of_pair = arr[i];
        int second_element_of_pair = sum - arr[i]; // This is the value we are looking for.

        // Now, we ask the critical question: "Have we already seen the partner?"
        // We check if the 'second_element_of_pair' is present in our hash set.
        // The find operation is extremely fast (O(1) on average).
        
        // Your comment is exactly right: us.find() returns an iterator. 
        // If the element is found, it returns an iterator to that element.
        // If it is NOT found, it returns an iterator equal to us.end().
        // us.end() points to a theoretical position "after" the last element.
        if (us.find(second_element_of_pair) != us.end())
        {
            // If the iterator is NOT us.end(), it means we found the complement!
            // A pair exists, so we can immediately return true.
            return true;
        }
        
        // If we did NOT find the complement, it means we haven't seen it yet.
        // So, we add the CURRENT element (arr[i]) to our set of "seen" numbers.
        // This way, it becomes a potential partner for a future element in the array.
        us.insert(arr[i]);
    }

    // If we iterate through the entire array and never find a pair,
    // it means no such pair exists. We can safely return false.
    return false;
}


*/


// dry run


/*


Trace with an Example
Let's trace arr = [3, 2, 8, 15, -7] and sum = 6.

i = 0, arr = 3:

Partner needed: 6 - 3 = 3.

Is 3 in the set? us is empty. No.

Insert 3 into us. us is now {3}.

i = 1, arr = 2:

Partner needed: 6 - 2 = 4.

Is 4 in the set? No. us only has {3}.

Insert 2 into us. us is now {3, 2}.

i = 2, arr = 8:

Partner needed: 6 - 8 = -2.

Is -2 in the set? No. us has {3, 2}.

Insert 8 into us. us is now {3, 2, 8}.

i = 3, arr = 15:

Partner needed: 6 - 15 = -9.

Is -9 in the set? No. us has {3, 2, 8}.

Insert 15 into us. us is now {3, 2, 8, 15}.

i = 4, arr = -7:

Partner needed: 6 - (-7) = 13.

Is 13 in the set? No. us has {3, 2, 8, 15}.

Insert -7 into us. us is now {3, 2, 8, 15, -7}.

The loop finishes. No pair was found. The function returns false.


*/