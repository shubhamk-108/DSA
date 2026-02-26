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
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
             
        ListNode *slow = head;
        ListNode *fast = head;
        int len = 0;
        ListNode *curr = head;

        while (curr)
        {
            len++;
            curr = curr->next;
        }

        int rotateCount = k % len;
        if(rotateCount==0)
            return head;

        for (int i = 0; i < rotateCount; i++)
            fast = fast->next;

        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *newHead = slow->next;
        slow->next = nullptr;

        curr = newHead;

        while (curr->next)
            curr = curr->next;

        curr->next = head;
        head = newHead;

        return head;
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
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
First traversal → O(N)
Second traversal (two pointers) → O(N)
Final tail traversal → O(N)
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

🎯 Goal

Rotate the linked list to the right by k places.

Step 1: Handle Edge Cases
If:
The list is empty
The list has only one node
k == 0
Then rotation is unnecessary. Return head.

Step 2: Find Length of the List
Traverse once to compute:
Total number of nodes (len)
This is required because:
Rotating more than len times repeats the pattern.
Step 3: Reduce Rotations

Compute
rotateCount = k % len
Because rotating len times brings the list back to original state.
If rotateCount == 0, return head.

Step 4: Two-Pointer Technique
Move fast pointer rotateCount steps ahead.
Then move both slow and fast together until fast reaches the last node.
At this point:
slow will be at the new tail.
slow->next will be the new head.

Step 5: Rearrangement
Store newHead = slow->next
Break link: slow->next = nullptr
Traverse from newHead to its tail
Connect that tail to original head
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
        // Edge case handling
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;

        int len = 0;
        ListNode *curr = head;

        // Step 1: Calculate length
        while (curr)
        {
            len++;
            curr = curr->next;
        }

        // Step 2: Reduce k using modulus
        int rotateCount = k % len;

        // If rotation equals length, no change needed
        if (rotateCount == 0)
            return head;

        // Step 3: Move fast pointer rotateCount steps ahead
        for (int i = 0; i < rotateCount; i++)
            fast = fast->next;

        // Step 4: Move both pointers until fast reaches last node
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // slow is now at new tail
        ListNode *newHead = slow->next;

        // Break the list
        slow->next = nullptr;

        // Step 5: Traverse from newHead to its tail
        curr = newHead;
        while (curr->next)
            curr = curr->next;

        // Connect tail to original head
        curr->next = head;

        return newHead;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Fast & Slow Pointer (Two-Pointer Technique)
You maintain a fixed gap of k between two pointers.



*/
