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
        ListNode *temp = head;

        for (int i = 0; i < k; i++)
        {
            if (temp == nullptr)
                return head;
            temp = temp->next;
        }

        ListNode *curr = head;
        ListNode *nextNode = NULL;
        ListNode *prevNode = NULL;
        int count = k;
        while (curr != NULL && count > 0)
        {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
            count--;
        }

        ListNode *headOfGroup = reverseKGroup(curr, k);
        head->next = headOfGroup; 

        return prevNode;
    }
};




//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(N)

O(N / k) → recursion stack
Because:\
Each recursive call processes k nodes
Total depth ≈ N/k
Worst case when k = 1 → O(N)\
If implemented iteratively → O(1) extra space.
*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*
We solve the problem in three clear phases:
🔹 Phase 1: Validate that k nodes exist
Before reversing, we check whether there are at least k nodes available.
Why?
Because the problem states:
If the remaining nodes are fewer than k, leave them as they are.
So we scan k nodes ahead using a temporary pointer.
If at any point we hit nullptr, we return head unchanged.

🔹 Phase 2: Reverse exactly k nodes
We reverse the first k nodes using standard linked list reversal logic:
prevNode
cur
nextNode
After reversing:
prevNode → new head of reversed block
head → becomes tail of reversed block
curr → start of remaining list

🔹 Phase 3: Recursively process remaining list
We recursively reverse the remaining list in k-groups:
head->next = reverseKGroup(curr, k);

Then return the new head of the current reversed block.



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
        // Step 1: Check if at least k nodes exist
        ListNode *temp = head;

        for (int i = 0; i < k; i++)
        {
            if (temp == nullptr)
                return head;   // Not enough nodes → do not reverse
            temp = temp->next;
        }

        // Step 2: Reverse first k nodes
        ListNode *curr = head;
        ListNode *nextNode = NULL;
        ListNode *prevNode = NULL;
        int count = k;

        while (curr != NULL && count > 0)
        {
            nextNode = curr->next;   // store next
            curr->next = prevNode;   // reverse link
            prevNode = curr;         // move prev forward
            curr = nextNode;         // move curr forward
            count--;
        }

        // Step 3: Recursively reverse remaining nodes
        ListNode *headOfGroup = reverseKGroup(curr, k);

        // Connect tail of current reversed block to result
        head->next = headOfGroup;

        // Return new head of this block
        return prevNode;
    }
};



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/

