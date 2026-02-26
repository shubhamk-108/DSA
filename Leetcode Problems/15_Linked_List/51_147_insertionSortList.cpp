/*
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first
element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

Input: head = [4,2,1,3]
Output: [1,2,3,4]

*/

#include <iostream>
#include <climits>
#include <vector>
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
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode dummyNode(INT_MIN);
        ListNode *curr = head;

        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = nullptr;

            ListNode *curr2 = &dummyNode;
            while (curr2->next && curr2->next->val < curr->val)
                curr2 = curr2->next;

            ListNode *nextNodeOfSortedList = curr2->next;
            curr2->next = curr;
            curr->next = nextNodeOfSortedList;
            curr = nextNode;
        }
        return dummyNode.next;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Worst Case: O(n²)
(For each node, we may traverse entire sorted list)
Best Case (already sorted): O(n)

📦 Space Complexity
O(1)
We only use:Few pointers
Dummy node
No extra data structure
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
🔹 Idea
We build a new sorted list one node at a time.
For each node in the original list:
Detach it
Find its correct position in the sorted list

Insert it there

🔹 Detailed Steps
Create a dummy node to represent the head of the sorted list.
Traverse the original list using curr.

For each node:
Save nextNode (so we don't lose the rest of the list).
Traverse the sorted list from dummy to find correct position.
Insert the node in that position.
Move to next original node.
Return dummy.next.

🔹 Why Dummy Helps?
It handles:
Insertion at head
Empty sorted list
Cleaner pointer manipulation



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        // Edge case: empty list or single node
        if (!head || !head->next)
            return head;

        // Dummy node for sorted list
        ListNode dummyNode(INT_MIN);

        // Current node in original list
        ListNode *curr = head;

        while (curr)
        {
            // Save next node before modifying links
            ListNode *nextNode = curr->next;

            // Optional: detach current node
            curr->next = nullptr;

            // Start from beginning of sorted list
            ListNode *curr2 = &dummyNode;

            // Find correct position to insert current node
            while (curr2->next && curr2->next->val < curr->val)
                curr2 = curr2->next;

            // Insert current node in sorted list
            ListNode *nextNodeOfSortedList = curr2->next;
            curr2->next = curr;
            curr->next = nextNodeOfSortedList;

            // Move to next node in original list
            curr = nextNode;
        }

        // Return sorted list head
        return dummyNode.next;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



This problem uses:
🔹 1. Dummy Node Pattern
Common in:
Merge two sorted lists
Partition list
Remove nth node
Reverse sublist
*/
