/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *curr = head;
        int len = 0;
        ListNode *frontNode = nullptr;
        while (curr)
        {
            len++;
            if (len == k)
                frontNode = curr;

            curr = curr->next;
        }

        int rearNodeAt = len - k + 1;
        curr = head;
        for (int i = 1; i < rearNodeAt; i++)
        {
            curr = curr->next;
        }
        ListNode *rearNode = curr;

        int temp = frontNode->val;
        frontNode->val = rearNode->val;
        rearNode->val = temp;

        return head;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
First traversal → O(n)
Second traversal → O(n)
Total:
O(2n) ≈ O(n)
🗂 Space Complexity
O(1) (constant extra space)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Swap:
k-th node from beginning
k-th node from end
🧠 Step 1: Calculate Length
Traverse entire list and:
Count total number of nodes (len)
At the same time, when counter equals k, store that node as frontNode
So after first pass:
You know total length
You already have k-th node from beginning


🧠 Step 2: Compute k-th from End Position
We know:
k-th from end = (len - k + 1)-th from start
Store:
rearNodeAt = len - k + 1

🧠 Step 3: Traverse Again
Traverse from head until reaching rearNodeAt.
Store that node as rearNode.

🧠 Step 4: Swap Values
Swap:
frontNode->val
rearNode->val
No pointer modifications.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *curr = head;
        int len = 0;

        // Will store k-th node from start
        ListNode *frontNode = nullptr;

        // First traversal to calculate length
        // and capture k-th node from beginning
        while (curr)
        {
            len++;

            if (len == k)
                frontNode = curr;

            curr = curr->next;
        }

        // Compute position of k-th node from end
        int rearNodeAt = len - k + 1;

        curr = head;

        // Traverse again to find k-th node from end
        for (int i = 1; i < rearNodeAt; i++)
        {
            curr = curr->next;
        }

        ListNode *rearNode = curr;

        // Swap their values
        int temp = frontNode->val;
        frontNode->val = rearNode->val;
        rearNode->val = temp;

        return head;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
