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

        // ListNode *dummyNode =new ListNode(0);
        // dummyNode->next = head;
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode *slow = &dummyNode;
        ListNode *fast = &dummyNode;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *toBeDeleted = slow->next;
        slow->next = toBeDeleted->next;
        delete (toBeDeleted);
        return dummyNode.next;
    }
};

//___________________________________________________________________________________________________________________________________________
// Why created dummy node
//___________________________________________________________________________________________________________________________________________

/*
A dummy node is NOT mandatory, but it is created to safely and cleanly handle the head-deletion case and avoid fragile pointer logic.
Dummy node = a guaranteed “previous node” for head
In linked lists, deletion always needs access to the previous node.
Problem:
When the node to delete is the head, there is no previous node.
Solution:
Create a fake node before head:
dummy → head → ...

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(N) (single pass)
Space: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Create a dummy node before head
Move fast pointer n steps ahead
Move both fast and slow until fast == nullptr
Delete slow->next
Why dummy?
It automatically handles head deletion
Prevents edge-case bugs


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
        ListNode dummy(0);
        dummy.next = head;

        ListNode *fast = &dummy;
        ListNode *slow = &dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // Move both until fast reaches last node
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete nth node from end
        ListNode *toBeDeleted = slow->next;
        slow->next = toBeDeleted->next;
        delete toBeDeleted;

        return dummy.next;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

✅ Two Pointers (Fast & Slow / Sliding Window on Linked List)


*/
