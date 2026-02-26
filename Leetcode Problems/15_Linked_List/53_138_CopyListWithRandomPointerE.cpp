/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *curr = head;

        while (curr != NULL)
        {
            Node *NextNode = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = NextNode;
            curr = NextNode;
        }

        curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            if (curr->random == NULL)
                curr->next->random = nullptr;
            else
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        curr = head;
        Node *cloneHead = head->next;

        while (curr)
        {
            Node *copy = curr->next;
            curr->next = copy->next;
            
            if(copy->next)
            copy->next = copy->next->next;

            curr=curr->next;
        }
        return cloneHead;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
Step 1: O(n)
Step 2: O(n)
Step 3: O(n)
✅ Overall: O(n)

💾 Space Complexity
✅ O(1) extra space (output list doesn’t count)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

This problem asks for a deep copy of a linked list where each node has:
next pointer
random pointer (can point anywhere or be NULL)
The optimal solution avoids extra space (like a hash map) by using a 3-step in-place strategy:

Step 1: Interleave cloned nodes with original nodes
For every original node X, create a clone X' and insert it right after X.
Original:  X → Y → Z
Becomes:   X → X' → Y → Y' → Z → Z'

Step 2: Assign random pointers to cloned nodes
Because clones are placed immediately after originals:
If X.random = Y
Then X'.random = Y.next
This works in O(1) time per node.

Step 3: Separate the two lists
Restore the original list and extract the cloned list by fixing next pointers.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // Edge case: empty list
        if (head == nullptr)
            return nullptr;

        Node *curr = head;

        // -------------------------------------------------
        // STEP 1: Interleave copied nodes with originals
        // -------------------------------------------------
        // For each original node:
        // Create its copy and insert it right after the original node.
        //
        // Example:
        // A -> B -> C
        // becomes
        // A -> A' -> B -> B' -> C -> C'
        //
        while (curr != NULL)
        {
            Node *NextNode = curr->next;          // Store next original node
            curr->next = new Node(curr->val);     // Create copy node
            curr->next->next = NextNode;          // Link copy to next original
            curr = NextNode;                      // Move to next original node
        }

        // -------------------------------------------------
        // STEP 2: Assign random pointers to copied nodes
        // -------------------------------------------------
        // If original node's random = R,
        // then copy's random = R->next
        // because R->next is the copied version of R.
        //
        curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            if (curr->random == NULL)
                curr->next->random = nullptr;   // If original random is null
            else
                curr->next->random = curr->random->next; // Assign copied random

            curr = curr->next->next;  // Move to next original node
        }

        // -------------------------------------------------
        // STEP 3: Separate original list and copied list
        // -------------------------------------------------
        // Current structure:
        // A -> A' -> B -> B' -> C -> C'
        //
        // We must:
        // 1. Restore original list
        // 2. Extract copied list
        //
        curr = head;
        Node *cloneHead = head->next;  // Head of copied list

        while (curr)
        {
            Node *copy = curr->next;   // Copied node

            curr->next = copy->next;   // Restore original list link

            // Fix copied list link (if next exists)
            if (copy->next)
                copy->next = copy->next->next;

            curr = curr->next;         // Move to next original node
        }

        // Return deep copied list head
        return cloneHead;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
