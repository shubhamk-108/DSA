/*

Given the heads of two singly linked-lists headA and headB, return the ListNode at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at ListNode c1:

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the ListNode where the intersection occurs. This is 0 if there is no intersected ListNode.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected ListNode.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected ListNode.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected ListNode, then your solution will be accepted.

 

Example 1:

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected ListNode's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected ListNode in A; There are 3 nodes before the intersected ListNode in B.
- Note that the intersected ListNode's value is not 1 because the nodes with value 1 in A and B (2nd ListNode in A and 3rd ListNode in B) are different ListNode references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd ListNode in A and 4th ListNode in B) point to the same location in memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curr1 = headA;
    ListNode *curr2 = headB;

    int count1 = 0;
    while (curr1 != nullptr)
    {
        count1++;
        curr1 = curr1->next;
    }
    int count2 = 0;
    while (curr2 != nullptr)
    {
        count2++;
        curr2 = curr2->next;
    }

    int d = abs(count1 - count2);

    curr1 = headA;
    curr2 = headB;

    if (count1 > count2)
    {
        int i = 0;
        while (curr1 != NULL && i < d)
        {
            curr1 = curr1->next;
            i++;
        }
    }
    else
    {
        int i = 0;
        while (curr2 != NULL && i < d)
        {
            curr2 = curr2->next;
            i++;
        }
    }

    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1 == curr2)
            return curr1;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return nullptr;
    }
};



//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Counting lengths: O(n + m)
Alignment + traversal: O(n + m)
✅ Overall:
O(n + m)

💾 Space Complexity
Only pointers and counters used

✅ Extra space:
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Traverse both lists to find their lengths.
Compute the absolute length difference d.
Move the pointer of the longer list forward by d nodes.
Traverse both lists simultaneously.
The first node where both pointers are equal is the intersection point.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


int commonIntersectionPoint(Node *head1, Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;

    // Count length of first linked list
    int count1 = 0;
    while (curr1 != nullptr)
    {
        count1++;
        curr1 = curr1->next;
    }

    // Count length of second linked list
    int count2 = 0;
    while (curr2 != nullptr)
    {
        count2++;
        curr2 = curr2->next;
    }

    // Find difference in lengths
    int d = abs(count1 - count2);

    // Reset pointers to list heads
    curr1 = head1;
    curr2 = head2;

    // Advance pointer of longer list by d nodes
    if (count1 > count2)
    {
        int i = 0;
        while (curr1 != nullptr && i < d)
        {
            curr1 = curr1->next;
            i++;
        }
    }
    else
    {
        int i = 0;
        while (curr2 != nullptr && i < d)
        {
            curr2 = curr2->next;
            i++;
        }
    }

    // Traverse both lists together to find intersection
    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1 == curr2)
            return curr1->data;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // No intersection found
    return -1;
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Two-Pointer Alignment Pattern
Key idea:
Equalize traversal distance before moving pointers together



*/
