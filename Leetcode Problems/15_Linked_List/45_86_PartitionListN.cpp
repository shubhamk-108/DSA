/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.


Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
*/

#include <iostream>
#include <vector>
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
    ListNode *partition(ListNode *head, int x)
    {
        vector<int> smaller;
        vector<int> larger;

        ListNode *curr = head;
        while (curr)
        {
            if (curr->val < x)
                smaller.push_back(curr->val);
            else
                larger.push_back(curr->val);
            curr = curr->next;
        }

        curr = head;

        int i = 0;
        while (i < smaller.size())
        {
            curr->val = smaller[i++];
            curr = curr->next;
        }
        i = 0;
        while (i < larger.size())
        {
            curr->val = larger[i++];
            curr = curr->next;
        }
        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Complexity
Time: O(n)
Space: O(n) (due to vectors)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


🎯 Goal

Partition list such that:
All values < x come first
All values >= x come after
Relative order preserved

🧠 Step 1: Store Values
Traverse list once:
Push values < x into smaller
Push values >= x into larger
This preserves original order automatically.

🧠 Step 2: Rewrite List
Traverse again from head:
First overwrite with smaller
Then overwrite with larger
No pointer changes.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        // Vectors to store partitioned values
        vector<int> smaller;  // values < x
        vector<int> larger;   // values >= x

        // First pass: collect values into two groups
        ListNode *curr = head;
        while (curr)
        {
            if (curr->val < x)
                smaller.push_back(curr->val);  // store smaller values
            else
                larger.push_back(curr->val);   // store larger or equal values

            curr = curr->next;  // move to next node
        }

        // Second pass: rewrite the linked list values
        curr = head;

        // Fill nodes with smaller values first
        int i = 0;
        while (i < smaller.size())
        {
            curr->val = smaller[i++];  // overwrite node value
            curr = curr->next;
        }

        // Then fill nodes with larger values
        i = 0;
        while (i < larger.size())
        {
            curr->val = larger[i++];  // overwrite node value
            curr = curr->next;
        }

        return head;  // return modified list
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
