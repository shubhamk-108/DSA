/*
Given the head of a linked list, remove the nth ListNode from the end of the list and return its head.
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
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
private:
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
            return head;
        ListNode *curr = head;
        int size = 0;
        while (curr)
        {
            size++;
            curr = curr->next;
        }
        if (n > size)
            return head;

        if (n == size)
        {
            ListNode *toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
            return head;
        }
        curr=head;
        for (int i = 1; i < size - n; i++)
        {
            curr = curr->next;
        }
        ListNode *toBeDeleted = curr->next;
        curr->next = toBeDeleted->next;
        delete toBeDeleted;
        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
First traversal to calculate size → O(N)
Second traversal to reach target node → O(N)
Total: O(N)

🧠 Space Complexity
Only pointers used
O(1) (constant extra space)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

If we know the length of the linked list, we can convert
“Nth node from the end” → “(size − n)th node from the beginning”.
Steps:
Traverse the list once to calculate its length (size)
If n > size, nothing to delete → return head
If n == size, the node to delete is the head
Otherwise:
Move to the (size − n − 1)th node
Delete its next node
Return updated head
This is a clean and standard brute-force approach.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Edge case: empty list
        if (head == nullptr)
            return head;

        // First pass: calculate size of the list
        ListNode *curr = head;
        int size = 0;
        while (curr)
        {
            size++;
            curr = curr->next;
        }

        // If n is larger than list size, nothing to remove
        if (n > size)
            return head;

        // Special case: removing the head node
        if (n == size)
        {
            ListNode *toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
            return head;
        }

        // Move curr to the node just before the one to be deleted
        curr = head;
        for (int i = 1; i < size - n; i++)
        {
            curr = curr->next;
        }

        // Delete the target node
        ListNode *toBeDeleted = curr->next;
        curr->next = toBeDeleted->next;
        delete toBeDeleted;

        return head;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
