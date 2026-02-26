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

        int size = 0;
        ListNode *curr = head;
        while (curr)
        {
            size++;
            curr = curr->next;
        }

        int middle = size / 2;

        curr = head;
        int i = 0;
        while (curr)
        {
            if (i == middle - 1)
            {
                ListNode *toBeDeleted = curr->next;
                curr->next = toBeDeleted->next;
                delete (toBeDeleted);
                break;
            }
            i++;
            curr = curr->next;
        }
        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n)
One pass to count nodes
One pass to delete the middle node
Space Complexity: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Handle edge cases first:
If the list is empty or has only one node, deleting the middle means returning nullptr.
First pass: Traverse the list to count the total number of nodes.
Compute the middle index:
Since indexing is 0-based, the middle node is at size / 2.
Second pass:
Traverse again to reach the node just before the middle (middle - 1).
Delete the middle node by adjusting pointers.
Key idea:
Use two passes—one to find the size, one to delete the middle node safely.



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

        // First pass: count total number of nodes
        int size = 0;
        ListNode *curr = head;
        while (curr)
        {
            size++;
            curr = curr->next;
        }

        // Middle index (0-based)
        int middle = size / 2;

        // Second pass: reach node before the middle
        curr = head;
        int i = 0;
        while (curr)
        {
            if (i == middle - 1)
            {
                // Delete the middle node
                ListNode *toBeDeleted = curr->next;
                curr->next = toBeDeleted->next;
                delete toBeDeleted;
                break;
            }
            i++;
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




*/
