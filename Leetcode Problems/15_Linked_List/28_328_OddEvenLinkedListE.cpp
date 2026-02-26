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

        ListNode *evenStart = NULL;
        ListNode *evenEnd = NULL;
        ListNode *oddStart = NULL;
        ListNode *oddEnd = NULL;
        ListNode *curr = head;
        int pos = 1;
        while (curr != nullptr)
        {
            ListNode *nextNode = curr->next;
            curr->next = nullptr;

            if (pos % 2 == 0)
            {
                if (evenStart == nullptr)
                {
                    evenStart = curr;
                    evenEnd = curr;
                }
                else
                {
                    evenEnd->next = curr;
                    evenEnd = curr;
                }
            }
            else
            {
                if (oddStart == NULL)
                {
                    oddStart = curr;
                    oddEnd = curr;
                }
                else
                {
                    oddEnd->next = curr;
                    oddEnd = curr;
                }
            }
            curr = nextNode;
            pos++;
        }

        if (oddEnd != nullptr)
            oddEnd->next = evenStart;
        return oddStart;
    }
}

;

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time & Space Complexity
Time: O(n)
Space: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

I traverse the linked list once and separate nodes based on their positions (1-indexed) into two lists: odd-position list and even-position list.
While traversing, I relink nodes directly instead of creating new nodes or changing values, so the relative order is preserved.
After traversal, I attach the even list to the end of the odd list.
This rearranges the list in-place as required.


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
            return head;

        ListNode *oddStart = nullptr, *oddEnd = nullptr;
        ListNode *evenStart = nullptr, *evenEnd = nullptr;

        ListNode *curr = head;
        int pos = 1;  // ✅ position must be outside the loop

        while (curr != nullptr)
        {
            ListNode *nextNode = curr->next;
            curr->next = nullptr;

            if (pos % 2 == 0)   // even position
            {
                if (evenStart == nullptr)
                {
                    evenStart = curr;
                    evenEnd = curr;
                }
                else
                {
                    evenEnd->next = curr;
                    evenEnd = curr;
                }
            }
            else                // odd position
            {
                if (oddStart == nullptr)
                {
                    oddStart = curr;
                    oddEnd = curr;
                }
                else
                {
                    oddEnd->next = curr;
                    oddEnd = curr;
                }
            }

            curr = nextNode;
            pos++;  // ✅ increment position
        }

        // ✅ odd list should come first
        if (oddEnd != nullptr)
            oddEnd->next = evenStart;

        return oddStart;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
