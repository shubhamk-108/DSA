/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0

*/

#include <iostream>
#include <cmath>
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
    int getDecimalValue(ListNode *head)
    {
        ListNode *curr = head;
        int count = 0;
        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        count--;
        long long number = 0;

        curr = head;
        while (curr != nullptr)
        {
            if (curr->val == 0)
                count--;

            else
            {
                number += pow(2, count);
                count--;
            }
            curr = curr->next;
        }
        return number;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Your solution
Time: O(n)
Space: O(1)
Extra overhead due to pow
Optimal solution
Time: O(n)
Space: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Traverse the linked list once to count the number of nodes.
Since the list represents a binary number, the leftmost bit has the highest power of 2.
Traverse the list again:
If the current node’s value is 1, add 2^(position) to the answer.
Decrease the position after every node.
Return the computed decimal value.
This approach uses two passes over the linked list.

Why this is brute. Because pow returns double and then we have double to int conversion here. So pow is slow.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        // Pointer to traverse the list
        ListNode *curr = head;

        // Count total number of nodes
        int count = 0;
        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        // Highest power of 2 will be (count - 1)
        count--;

        long long number = 0;

        // Start traversal again from head
        curr = head;
        while (curr != nullptr)
        {
            // If current bit is 1, add 2^count to number
            if (curr->val == 1)
            {
                number += pow(2, count);
            }

            // Move to next bit (lower power)
            count--;
            curr = curr->next;
        }

        // Return final decimal value
        return number;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
