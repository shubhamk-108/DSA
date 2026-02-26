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
private:
    Node *flattenDFS(Node *head)
    {
        Node *curr = head;
        Node *tail = head;

        while (curr)
        {
            Node *earlierNext = curr->next;

            if (curr->child)
            {
                Node *childTail = flattenDFS(curr->child);

                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;

                if (earlierNext)
                {
                    childTail->next = earlierNext;
                    earlierNext->prev = childTail;
                }
                tail = childTail;
            }
            else
                tail = curr;

            curr = earlierNext;
        }
        return tail;
    }

public:
    Node *flatten(Node *head)
    {
        flattenDFS(head);
        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// why we need to seperate call
//___________________________________________________________________________________________________________________________________________

/*

because in all the call we have to return tail of the sub list so that we can join that tail to earlier curr->next. But in the very
last call we need to return head to the main function.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Aspect    | Complexity                              |
| --------- | --------------------------------------- |
| **Time**  | O(n) — each node visited exactly once   |
| **Space** | O(n) — recursion stack for deep nesting |


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
private:
    // Recursive helper that flattens the list starting at 'head' and returns the tail
    Node *flattenDFS(Node *head)
    {
        Node *curr = head;
        Node *tail = head; // tail of current flattened segment

        while (curr)
        {
            Node *earlierNext = curr->next; // save original next

            if (curr->child)
            {
                // Recursively flatten the child list
                Node *childTail = flattenDFS(curr->child);

                // Attach child list
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;

                // Connect the tail of child to the original next
                if (earlierNext)
                {
                    childTail->next = earlierNext;
                    earlierNext->prev = childTail;
                }

                // Update tail to the tail of child list
                tail = childTail;
            }
            else
            {
                // No child, update tail to current node
                tail = curr;
            }

            // Move to next node (original next, saved earlier)
            curr = earlierNext;
        }

        return tail; // return tail of this flattened segment
    }

public:
    Node *flatten(Node *head)
    {
        flattenDFS(head); // flatten the entire list
        return head;      // head remains unchanged
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Recursive Depth-First Search (DFS)
Tail propagation recursion — each recursive call returns the tail of its segment
In-place pointer rewiring for doubly linked list

*/
