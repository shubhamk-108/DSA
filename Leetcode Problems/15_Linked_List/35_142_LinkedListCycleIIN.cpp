/*

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

*/
#include <iostream>
#include <unordered_set>
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
        unordered_set<ListNode *> sett;

        while (head)
        {
            if (sett.count(head))
                return head;

            sett.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};





//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Complexity | Value |
| ---------- | ----- |
| Time       | O(N)  |
| Space      | O(N)  |

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*

💡 Idea: Use a Hash Set to track visited nodes
Traverse the linked list.
For each node:
If it already exists in the set → we found the cycle start.
Otherwise, insert it into the set.
If we reach nullptr, there is no cycle.
Why this works:
In a cycle, nodes repeat.
The first node that repeats is exactly the cycle entry point.
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
        // Hash set to store visited node addresses
        unordered_set<ListNode *> sett;

        // Traverse the linked list
        while (head)
        {
            // If node already visited → cycle start found
            if (sett.count(head))
                return head;

            // Otherwise store the node
            sett.insert(head);

            // Move to next node
            head = head->next;
        }

        // If we reach NULL → no cycle
        return nullptr;
    }
};



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*

Hashing / Visited Set Pattern


*/

