/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Input: head = [1,2,2,1]
Output: true

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
    ListNode *reverseList(ListNode *head)
    {

        ListNode *curr = head;
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *nextNode = NULL;
        ListNode *prevNode = NULL;

        while (curr != NULL)
        {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }
        return prevNode;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *reversed = reverseList(slow->next);
        ListNode *curr = head;
        while (reversed != NULL)
        {
            if (curr->val != reversed->val)
                return false;
            reversed = reversed->next;
            curr = curr->next;
        }
        return true;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n)
Finding middle → O(n)
Reversing half → O(n)
Comparing → O(n)
Total is still linear.
🧠 Space Complexity
O(1) (constant extra space)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use slow and fast pointers to find the middle of the linked list
Reverse the second half of the list
Compare the first half and reversed second half
If all corresponding nodes match → palindrome
This avoids using a stack or array.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

bool isPalindrome(Node *head)
{
    // Empty list or single node is always a palindrome
    if (head == NULL)
        return true;

    Node *slow = head;
    Node *fast = head;

    // Step 1: Find middle of the list
    // slow moves 1 step, fast moves 2 steps
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half of the list
    Node *reversed = reverseList(slow->next);

    // Step 3: Compare first half and reversed second half
    Node *curr = head;
    while (reversed != NULL)
    {
        if (curr->data != reversed->data)
            return false;
        reversed = reversed->next;
        curr = curr->next;
    }

    return true;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Slow & Fast Pointer Pattern
Used to find middle efficiently
✅ Reverse-in-place Pattern
Reverse second half to simulate backward traversal
Combined Pattern Name:
Two-pointer + In-place modification




*/
