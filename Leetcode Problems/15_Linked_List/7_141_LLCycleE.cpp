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
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};

//___________________________________________________________________________________________________________________________________________
// Imp mathematical property.
//___________________________________________________________________________________________________________________________________________
/*

1️⃣ Detecting a loop
If slow and fast meet at some point, then a cycle exists.

2️⃣ Where they meet
The point where slow and fast meet is NOT necessarily the node where the cycle starts.
They usually meet somewhere inside the loop, not at the entry.

3️⃣ Finding the starting node of the loop
Move slow to the start and keep fast where they met earlier.
Move both pointers one step at a time.
The node where they meet is the start of the cycle.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n)
📦 Space Complexity
O(1) (optimal)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
slow moves 1 step
fast moves 2 steps
If a loop exists:
fast will eventually catch up with slow
If no loop:
fast reaches NULL


By this the distance between slow and fast increases by one in each iteration. That is why we are doing fast = fast->next->next
and not by moving fast 3 or 4 or 5 or etc times ahead.
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


bool detectLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;          // move by 1
        fast = fast->next->next;   // move by 2

        if (slow == fast)
            return true;            // loop detected
    }
    return false;                   // no loop
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two-Pointer (Tortoise & Hare)

Cycle Detection Pattern


*/
