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
        int count = 0;
        ListNode *curr;
        for (curr = head; curr != NULL; curr = curr->next)
            count++;

        curr = head;
        for (int i = 0; i < count / 2; i++)
            curr = curr->next;
        return curr;
    }
};
       
// timespace
/*
Time Complexity
First traversal → O(n)
Second traversal → O(n)
👉 Total Time = O(n)
💾 Space Complexity
👉 Space = O(1)
*/

// approach 

/*

Counts the number of nodes.
Traverses again to reach the middle node.
Returns the middle node’s data.
For even number of nodes, it returns the second middle, which is standard in many problems.
Example:
1 → 2 → 3 → 4 → returns 3
1 → 2 → 3 → 4 → 5 → returns 3

🧠 Approach (Naive / Two Traversals)

Step 1: Count nodes
Traverse the linked list from head to NULL
Store total number of nodes in count

Step 2: Move to middle
Middle index = count / 2
Traverse again from head for count / 2 steps
The node reached is the middle node

*/


//code

/*
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        // If the list is empty, there is no middle
        if (head == NULL)
            return NULL;

        int count = 0;
        ListNode *curr;

        // First pass: count total number of nodes
        for (curr = head; curr != NULL; curr = curr->next)
            count++;

        // Reset pointer back to head
        curr = head;

        // Second pass: move count/2 steps to reach the middle node
        for (int i = 0; i < count / 2; i++)
            curr = curr->next;

        // curr now points to the middle node
        // (for even length, this returns the second middle as required)
        return curr;
    }
};



*/