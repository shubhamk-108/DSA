/*

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first ListNode is considered odd, and the second ListNode is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

All nodes at odd positions come first
All nodes at even positions come after
The relative order is preserved within the odd group and within the even group
You must not change node values, only change links
Position counting starts from 1 (1-indexed)
*/

#include <iostream>
#include <vector>
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return head;

        int pos = 1;
        vector<int> even;
        vector<int> odd;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            if (pos % 2 == 0)
                even.push_back(curr->val);
            else
                odd.push_back(curr->val);

            curr = curr->next;
            pos++;
        }

        curr = head;
        for (int x : odd)
        {
            curr->val = x;
            curr = curr->next;
        }

        for (int x : even)
        {
            curr->val = x;
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
One traversal to collect values
One traversal to overwrite values
Space Complexity: O(n)

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*

odd and even.
Traverse the list again and overwrite node values:
First with all values from the odd array
Then with all values from the even array
Return the modified list.
Key idea: Rearrange values instead of rearranging nodes.


*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*


class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return head; // empty list

        int pos = 1;                    // position counter (1-indexed)
        vector<int> even, odd;          // store values by position
        ListNode *curr = head;

        // First pass: separate values by position
        while (curr != nullptr)
        {
            if (pos % 2 == 0)
                even.push_back(curr->val);  // even position
            else
                odd.push_back(curr->val);   // odd position

            curr = curr->next;
            pos++;
        }

        curr = head;

        // Second pass: overwrite odd-position values
        for (int x : odd)
        {
            curr->val = x;
            curr = curr->next;
        }

        // Overwrite even-position values
        for (int x : even)
        {
            curr->val = x;
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

