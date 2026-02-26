/*
Given the head of a linked list, return the list after sorting it in ascending order.
Input: head = [4,2,1,3]
Output: [1,2,3,4]
*/

// Merge Sort 

#include <iostream>
#include <vector>
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
    ListNode *mergeList(ListNode *left, ListNode *right)
    {
        ListNode dummyNode(0);
        ListNode *tail = &dummyNode;

        while (left && right)
        {
            if (left->val < right->val)
            {
                tail->next = left;
                tail = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                tail = right;
                right = right->next;
            }
        }

        if (left)
        {
            tail->next = left;
            tail = left;
            left = left->next;
        }

        if (right)
        {
            tail->next = right;
            tail = right;
            right = right->next;
        }

        return dummyNode.next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        return mergeList(left, right);
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time = O(n log n)
log n levels of recursion
each level merges total n nodes

Space:
This is important.
You are NOT creating new nodes.
You are rearranging pointers.
Extra space:
Only recursion stack
✅ Space = O(log n)
Because recursion depth = log n.
It is NOT O(1) due to recursion stack.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


1️⃣ Identify the pattern
This problem asks to sort a linked list in O(n log n) time and constant extra space.
For linked list:
Quick sort is not ideal (no random access).
Heap sort is complicated.
Merge Sort is optimal.

2️⃣ Divide Step (Find Middle)
Use slow & fast pointer:
slow moves 1 step
fast moves 2 steps
prev tracks node before slow
When loop ends:
slow = start of right half
head = start of left half
prev->next = NULL breaks the list
Now list is divided into two halves.

3️⃣ Conquer Step (Recursive Sort)
Recursively sort
Left half
Right half
Base case:
If list has 0 or 1 node → already sorted

4️⃣ Merge Step
Merge two sorted linked lists:
Use dummy node
Compare values
Attach smaller node
Move pointer forward
Return dummy.next

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
private:
    // Function to merge two sorted linked lists
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1)
            tail->next = l1;
        if (l2)
            tail->next = l2;

        return dummy.next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // Step 1: Split list into two halves
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr; // break the list into two halves

        // Step 2: Recursively sort both halves
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);

        // Step 3: Merge sorted halves
        return merge(left, right);
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern: Divide and Conquer
More specifically:
Merge Sort Pattern
Slow-Fast Pointer Pattern
Dummy Node Pattern (for merging)


*/
