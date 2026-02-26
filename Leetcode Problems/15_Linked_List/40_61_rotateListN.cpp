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

        while (k--)
        {
            ListNode *curr = head;
            while (curr->next->next != nullptr)
            {
                curr = curr->next;
            }
            ListNode *newTail = curr;
            ListNode *originalTail = newTail->next;
            newTail->next = nullptr;

            originalTail->next = head;
            head = originalTail;
        }
        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Each rotation takes O(N)
Done k times
So:
O(N × k)
Worst case:
k ≈ N
→ O(N²)

🧠 Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


🎯 Goal

Rotate the linked list to the right by k positions.

Step 1: Handle Edge Cases
If:
List is empty
Only one node
k == 0
Return head.

Step 2: Find Length
Traverse once to compute length len.
This helps reduce unnecessary rotations.
Step 3: Reduce k
k = k % len
Because rotating len times returns the same list.
If k == 0, return head.

Step 4: Perform Rotation k Times
For each rotation:
Traverse to second-last node.
Store last node.
Break second-last → last connection.
Move last node to front.
Update head.
Repeat this k times.

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
        // Step 1: Edge case handling
        if (!head || !head->next || k == 0)
            return head;

        // Step 2: Calculate length
        int len = 1;
        ListNode *tail = head;

        while (tail->next)
        {
            len++;
            tail = tail->next;
        }

        // Step 3: Reduce unnecessary rotations
        k = k % len;
        if (k == 0)
            return head;

        // Step 4: Rotate one step at a time
        while (k--)
        {
            ListNode *curr = head;

            // Move to second last node
            while (curr->next->next != nullptr)
            {
                curr = curr->next;
            }

            ListNode *newTail = curr;
            ListNode *originalTail = newTail->next;

            // Break last node
            newTail->next = nullptr;

            // Move last node to front
            originalTail->next = head;
            head = originalTail;
        }

        return head;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
