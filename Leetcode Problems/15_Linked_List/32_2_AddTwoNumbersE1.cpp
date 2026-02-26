/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
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
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        ListNode *newHead = nullptr;
        ListNode *prev = nullptr;
        int carry = 0;
        while (curr1 || curr2 || carry)
        {
            int d1 = curr1 == NULL ? 0 : curr1->val;
            int d2 = curr2 == NULL ? 0 : curr2->val;
            int s = d1 + d2 + carry;
            carry = s / 10;
            int unitDigit = s % 10;
            ListNode *newNode = new ListNode(unitDigit);

            if (newHead == nullptr)
            {
                newHead = newNode;
                prev = newNode;
            }
            else
            {
                prev->next = newNode;
                prev = newNode;
            }
            if (curr1)
                curr1 = curr1->next;
            if (curr2)
                curr2 = curr2->next;
        }
        return newHead;
    }
};

//___________________________________________________________________________________________________________________________________________
// digits are reversed so we will do addition from the left side and not the right side. And we will propogate carry to the right
//same as we propogate it in left side in normal addition.
//___________________________________________________________________________________________________________________________________________




//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*Time Complexity
O(max(n, m))
Each node of both lists is visited exactly once.
📦 Space Complexity
O(max(n, m))


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


The digits are stored in reverse order, so we can add them node by node, just like manual addition.
Steps:
Use two pointers (curr1, curr2) to traverse both linked lists.
Maintain a carry from the previous addition.
At each step:
Take digit from l1 if available, else 0
Take digit from l2 if available, else 0
Add digits + carry
Store (sum % 10) as a new node in the result list.
Update carry = sum / 10
Continue until both lists are exhausted and carry is zer

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Pointers to traverse the two input linked lists
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;

        // Head of the result linked list
        ListNode *newHead = nullptr;

        // Pointer to keep track of the last node in result list
        ListNode *prev = nullptr;

        // Carry from digit addition
        int carry = 0;

        // Continue while there is any digit left or carry remains
        while (curr1 || curr2 || carry)
        {
            // Get current digit from l1 if exists, else 0
            int d1 = (curr1 == NULL) ? 0 : curr1->val;

            // Get current digit from l2 if exists, else 0
            int d2 = (curr2 == NULL) ? 0 : curr2->val;

            // Sum of digits and carry
            int s = d1 + d2 + carry;

            // Update carry for next iteration
            carry = s / 10;

            // Unit digit to be stored in result list
            int unitDigit = s % 10;

            // Create a new node for the result digit
            ListNode *newNode = new ListNode(unitDigit);

            // If this is the first node, initialize head
            if (newHead == nullptr)
            {
                newHead = newNode;
                prev = newNode;
            }
            else
            {
                // Append node to the result list
                prev->next = newNode;
                prev = newNode;
            }

            // Move to next nodes if they exist
            if (curr1)
                curr1 = curr1->next;
            if (curr2)
                curr2 = curr2->next;
        }

        // Return the head of the result list
        return newHead;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Digit-by-Digit Simulation with Carry
Also known as:
Linked List + Math Simulation
Elementary Addition Pattern

*/
