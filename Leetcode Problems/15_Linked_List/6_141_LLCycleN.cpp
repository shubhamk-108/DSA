/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some ListNode in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the ListNode that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st ListNode (0-indexed).

Input: head = [1], pos = -1
Output: false
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
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> us;
        while (head != NULL)
        {
            if (us.find(head) != us.end())
                return true;

            us.insert(head);
            head = head->next;
        }
        return false;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

⏱ Time Complexity
O(n)
Each node is visited once (average case).

📦 Space Complexity
O(n)
Extra space for the hash set.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Traverse the linked list from the head.
Store addresses of visited nodes in a hash set.
Before visiting a node:
Check if it already exists in the set.
If yes → loop detected.
If traversal reaches NULL → no loop.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

bool detectLoop(Node *head)
{
    unordered_set<Node *> us;

    while (head != NULL)
    {
        // If node already visited → loop exists
        if (us.find(head) != us.end())
            return true;

        us.insert(head);        // mark node as visited
        head = head->next;      // move forward
    }
    return false;               // reached NULL → no loop
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Hashing / Visited Set Pattern
*/
