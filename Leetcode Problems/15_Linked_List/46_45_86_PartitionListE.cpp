/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.


Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
*/

#include <iostream>
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *curr = head;
        ListNode dummyNode1(0);
        ListNode *dummyNode1Tail = &dummyNode1;
        ListNode dummyNode2(0);
        ListNode *dummyNode2Tail = &dummyNode2;

        while (curr)
        {
            ListNode *nextNode = nullptr;
            nextNode = curr->next;
            if (curr->val < x)
            {
                curr->next = nullptr;
                dummyNode1Tail->next = curr;
                dummyNode1Tail = curr;
            }
            else
            {
                curr->next = nullptr;
                dummyNode2Tail->next = curr;
                dummyNode2Tail = curr;
            }
            curr = nextNode;
        }
        if (dummyNode1Tail == &dummyNode1)
            return dummyNode2.next;
        else
        {
            dummyNode1Tail->next = dummyNode2.next;
            return dummyNode1.next;
        }
    }
};

//___________________________________________________________________________________________________________________________________________
// why not ListNode *dummyNode1 = new ListNode(0); and why prefer this ListNode dummyNode1(0);
//___________________________________________________________________________________________________________________________________________

/*

When you write:

ListNode *dummyNode1 = new ListNode(0);
Memory is allocated on the heap
You must manually delete it
If not deleted → memory leak
In LeetCode it doesn’t matter much (short-lived program),
but in real systems or interviews → it shows discipline.

When you write:
ListNode dummyNode1(0);
Memory is allocated on the stack
It is automatically destroyed when function ends
No manual delete required
No memory leak risk

*/

//___________________________________________________________________________________________________________________________________________
// listnode *dummy = null and  listnode dummy(10) understanding
//___________________________________________________________________________________________________________________________________________

/*

We compare:

ListNode *dummy = NULL;


vs

ListNode dummy(10);

🔹 1️⃣ ListNode *dummy = NULL;
What is this
This is a pointer variable
It currently points to nothing
No ListNode object is created
Memory used:
Only space for a pointer (usually 8 bytes)
So right now:

❌ No node exists
✅ Only a pointer variable exists
If later you do:
dummy = new ListNode(10);
Then:
Node is created on heap
Pointer stores its address

🔹 2️⃣ ListNode dummy(10);
What is this?
This creates an actual ListNode object
It is allocated on the stack
It has:
val = 10
next pointer

So:
✅ A real node exists
❌ No pointer variable needed (unless you take its address)

| Code                                  | What Exists                   | Where Stored |
| ------------------------------------- | ----------------------------- | ------------ |
| `ListNode *dummy = NULL;`             | Only pointer  variable        | Stack        |
| `ListNode dummy(10);`                 | Full node object              | Stack        |
| `ListNode *dummy = new ListNode(10);` | Pointer (stack) + Node (heap) | Both         |

You asked:
Does either take O(1) space?
Yes ✅ — all of them are O(1).
Because:
They do NOT depend on n

*/


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Single traversal:
O(n)

🗂 Space Complexity
Only dummy nodes:
O(1) extra space
(We reuse existing nodes.)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Partition the list such that:
All nodes < x come first
All nodes >= x come after
Relative order is preserved
🧠 Core Idea – Stable Two-List Partition
Create two dummy nodes:
dummyNode1 → for nodes < x
dummyNode2 → for nodes >= x
Traverse original list once.
For each node:
Detach it (curr->next = nullptr)
Attach it to the appropriate list
Move the corresponding tail
After traversal:
Connect smaller list to larger list
Return head of smaller list (or larger if smaller is empty)


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        // Pointer to traverse original list
        ListNode *curr = head;

        // Dummy node for list containing values < x
        ListNode *dummyNode1 = new ListNode(0);
        ListNode *dummyNode1Tail = dummyNode1;

        // Dummy node for list containing values >= x
        ListNode *dummyNode2 = new ListNode(0);
        ListNode *dummyNode2Tail = dummyNode2;

        // Traverse original list
        while (curr)
        {
            // Store next node before breaking link
            ListNode *nextNode = nullptr;

            if (curr->val < x)
            {
                // Save next node
                nextNode = curr->next;

                // Detach current node to avoid cycles
                curr->next = nullptr;

                // Append current node to "smaller than x" list
                dummyNode1Tail->next = curr;

                // Move tail forward
                dummyNode1Tail = curr;
            }
            else
            {
                // Save next node
                nextNode = curr->next;

                // Detach current node
                curr->next = nullptr;

                // Append current node to "greater or equal to x" list
                dummyNode2Tail->next = curr;

                // Move tail forward
                dummyNode2Tail = curr;
            }

            // Move to next node in original list
            curr = nextNode;
        }

        // If no nodes were added to smaller list,
        // return head of larger list
        if (dummyNode1Tail == dummyNode1)
            return dummyNode2->next;
        else
        {
            // Connect smaller list to larger list
            dummyNode1Tail->next = dummyNode2->next;

            // Return head of smaller list (skip dummy)
            return dummyNode1->next;
        }
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

✅ Stable Partition Pattern
✅ Two Dummy List Technique
Very common in:
Partition List
Odd-Even Linked List
Merge sorted lists
Segregate even/odd


*/
