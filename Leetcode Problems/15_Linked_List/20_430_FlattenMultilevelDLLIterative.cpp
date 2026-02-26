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
#include <stack>
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
            return head;
        Node *curr = head;

        stack<Node *> st;

        while (curr != nullptr)
        {
            if (curr->child != nullptr)
            {
                if (curr->next != nullptr)
                    st.push(curr->next);
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;
            }

            if (curr->next == nullptr && !st.empty())
            {
                curr->next = st.top();
                st.top()->prev = curr;
                st.pop();
            }

            curr = curr->next;
        }

        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity 
O(n)
Every node is visited exactly once
💾 Space Complexity
O(n) worst case
Stack stores nodes when the list is deeply nested

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal
Flatten a multilevel doubly linked list so that:
All nodes appear in DFS preorder
child pointers are removed
prev and next pointers remain valid
Key idea
Whenever a node has a child, process the child first (DFS), and come back to the original next later.
To do this iteratively, we:
Use a stack to remember where to return
Rewire pointers in place
Strategy
Traverse the list using curr
If curr has a child:
Save curr->next on a stack (if it exists)
Connect curr → child
Fix prev
Remove child
If we reach the end of a list:
Pop a node from the stack
Continue traversal
Move forward
This mimics recursive DFS, but without recursion.

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
        // Edge case: empty list
        if (head == nullptr)
            return head;

        Node *curr = head;

        // Stack to remember next nodes when diving into child lists
        stack<Node *> st;

        while (curr != nullptr)
        {
            // Case 1: current node has a child
            if (curr->child != nullptr)
            {
                // Save the next node to return to later
                if (curr->next != nullptr)
                    st.push(curr->next);

                // Connect current node to its child
                curr->next = curr->child;
                curr->next->prev = curr;

                // Remove child pointer
                curr->child = nullptr;
            }

            // Case 2: reached end of current list, resume from stack
            if (curr->next == nullptr && !st.empty())
            {
                curr->next = st.top();
                st.top()->prev = curr;
                st.pop();
            }

            // Move forward
            curr = curr->next;
        }

        return head;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Depth-First Search (DFS) using an explicit stack with in-place pointer manipulation

*/
