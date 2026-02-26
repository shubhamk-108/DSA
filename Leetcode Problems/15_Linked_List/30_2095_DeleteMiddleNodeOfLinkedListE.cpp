/*
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]

Input: head = [1,2,3,4]
Output: [1,2,4]
*/

#include <iostream>
#include <unordered_map>

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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(n)
Single traversal of the list
Space Complexity: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
If the list is empty or has only one node, deleting the middle means returning nullptr.
Use two pointers, slow and fast, starting at the head:
slow moves one step at a time
fast moves two steps at a time
Maintain a prev pointer to track the node just before slow.
When fast reaches the end, slow will be at the middle node.
Delete the middle node by linking prev->next to slow->next.
Return the head of the updated list.



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        // Edge case: empty list or single node
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head;   // moves one step
        ListNode *fast = head;   // moves two steps
        ListNode *prev = nullptr; // tracks node before slow

        // Find the middle node
        while (fast && fast->next)
        {
            prev = slow;                // save previous node
            slow = slow->next;          // move slow by 1
            fast = fast->next->next;    // move fast by 2
        }

        // Delete the middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Slow & Fast Pointer (Tortoise–Hare Pattern)


*/
