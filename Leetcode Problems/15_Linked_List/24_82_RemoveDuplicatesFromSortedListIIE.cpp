/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
*/

#include <iostream>
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
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *curr = dummyNode;

        while (curr->next != nullptr && curr->next->next != nullptr)
        {
            if (curr->next->val == curr->next->next->val)
            {
                int duplicateNodeVal = curr->next->val;
                while (curr->next != nullptr && curr->next->val == duplicateNodeVal)
                {
                    ListNode *temp = curr->next;
                    curr->next = curr->next->next;
                    delete (temp);
                }
            }
            else
                curr = curr->next;
        }
        head = dummyNode->next;
        delete (dummyNode);
        return (head);
    }
};

//___________________________________________________________________________________________________________________________________________
// Mistake
//___________________________________________________________________________________________________________________________________________

/*
initially i wrote ListNode* duplicateNode = curr->next;
but even though it is different node, it still pointing to the old node in the list. There is no seperate address this dupliacteNode is
contaning. If we would have created node using new keyword then its address would have different.
So when curr->next got deleted, the duplicate node was giving undefined behaviour causing runtime error.


*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n)
Each node is visited exactly once.
Inner loop deletes all nodes of a duplicate value in one pass.
Space Complexity: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use a dummy node before the head to simplify deletions at the start.
Maintain a pointer curr that points to the node before the sequence being checked.
Iterate through the list:
If curr->next and curr->next->next have the same value, it’s a duplicate.
Store the duplicate value in an integer and skip/delete all nodes with that value.
Otherwise, move curr forward.
Return dummy->next as the new head after all duplicates are removed.
Key idea: Always track the node before the potential duplicates and delete entire duplicate sequences in one pass.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr)
            return nullptr; // empty list

        ListNode* dummyNode = new ListNode(0); // dummy node before head
        dummyNode->next = head;
        ListNode* curr = dummyNode; // pointer before the current node being checked

        while (curr->next != nullptr && curr->next->next != nullptr)
        {
            // check if the next two nodes have the same value
            if (curr->next->val == curr->next->next->val)
            {
                int duplicateNodeVal = curr->next->val; // store the duplicate value
                // skip all nodes with this duplicate value
                while (curr->next != nullptr && curr->next->val == duplicateNodeVal)
                {
                    ListNode* temp = curr->next;       // node to delete
                    curr->next = curr->next->next;     // unlink node
                    delete temp;                        // free memory
                }
            }
            else
                curr = curr->next; // move forward if no duplicate
        }

        head = dummyNode->next; // new head after duplicates removed
        delete dummyNode;       // free dummy node
        return head;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
