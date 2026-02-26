/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//brute

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            swap(curr->val, curr->next->val);
            curr = curr->next->next;
        }
        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity:

O(n)

4️⃣ Space Complexity
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Problem:
Pairwise swap elements of a singly linked list.

Example:

Input :  10 → 20 → 30 → 40 → 50
Output:  20 → 10 → 40 → 30 → 50

Idea:
Traverse the linked list two nodes at a time.
Swap the data of the current node with the next node.
Move the pointer ahead by two nodes.
Stop when fewer than two nodes remain.
This avoids pointer manipulation and keeps the logic simple.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


void pairwiseSwap(Node *head)
{
    // Start from the head of the linked list
    Node *curr = head;

    // Traverse while at least two nodes are available
    while (curr != NULL && curr->next != NULL)
    {
        // Swap data of current node and next node
        swap(curr->data, curr->next->data);

        // Move pointer two nodes ahead
        curr = curr->next->next;
    }
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/