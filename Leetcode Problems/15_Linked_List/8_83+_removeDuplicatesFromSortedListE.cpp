/*

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;
        if (head == NULL)
            return head;

        while (curr != NULL && curr->next != nullptr)
        {
            if (curr->val == curr->next->val)
            {
                ListNode *duplicate = curr->next;
                curr->next = curr->next->next;
                delete (duplicate);
            }
            else
                curr = curr->next;
        }
        return head;
    }
};
// ______________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n)
Each node is visited at most once.

📦 Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Assumption: The linked list is sorted
Start from the head of the list
Compare the current node with the next node
If both values are equal:
Remove the next node (duplicate)
Do not move the current pointer
If values are different:
Move to the next node
Continue until the end of the list

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


Node* removeDuplicates(Node* head)
{
    // If list is empty, nothing to remove
    if (head == NULL)
        return head;

    Node* curr = head;

    // Traverse the list
    while (curr != NULL && curr->next != NULL)
    {
        // If duplicate is found
        if (curr->data == curr->next->data)
        {
            Node* duplicate = curr->next;   // store duplicate node
            curr->next = curr->next->next;  // remove duplicate from list
            delete duplicate;               // free memory
        }
        else
        {
            // Move forward only if no duplicate
            curr = curr->next;
        }
    }
    return head;
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
