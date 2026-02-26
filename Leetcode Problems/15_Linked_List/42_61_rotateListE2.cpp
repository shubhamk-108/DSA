/*
Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Input: head = [0,1,2], k = 4
Output: [2,0,1]

*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        int len = 1;
        ListNode *tail = head;

        while (tail->next)
        {
            len++;
            tail = tail->next;
        }

        k = k % len;
        if (k == 0)
            return head;

        tail->next = head;

        int stepsToNewTail = len - k;
        ListNode *newTail = head;

        for (int i = 1; i < stepsToNewTail; i++)
            newTail = newTail->next;

        ListNode *newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

//___________________________________________________________________________________________________________________________________________
// Modulo rule
//___________________________________________________________________________________________________________________________________________

/*
Rotating by the length of the list brings it back to the same position.
Rotating 5 → same list
Rotating 10 → same list

So any k > len is effectively reduced to:
k % len

Example with k > len
k = 7
len = 5
rotateCount = k % len = 7 % 5 = 2
So rotating 7 steps is the same as rotating 2 steps.

Example with k == len
k = 5
len = 5
rotateCount = k % len = 5 % 5 = 0
Means no rotation is needed

Return head immediately
Example with k < len
k = 3
len = 5
rotateCount = 3 % 5 = 3
Rotate 3 steps as usual

🔹 Rule in Words
Always reduce k by the length of the list using modulus: k = k % len.
This ensures:
We never move more than necessary
Avoids extra passes
Covers k == len and k > len automatically


*/

//___________________________________________________________________________________________________________________________________________
// About array vs Linked list rotation
//___________________________________________________________________________________________________________________________________________

/*

you cannot implement array rotation exactly like linked list rotation (by “breaking and reconnecting nodes”) because arrays don’t have
pointers connecting elements — they are contiguous blocks of memory.

What We Can Do in Array

You still use the modulo concept, but differently:

To compute where an element goes:

new_index = (i + k) % n


Or use the reverse trick:

Rotate right by k:
1. Reverse whole array
2. Reverse first k elements
3. Reverse remaining n-k elements


Both use k % n to reduce extra rotations. But in linked list modulo is somewhat different. index i = (i + k ) % n
But no pointer connections happen

*/

//___________________________________________________________________________________________________________________________________________
// why len is initiated from 1 and not 0.
//___________________________________________________________________________________________________________________________________________

/*
Because we are checking tail->next is not null in while loop. SO for last node tail this condition is correct. So
for last node it wont go in while block and we will loose last node's count. So we directly take 1 from start.


*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
One traversal to find length → O(N)
One traversal to reach newTail → O(N)
Overall:
O(N)

🧠 Space Complexity
No extra data structures used.
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Step 1: Handle Edge Cases
If:
List is empty
Only one node
k == 0
Then no rotation needed → return head.

Step 2: Find Length and Tail
Traverse once to:
Count total nodes (len)
Reach the last node (tail)
We need:
Length to reduce unnecessary rotations
Tail to create circular structure

Step 3: Reduce Rotations
k = k % len
Why?
Because rotating len times gives original list.
If k == 0, return head.

Step 4: Make List Circular
Connect:
tail->next = head
Now the list becomes a circular linked list.

Step 5: Find New Tail
New tail is at:
len - k steps from head
Move pointer len - k - 1 times forward.

Step 6: Break the Circle
newHead = newTail->next
newTail->next = nullptr
Return newHead.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        // Step 1: Handle edge cases
        if (!head || !head->next || k == 0)
            return head;

        // Step 2: Find length and tail
        int len = 1;
        ListNode *tail = head;

        while (tail->next)
        {
            len++;
            tail = tail->next;
        }

        // Step 3: Reduce k using modulus
        k = k % len;
        if (k == 0)
            return head;

        // Step 4: Make list circular
        tail->next = head;

        // Step 5: Find new tail (len - k steps ahead)
        int stepsToNewTail = len - k;
        ListNode *newTail = head;

        for (int i = 1; i < stepsToNewTail; i++)
            newTail = newTail->next;

        // Step 6: Break the circle
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Circular Linked List Transformation Pattern


*/
