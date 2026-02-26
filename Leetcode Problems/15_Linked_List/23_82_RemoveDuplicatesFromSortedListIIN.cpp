/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        unordered_map<int, int> freq;
        ListNode *curr = head;

        while (curr)
        {
            freq[curr->val]++;
            curr = curr->next;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        curr = dummy;

        while (curr->next)
        {
            if (freq[curr->next->val] > 1)
            {
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n) — two passes through the list.
Space: O(n) — for storing duplicate values in the hash set.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Iterate through the list once to record all values that appear more than once in a hash set.
Iterate again to delete all nodes whose values are in the hash set.
Return the updated list starting from the dummy node.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        unordered_map<int,int> freq;
        ListNode* curr = head;

        // 1. Count frequencies
        while (curr) {
            freq[curr->val]++;
            curr = curr->next;
        }

        // 2. Dummy node to handle head deletion
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        curr = dummy;

        // 3. Remove nodes that appear more than once
        while (curr->next) {
            if (freq[curr->next->val] > 1) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
