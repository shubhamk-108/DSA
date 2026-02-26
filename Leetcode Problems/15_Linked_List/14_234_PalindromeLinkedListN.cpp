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
public:
    bool isPalindrome(ListNode *head)
    {
        stack<char> st;
        for (ListNode *curr = head; curr != NULL; curr = curr->next)
            st.push(curr->val);
        for (ListNode *curr = head; curr != NULL; curr = curr->next)
        {
            if (st.top() != curr->val)
                return false;
            st.pop();
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
One traversal to push
One traversal to compare

🧠 Space Complexity
O(n)
Stack stores all node values

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Traverse the linked list from head to end
Push each node’s data onto a stack
(stack reverses the order)
Traverse the linked list again from head
For each node:
Compare its value with the stack’s top
If mismatch → not a palindrome
If all values match → palindrome
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


bool isPalindrome(Node *head)
{
    stack<int> st;
    Node *curr = head;

    // Push all elements into stack
    while (curr != nullptr)
    {
        st.push(curr->data);
        curr = curr->next;
    }

    // Compare stack elements with list from start
    curr = head;
    while (curr != nullptr)
    {
        if (st.top() != curr->data)
            return false;
        st.pop();
        curr = curr->next;
    }

    return true;
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
