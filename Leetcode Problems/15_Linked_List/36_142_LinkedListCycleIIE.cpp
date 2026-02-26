/*

Given the head of a linked list, return the ListNode where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some ListNode in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the ListNode that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to ListNode index 1
Explanation: There is a cycle in the linked list, where tail connects to the second ListNode.

*/
#include <iostream>
#include <stack>
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (fast == NULL || fast->next == NULL)
            return nullptr;

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};





//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Complexity | Value |
| ---------- | ----- |
| Time       | O(N)  |
| Space      | O(1)  |
Each pointer traverses at most ~2N steps.
No extra memory used.
*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*

Phase 1: Detect if a cycle exists
Use two pointers:
slow moves 1 step
fast moves 2 steps
If there is a cycle, they will eventually meet.
If fast reaches NULL, there is no cycle.

🔹 Phase 2: Find the start of the cycle
Once they meet:
Move slow back to head
Keep fast at meeting point
Move both 1 step at a time
The node where they meet again is the cycle start
This works due to mathematical distance reasoning of Floyd’s algorithm.


*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // Initialize two pointers
        ListNode *slow = head, *fast = head;

        // Phase 1: Detect cycle using Floyd’s algorithm
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps

            if (slow == fast)           // cycle detected
                break;
        }

        // If fast reached NULL, there is no cycle
        if (fast == NULL || fast->next == NULL)
            return nullptr;

        // Phase 2: Find the starting node of the cycle
        slow = head;                   // reset slow to head

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Both pointers now point to cycle start
        return slow;
    }
};
     


*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*

1️⃣ Fast & Slow Pointer (Tortoise and Hare)
2️⃣ Floyd’s Cycle Detection Algorithm


*/

