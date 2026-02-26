/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

*/

#include <iostream>
#include <stack>
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || k <= 1)
            return head;

        ListNode *curr = head;
        ListNode *nextNode = nullptr;
        ListNode *prevNode = nullptr;
        ListNode *newHead = nullptr;
        ListNode *tailOfPrevGroupAfterReversal = NULL;
        bool isFirstGroup = true;

        while (curr != NULL)
        {
            ListNode *temp = curr;
            for (int i = 0; i < k; i++)
            {
                if (temp == nullptr)
                {
                    if (isFirstGroup)
                        return head;
                    else
                    {
                        tailOfPrevGroupAfterReversal->next = curr;
                        return newHead;
                    }
                }
                temp = temp->next;
            }

            prevNode = NULL;
            ListNode *groupHeadBeforeReversal = curr;
            int count = 0;
            while (curr != NULL && count < k)
            {
                nextNode = curr->next;
                curr->next = prevNode;
                prevNode = curr;
                curr = nextNode;
                count++;
            }
            if (isFirstGroup)
            {
                isFirstGroup = false;
                newHead = prevNode;
            }
            else
            {
                tailOfPrevGroupAfterReversal->next = prevNode;
            }
            tailOfPrevGroupAfterReversal = groupHeadBeforeReversal;
        }
        return newHead;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(N)
Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


High-Level Idea
We process the linked list in blocks of size k.
For every block:
Check whether k nodes are available.
If yes, reverse those k nodes.
Connect the reversed block to the previous block.
Move forward and repeat.
If fewer than k nodes remain, leave them unchanged.

🔹 Step 1: Handle Edge Cases
If the list is empty or k is less than or equal to 1, no reversal is needed.

🔹 Step 2: Process the List Group by Group
We iterate through the list while maintaining:
A pointer to the current node (start of the group).
A pointer to the tail of the previously reversed group.
A pointer to store the new head after the first reversal.

🔹 Step 3: Check If k Nodes Exist
Before reversing a group, we verify that at least k nodes remain ahead.
This prevents partial reversal of a group smaller than k, which the problem explicitly disallows.
If fewer than k nodes remain:
If no reversal has happened yet, return the original head.
Otherwise, connect the previous group’s tail to the remaining nodes and terminate.

🔹 Step 4: Reverse the Current k-Group
We reverse exactly k nodes using standard in-place linked list reversal.
After reversing:
The original group head becomes the tail.
The last node of the group becomes the new head of this block.
We still have a pointer to the start of the next group.

🔹 Step 5: Connect Groups
If this is the first group, update the overall new head.
Otherwise, connect the previous group’s tail to the new head of the reversed block.
Then update the previous group’s tail pointer to the tail of the current block.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || k <= 1)
            return head;

        ListNode *curr = head;
        ListNode *nextNode = nullptr;
        ListNode *prevNode = nullptr;
        ListNode *newHead = nullptr;
        ListNode *tailOfPrevGroupAfterReversal = NULL;
        bool isFirstGroup = true;

        while (curr != NULL)
        {
            // Step 1: Check if at least k nodes exist
            ListNode *temp = curr;
            for (int i = 0; i < k; i++)
            {
                if (temp == nullptr)
                {
                    // Not enough nodes, attach remaining and return
                    if (isFirstGroup)
                        return head;
                    else
                    {
                        tailOfPrevGroupAfterReversal->next = curr;
                        return newHead;
                    }
                }
                temp = temp->next;
            }

            // Step 2: Reverse k nodes
            prevNode = NULL;
            ListNode *groupHeadBeforeReversal = curr;
            int count = 0;

            while (curr != NULL && count < k)
            {
                nextNode = curr->next;
                curr->next = prevNode;
                prevNode = curr;
                curr = nextNode;
                count++;
            }

            // Step 3: Connect with previous group
            if (isFirstGroup)
            {
                isFirstGroup = false;
                newHead = prevNode;
            }
            else
            {
                tailOfPrevGroupAfterReversal->next = prevNode;
            }

            // Update tail pointer
            tailOfPrevGroupAfterReversal = groupHeadBeforeReversal;
        }

        return newHead;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
