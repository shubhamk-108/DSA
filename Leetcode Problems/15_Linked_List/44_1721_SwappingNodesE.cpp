/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
*/

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
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;

        ListNode *curr = head;
        ListNode *slow = head;
        ListNode *fast = head;

        for (int i = 1; i < k; i++)
        {
            fast = fast->next;
        }

        ListNode *firstNode = fast;

        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *secondNode = slow;

        int temp = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = temp;

        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
First loop → O(k)
Second loop → O(n − k)
Overall:
O(n)

Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

🎯 Goal
Swap the value of:
k-th node from beginning
k-th node from end

🧠 Key Idea: Two Pointer Offset Technique
Step 1: Reach k-th node from beginning
Move fast pointer (k−1) steps forward.
Now:
fast → k-th node
Store it as firstNode

Step 2: Find k-th node from end (without length)
Now:
Keep slow at head
Move both fast and slow together
Stop when fast reaches last node
Because fast started k-1 steps ahead:
When fast reaches end →
slow will be at k-th from end.
Store it as secondNode.

Step 3: Swap values
Swap firstNode->val and secondNode->val.
We are not swapping nodes, only values.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        // Edge case: empty list
        if (head == nullptr)
            return head;

        // Initialize two pointers
        ListNode *slow = head;
        ListNode *fast = head;

        // Move fast pointer to k-th node
        for (int i = 1; i < k; i++)
        {
            fast = fast->next;
        }

        // Store k-th node from beginning
        ListNode *firstNode = fast;

        // Move both pointers until fast reaches last node
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Now slow is k-th node from end
        ListNode *secondNode = slow;

        // Swap their values
        int temp = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = temp;

        return head;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
