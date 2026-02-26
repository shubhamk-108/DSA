/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Input: head = [1,2,3,4]
Output: [1,4,2,3]
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
private:
    ListNode *reverseList(ListNode *head)
    {

        ListNode *curr = head;
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *nextNode = nullptr;
        ListNode *prevNode = nullptr;

        while (curr)
        {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }
        return prevNode;
    }

    ListNode *findMiddle(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;

        ListNode *middle = findMiddle(head);
        ListNode *secondHalf = middle->next;
        middle->next = nullptr;
        ListNode *headOfSecondHalf = reverseList(secondHalf);
        ListNode *first = head;
        ListNode *second = headOfSecondHalf;

        while (second)
        {
            ListNode *nextNode1 = first->next;
            ListNode *nextNode2 = second->next;

            first->next = second;
            second->next = nextNode1;

            first = nextNode1;
            second = nextNode2;
        }
        
    }
};

int main()
{

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Some imp things
//___________________________________________________________________________________________________________________________________________

/*
1.
In LL middle is considered 2nd node in case of even.
1-2-3-4-5-6-7-8 
here 5 is middle.
And there is no problem for odd case.

For odd case we will take middle in the first half.
1-2-3-4-5-6-7
Here 4 is middlle and first ha;f = 1-2-3-4 because:
while mergine two lists we do 
nextNode1 = first->next;
first->next = second;
second->next = nextNode1;

i.e.
1-2-3-4
7-6-5

1-7 will pair. and then we connect 7 with 2 in same iteration.
2-6 will paid and then we connect 6 with 3  in same iteration.
3-5 will paid and then 5 will connect to 4.
But here if 4 is in the second half then 5 would have accessed null and then 5->null->4 something this would have happen which would have 
caused runtime error or segmentation fault.

In even case the middle which is 2nd node is in the second half but here there is no problem as discussed above like odd 
becauase both length will have same.

2.
while mergine here,
while (second)
always take second list for checking null because 2nd list is short than first. If we have taken first then when we do 
first = first->next and second = second->next at that time we would not had second. it would have been null causing segmentation fault.

*/


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity:
O(N)
Finding middle → O(N)
Reversing second half → O(N/2)
Merging → O(N/2)
Total → O(N)
Space Complexity:
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We must reorder the list:
L0 → L1 → L2 → ... → Ln

Into:
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 ...

Constraints:
Must modify in-place.
No extra list creation.
O(1) extra space expected.

✅ Step 1: Find the Middle of the List
Use slow and fast pointer technique:
Slow moves 1 step.
Fast moves 2 steps.
When fast reaches end, slow is at middle.
This splits list into two halves.

✅ Step 2: Break and Reverse Second Half
Store middle->next as start of second half.
Break the list by setting middle->next = NULL.
Reverse the second half in-place.
Now we have:
First half:
L0 → L1 → L2
Reversed second half:
Ln → Ln-1

✅ Step 3: Merge Alternately
Merge both halves by alternating nodes:
Connect first node of first half
Then first node of reversed half
Repeat
Stop when second half is exhausted.
Since second half is always smaller or equal, it controls the merge loop.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
private:
    // Standard in-place linked list reversal
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;

        // Edge case: empty or single node
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *nextNode = nullptr;
        ListNode *prevNode = nullptr;

        while (curr)
        {
            nextNode = curr->next;   // store next
            curr->next = prevNode;   // reverse link
            prevNode = curr;         // move prev
            curr = nextNode;         // move curr
        }
        return prevNode; // new head after reversal
    }

    // Find middle using slow-fast pointer
    ListNode *findMiddle(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;

        // Stop so that slow is end of first half
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;

        // Step 1: Find middle
        ListNode *middle = findMiddle(head);

        // Step 2: Split and reverse second half
        ListNode *secondHalf = middle->next;
        middle->next = nullptr;  // break list
        ListNode *headOfSecondHalf = reverseList(secondHalf);

        // Step 3: Merge alternately
        ListNode *first = head;
        ListNode *second = headOfSecondHalf;

        while (second)
        {
            ListNode *nextNode1 = first->next;
            ListNode *nextNode2 = second->next;

            first->next = second;       // attach from second half
            second->next = nextNode1;   // reconnect first half

            first = nextNode1;
            second = nextNode2;
        }
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Slow & Fast Pointer (Find Middle)
In-place Linked List Reversal
Two Pointer Alternating Merge



*/
