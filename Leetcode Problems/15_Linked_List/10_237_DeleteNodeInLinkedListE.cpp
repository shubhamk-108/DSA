/*
There is a singly-linked list head and we want to delete a ListNode ListNode in it.

You are given the ListNode to be deleted ListNode. You will not be given access to the first ListNode of head.

All the values of the linked list are unique, and it is guaranteed that the given ListNode ListNode is not the last ListNode in the linked list.

Delete the given ListNode. Note that by deleting the ListNode, we do not mean removing it from memory. We mean:

The value of the given ListNode should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before ListNode should be in the same order.
All the values after ListNode should be in the same order.
Custom testing:

For the input, you should provide the entire linked list head and the ListNode to be given ListNode. ListNode should not be the last ListNode of the list and should be an actual ListNode in the list.
We will build the linked list and pass the ListNode to your function.
The output will be the entire list after calling your function.

Input: head = [4,5,1,9], ListNode = 5
Output: [4,1,9]
Explanation: You are given the second ListNode with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.


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
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete (temp);
    }
};

//___________________________________________________________________________________________________________________________________________
// Why cant we delete last node
//___________________________________________________________________________________________________________________________________________
/*
Because we are swapping values and not nodes. When we try to swap last node then the next of it is nullptr. So value and nullptr can not
be swapped. values and values can be swapped.

*/


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(1)
No traversal required.

📦 Space Complexity
O(1)
No extra memory used.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Since we do not have access to the head, we cannot traverse the list or update the previous node.
So instead of deleting the given node directly, we:
Copy the data of the next node into the current node.
Bypass the next node by changing pointers.
Delete the next node.

⚠️ Important Constraint (must know)
🚨 This method works only if the given node is NOT the last node.
Why?
The last node has no next node to copy data from.
If ptr->next == NULL, this approach is impossible.

Before deletion:

A → B → C → D
      ↑
     ptr


After copying data:

A → C → C → D
      ↑
     ptr


After bypass & delete:

A → C → D
      ↑
     ptr

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

void deleteNode(Node *ptr)
{
    // Store the next node
    Node *temp = ptr->next;

    // Copy data from next node into current node
    ptr->data = temp->data;

    // Bypass the next node
    ptr->next = temp->next;

    // Delete the duplicate node
    delete(temp);
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Data Replacement Technique
Pointer Manipulation

*/
