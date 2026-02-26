/*
You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

Image:

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *curr = head;

        while (curr != nullptr)
        {
            if (curr->child != nullptr)
            {
                Node *earlierNext = curr->next;
                Node *childHead = flatten(curr->child);
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                Node *tail = curr;
                while (tail->next != nullptr)
                    tail = tail->next;

                if (earlierNext != nullptr)
                {
                    tail->next = earlierNext;
                    earlierNext->prev = tail;
                }
                curr = tail->next;
            }
            else
                curr = curr->next;
        }
        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Aspect    | Complexity                              |
| --------- | --------------------------------------- |
| **Time**  | O(n) — each node visited exactly once   |
| **Space** | O(n) — recursion stack for deep nesting |

But here we are not traversing all nodes exactly once because once we connect our childHead to curr node
we again traverse to find the tail of the sub list. So some of the nodes are being visited twice.
Watch next solution for even better code.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal: Flatten a multilevel doubly linked list into a single-level doubly linked list in DFS preorder.
Strategy (Recursive DFS with tail tracking):
Traverse the list node by node.
If a node has a child:
Recursively flatten the child list.
Connect the child list between curr and curr->next.
Find the tail of the flattened child.
Reconnect the original next after the tail.
Continue to the next node.
Repeat until the end of the list.
This is tail-propagation recursive DFS.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *curr = head;

        while (curr != nullptr)
        {
            if (curr->child != nullptr)
            {
                Node *earlierNext = curr->next;

                // Flatten child recursively
                Node *childHead = flatten(curr->child);

                // Attach child
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                // Find tail of child list
                Node *tail = childHead;
                while (tail->next != nullptr)
                    tail = tail->next;

                // Reconnect the saved next node
                if (earlierNext != nullptr)
                {
                    tail->next = earlierNext;
                    earlierNext->prev = tail;
                }

                // Move curr to tail->next (so we skip all child nodes already processed)
                curr = tail->next;
            }
            else
            {
                // No child, just move forward
                curr = curr->next;
            }
        }

        return head;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern Used



*/
