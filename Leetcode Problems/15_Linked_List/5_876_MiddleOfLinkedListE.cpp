/*
Given the head of a singly linked list, return the middle ListNode of the linked list.

If there are two middle nodes, return the second middle ListNode.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Single traversal of list
👉 O(n)

💾 Space Complexity
Only two pointers used
👉 O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Initialize two pointers
slow and fast both start at head.
Move pointers at different speeds
slow moves one node at a time
fast moves two nodes at a time

Stopping condition
When fast reaches the end of the list (or becomes NULL),
slow will be at the middle node.

Why this works
Since fast moves twice as fast as slow,
when fast has traversed the entire list,
slow has traversed half of it.

Result
slow points to the middle node
Return slow->data


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

int findMiddlle(Node *head)
{
    // If the linked list is empty, no middle exists
    if (head == NULL)
        return -1;

    // Slow pointer moves one step at a time
    Node *slow = head;

    // Fast pointer moves two steps at a time
    Node *fast = head;

    // Traverse the list until fast reaches the end
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;          // move slow by 1 node
        fast = fast->next->next;    // move fast by 2 nodes
    }

    // When loop ends, slow points to the middle node
    return slow->data;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two Pointer Technique
Also called Tortoise and Hare Algorithm


*/
