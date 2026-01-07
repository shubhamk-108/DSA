// Length of Longest Consecutive Subsequence. Elements can appear in any order. And elements are scattered all over the arry meaning
// {5,77,4} here longest sequencef is 2 even though there are 77 placed in between 5 and 4.
// {1,9,3,4,2,20} op = 4. explanation: 1,3,4,2 They are consecutive. Order does not matter.

// {20,30,40} op = 1


#include <iostream>
#include <algorithm>
#include<unordered_set>
using namespace std;

int longestConsecutiveSequence(int arr[], int n)
{
    if (n == 0)
        return 0;

    
    int longest = 1;

    unordered_set <int>us(arr, arr+n);

    for(auto element : us)
    {
        int current = 1;

        if(us.find(element - 1) != us.end())
        {
            continue;
        }
        else
        {
            int num = element;

            while(us.find(num+1) != us.end())
            {
                current++;
                num++;
            }
            longest = max(longest, current);
            
        }
    }
    return longest;

}

int main()
{
    int arr[] = {5, 6, 1, 2, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestConsecutiveSequence(arr, n);

    return 0;
}


// space and time 
/*


Time Complexity: O(n)
The time complexity is linear, or O(n), where 'n' is the number of elements in the input array. Here's the breakdown:
Set Insertion: unordered_set<int> us(arr, arr+n);
This is the first major operation. Inserting n elements into an unordered_set takes O(n) time on average, as each insertion is an O(1) operation.
Main Loop: for(auto element : us)
This loop runs once for each unique element in the array. In the worst case, all n elements are unique, so this loop runs n times.
Inner while loop: while(us.find(num+1) != us.end())
This is the crucial part. While it looks like a nested loop that would lead to O(n²), it is not. A number only enters the while loop if it is 
the start of a sequence. This means that each number in the set will be visited at most twice in total: once by the outer for loop and at most 
once by the inner while loop. Because we never re-count a sequence, the total number of operations across all loops remains proportional to n.
Therefore, the total time complexity is O(n) + O(n) = O(n).

Space Complexity: O(n)
The space complexity is also linear, or O(n).

*/


// logic

/*


int longestConsecutiveSequence(int arr[], int n)
{
    // --- Edge Case Handling ---
    // First, handle the simplest case: if the array is empty, the longest
    // sequence is 0. This prevents errors with an empty input.
    if (n == 0)
        return 0;

    // --- Data Structure Setup ---
    // Create an unordered_set from the array. This is the core of the
    // efficient solution.
    // Why a set? Because it gives us O(1) average time complexity to check
    // if a number exists, which is much faster than searching through an array.
    // The set also automatically handles any duplicate numbers for us.
    std::unordered_set <int> us(arr, arr + n);

    // --- Initialization ---
    // Initialize a variable to store the maximum length we've found so far.
    // We can start it at 1 because any non-empty array has at least a sequence of 1.
    int longest = 1;

    // --- Main Logic ---
    // Iterate through each UNIQUE element in the input.
    // Using the set `us` here is more efficient than iterating through the original `arr`
    // in case there were duplicate numbers.
    for (auto element : us)
    {
        // --- The "Key Trick": Find the Start of a Sequence ---
        // For each number, we check if its PREVIOUS number (element - 1) exists in the set.
        // If it does exist, then `element` is NOT the start of a new sequence.
        // It's just part of a sequence we will find later when the loop gets to the
        // actual starting number. So, we `continue` to the next element.
        if (us.find(element - 1) != us.end())
        {
            continue;
        }

        // --- Sequence Counting ---
        // If we've reached this point, it means `element` IS the start of a new sequence.
        // Now, and only now, we start counting its length.
        int currentStreak = 1;
        int currentNum = element;

        // Use a while loop to check for the NEXT number (currentNum + 1).
        // As long as the next consecutive number exists in our set,
        // we increment our streak and move to the next number.
        while (us.find(currentNum + 1) != us.end())
        {
            currentNum++;
            currentStreak++;
        }

        // --- Update Result ---
        // After the while loop finishes, `currentStreak` holds the total length
        // of the sequence we just found. We compare it with the `longest`
        // streak found so far and keep the larger one.
        longest = std::max(longest, currentStreak);
    }

    // --- Final Return ---
    // After checking all the elements, `longest` will hold the maximum length
    // found among all consecutive sequences. Return it.
    return longest;
}



*/