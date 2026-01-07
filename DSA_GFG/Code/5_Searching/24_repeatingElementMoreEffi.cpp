// In this problem, we have an array where each element appears only once except for a single element that has
// multiple occurrences. Additionally, the array always contains the number 0, and if the maximum element in the array
// is x, then all elements from 0 to x are guaranteed to be present in the array
// we are not allow to modify array

// we have assume that elements in array are positive integers

/*

Floyd's Cycle-Finding Algorithm:


Floyd's Cycle-Finding Algorithm (also called the Tortoise and the Hare Algorithm) from the ground up. It's a brilliantly clever
method used to determine if a sequence has a loop, and if so, where that loop begins.

The Core Idea: A Race
The algorithm uses a simple, elegant analogy: a race between a slow Tortoise and a fast Hare.

Two Pointers: We use two pointers, slow (the Tortoise) and fast (the Hare). Both start at the very beginning of the path.

Different Speeds: With each tick of the clock, they move:

The slow pointer advances one step.

The fast pointer advances two steps.

What Happens During the Race?
There are two possible outcomes:

Outcome 1: No Cycle
If the path is a straight line with an end (like a linked list ending in NULL), the fast Hare will simply reach the end first. The
Tortoise will be somewhere behind. If the fast pointer reaches the end, we can definitively say there is no cycle.

Outcome 2: A Cycle Exists
If there is a cycle, both pointers will eventually enter it. Once inside the cycle, the fast Hare, moving at double the speed, will
 inevitably catch up to and "lap" the slow Tortoise. They are guaranteed to land on the exact same spot at the same time.

The First Key Insight: If the slow and fast pointers ever meet at the same position, you have proven that a cycle exists.

The Two Phases of the Algorithm
Floyd's algorithm is a two-act play.

Act I: Detect the Cycle (Find the Meeting Point)
This is the race we just described.

Start slow and fast at the beginning.

In a loop, move slow by one step and fast by two steps.

Continue until slow and fast are at the same position. This position is the meeting point.

This phase answers the question: "Is there a loop?" If they meet, the answer is yes.

Act II: Find the Start of the Cycle
This is the non-intuitive, "magical" part of the algorithm. Once the Tortoise and Hare have met, how do you find the exact spot
where the path first becomes a circle?

The algorithm provides a surprisingly simple procedure:

Leave the fast pointer at the meeting point.

Reset the slow pointer back to the very beginning of the path.

Now, advance both pointers by one step at a time.

The place where they meet this second time is the start of the cycle.

The Second Key Insight: After finding an initial meeting point, resetting one pointer to the start and moving both at the same speed
 will cause them to collide precisely at the entrance to the loop. This has a clean mathematical proof based on the distances they
 traveled in Act I.

Why is This Algorithm So Great?
Floyd's Cycle-Finding Algorithm is celebrated for its efficiency:

Time Complexity: O(N). The algorithm will, at most, traverse the list a constant number of times. The time it takes is proportional
to the number of nodes, N.

Space Complexity: O(1). This is its most beautiful feature. It doesn't require any extra memory, hash maps, or visited arrays. It
solves the problem "in-place" using just two pointers.

It's a powerful tool for detecting loops in linked lists, finding repeating numbers in certain types of arrays, and even for
detecting patterns in pseudo-random number generators



*/

//_______________________________________________________________________________________________________________________

/*


what if array sixe if 5 and we have element as 60 then wholdnt it be arr[60]. How is that
This algo has some constraints that:

Scenario A: An array of size n+1 contains integers in the range [1, n]. (Notice 0 is excluded, and the values can't be bigger than n).

Scenario B: An array of size n contains integers in the range [0, n-1].

In both scenarios, if you pick any value x from the array, arr[x] will always be a valid memory access.


*/

#include <iostream>
using namespace std;

int repeatingElement(int arr[], int n )
{
    int slow = arr[0];
    int fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}


int main() {
    

 int arr[] = {1, 3, 2, 4, 6, 5, 7, 3}, n= 8;

 cout << repeatingElement(arr, n);

	return 0;
}

// time : O(n)
// space:O(1)


// Logic



/*



 * @brief Finds a repeating element in an array using Floyd's Cycle-Finding Algorithm.
 *
 * This function treats the array as a functional linked list where the value at an
 * index points to the next index in a sequence. It detects the cycle created by the
 * repeating number.
 *
 * IMPORTANT ASSUMPTIONS FOR THIS CODE TO BE CORRECT:
 * 1. The array contains N+1 integers.
 * 2. The integers are in the range [1, N].
 * 3. These constraints guarantee that a cycle must exist and all values are valid indices.
 *


int repeatingElement(int arr[], int n)
{
    // --- PHASE 1: FIND THE MEETING POINT INSIDE THE CYCLE ---

    // Initialize two pointers, 'slow' (the Tortoise) and 'fast' (the Hare).
    // Both start their journey from the beginning of the path, which is defined by the value at arr[0].
    int slow = arr[0];
    int fast = arr[0];

    // The do-while loop ensures the pointers move at least once before their first comparison.
    // This is necessary because they start at the same position.
    do
    {
        // The Tortoise moves one step forward in the sequence.
        slow = arr[slow];

        // The Hare moves two steps forward in the sequence.
        fast = arr[arr[fast]];

    } while (slow != fast); // The loop continues until they land on the same element.

    // At this point, 'slow' and 'fast' are at a meeting point somewhere inside the cycle.
    // This meeting point is NOT necessarily the start of the cycle.

    // --- PHASE 2: FIND THE ACTUAL START OF THE CYCLE ---

    // Reset the 'slow' pointer back to the beginning of the path.
    // The 'fast' pointer remains at the meeting point found in Phase 1.
    slow = arr[0];

    // Now, move both pointers one step at a time.
    // The point where they meet again is mathematically guaranteed to be the start of the cycle.
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    // The start of the cycle is the first element that is part of the repeating sequence.
    // This is our repeating number.
    return slow;
}



*/