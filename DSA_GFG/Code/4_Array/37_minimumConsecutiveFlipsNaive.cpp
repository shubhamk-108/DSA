// Our Task: Given a binary array, we need to convert this array into an array that either contains all 1s or all 0s.
// We need to do it using the minimum number of group flips.

// Input : arr[] = {1, 1, 0, 0, 0, 1}
// Output :  From 2 to 4

// Explanation: If we had flipped 1's then we need two flips. From 0 to 1 and from 5 to 5, {0,0,0,0,0,0}.
// But if we flipped from 2 to 4 then we need only one flip. {1,1,1,1,1,1}. And we want minimum number of flips so our op is from 2 to 4 or 1 flip

// Input : arr[] = {1, 0, 0, 0, 1, 0, 0, 1, 0, 1}
// Output :
// From 1 to 3
// From 5 to 6
// From 8 to 8

// Input : arr[] = {0, 0, 0}
// Output :
// Explanation : Output is empty, we need not to make any change

#include <iostream>
#include <cmath>
using namespace std;

void flipBits(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Empty Array " << endl;
        return;
    }

    int groups_of_zeros = 0;
    int groups_of_ones = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (i == 0 || arr[i - 1] == 1)
                groups_of_zeros++;
        }
        if (arr[i] == 1)
        {
            if (i == 0 || arr[i - 1] == 0)
                groups_of_ones++;
        }
    }

    if (groups_of_ones == 0 || groups_of_zeros == 0)
    {
        cout << "Array is already uniform. No flips needed." << endl;
        return;
    }

    int target_to_flip = (groups_of_zeros <= groups_of_ones) ? 0 : 1;

    std::cout << "Minimum flips required: " << std::min(groups_of_zeros, groups_of_ones) << std::endl;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target_to_flip)
        {
            int start_index_of_group_or_subarray = i;

            while (i + 1 < n && arr[i + 1] == target_to_flip)
            {
                i++;
            }

            int end_index = i;

            if (start_index_of_group_or_subarray == end_index)
            {
                std::cout << "Flip at index " << start_index_of_group_or_subarray << std::endl;
            }
            else
            {
                std::cout << "Flip from index " << start_index_of_group_or_subarray << " to " << end_index << std::endl;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 1, 0, 0, 1, 0, 0, 1}; // Groups of 0s: 2, Groups of 1s: 3
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n---" << std::endl;

    flipBits(arr, n);

    std::cout << "\n--- Example 2 ---" << std::endl;
    int arr2[] = {0, 0, 1, 1, 0, 1, 0, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    flipBits(arr2, n2);

    return 0;
}

// Time: O(n)
// space: O(1)



// Logic


/*



The mission of this code is to look at an array of 0s and 1s, figure out the minimum number of group flips needed to make the whole array the same, and then print out exactly which groups to flip.

Let's think of it as a three-step plan:

Step 1: Count the Groups. We need to scout the array to see how many separate groups of 0s and 1s there are.

Step 2: Make a Decision. Based on our count, we decide which number is "cheaper" to flip.

Step 3: Announce the Plan. We go through the array one last time and announce the start and end of each group that needs to be flipped.

We'll use this example from your code: arr = {1, 1, 0, 0, 1, 0, 0, 1}


-------------------------------------------------------------------------------------------


Step 1: Count the Groups (Lines 13-28)
The Goal: To find out how many groups of 0s and how many groups of 1s we have.


int groups_of_zeros = 0;
int groups_of_ones = 0;

for (int i = 0; i < n; i++)
{
    // Logic to count zero-groups
    if (arr[i] == 0)
    {
        if (i == 0 || arr[i - 1] == 1)
            groups_of_zeros++;
    }
    // Logic to count one-groups
    if (arr[i] == 1)
    {
        if (i == 0 || arr[i - 1] == 0)
            groups_of_ones++;
    }
}


This for loop visits every element. The clever part is how it identifies the start of a new group.

The condition if (i == 0 || arr[i - 1] == 1) means: "We've found the start of a new group of zeros if..."

"...we are at the very beginning of the array (i == 0)."

OR "...the element just before this one was a 1."

Let's trace it with arr = {1, 1, 0, 0, 1, 0, 0, 1}:

i=0, arr is 1. It's the start of a 1s-group. groups_of_ones = 1.

i=1, arr is 1. The element before it (arr) was also 1, so it's NOT the start of a new group.

i=2, arr is 0. The element before it (arr) was 1. This is the start of a new 0s-group. groups_of_zeros = 1.

i=3, arr is 0. The element before it was 0. Not a new group.

i=4, arr is 1. The element before it was 0. This is the start of a new 1s-group. groups_of_ones = 2.

i=5, arr is 0. The element before it was 1. This is the start of a new 0s-group. groups_of_zeros = 2.

i=6, arr is 0. The element before it was 0. Not a new group.

i=7, arr is 1. The element before it was 0. This is the start of a new 1s-group. groups_of_ones = 3.

After this loop, we know: groups_of_zeros = 2 and groups_of_ones = 3.


------------------------------------------------------------------------------------------------------------

Step 2: Make a Decision (Line 37)
The Goal: Decide which number is the better one to flip. We flip the one that has fewer groups.

int target_to_flip = (groups_of_zeros <= groups_of_ones) ? 0 : 1;


This is just a compact if-else statement.

It checks: Is groups_of_zeros (which is 2) less than or equal to groups_of_ones (which is 3)?

The answer is true.

So, target_to_flip is set to the first value, which is 0.

Our strategy is now set: We will flip all the 0s.


-------------------------------------------------------------------------------------------------------------


Step 3: Announce the Plan (Lines 41-61)
The Goal: Go through the array and find every group of our target_to_flip (which is 0) and print its start and end points.


for (int i = 0; i < n; i++)
{
    if (arr[i] == target_to_flip)
    {
        // ... code to find the group and print ...
    }
}
This for loop is our "group hunter". It's looking for the start of any group of 0s.

Let's trace this final loop:

i=0, arr is 1. Not our target. Loop continues.

i=1, arr is 1. Not our target. Loop continues.

i=2, arr is 0. We found one! It matches our target_to_flip.

We record the start: start_index_of_group_or_subarray = 2.

Now we enter the while loop to find the end of this same group.

while (i + 1 < n && arr[i + 1] == target_to_flip)
{
    i++;
}
This while loop is a "fast-forward" button. It says, "is the next element also a 0?"

At i=2, the next element arr is indeed 0. So the while loop increments i to 3.

Now i is 3. The while loop checks again. The next element arr is 1. It's not a 0, so the while loop stops.

We now know the group ends at the current position of i. So, end_index = 3.

The code prints: "Flip from index 2 to 3".

The for loop now continues, but i is already at 3. The next iteration will be i=4.

i=4, arr is 1. Not our target. Loop continues.

i=5, arr is 0. We found another one!

start_index_of_group_or_subarray = 5.

The while loop checks arr, which is 0. It increments i to 6.

The while loop checks arr, which is 1. It stops.

end_index = 6.

The code prints: "Flip from index 5 to 6".

The for loop continues from i=7.

i=7, arr is 1. Not our target.

The loop finishes.

The final output is correct. It found the two groups of 0s that need to be flipped.


*/  