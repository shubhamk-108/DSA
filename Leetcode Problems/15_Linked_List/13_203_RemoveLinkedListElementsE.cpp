/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode *curr = &dummyNode
        ;
        while (curr->next != nullptr)
        {
            if (curr->next->val == val)
            {
                ListNode *temp = curr->next;
                curr->next = temp->next;
                delete (temp);
            }
            else
                curr = curr->next;
        }
        head = dummyNode.next;
        return head;

    }
};

//___________________________________________________________________________________________________________________________________________
// Some imp things about passing variable address with & and without &
//___________________________________________________________________________________________________________________________________________

/*

1️⃣ Creating a node as an object (stack allocation)
Node head(10);
✔ This creates an object of type Node
✔ Memory is allocated on the stack
✔ head is NOT a pointer
So
head        // object
&head       // address of the object


👉 If you want to pass its address somewhere, you must use &head.
Example:
Node* ptr = &head;
✔ Your understanding here is correct.

Also when you create node using object that time you have to access it using dot operator and not -> operator.
Ex:
ListNode dummyNode(0);
dummyNode.next = head;

2️⃣ Creating a node using new (heap allocation)

Node* head = new Node(10);
✔ Memory allocated on the heap
✔ head itself is a pointer
✔ It already stores an address

So:
head       // address of Node
*head      // actual Node object
👉 When passing the node’s address, you just pass head, not &head.

Example:
foo(head);     // correct

Remember the new keyword always returns a pointer so to hold that address we have to use *variableName on the left hand side.

*/

//___________________________________________________________________________________________________________________________________________
//why we  can not delete dummyNode
//___________________________________________________________________________________________________________________________________________
/*
delete(dummyNode); // this is wrong.
❌ dummyNode is not created using new
❌ It is a stack object, so deleting it causes undefined behavior

👉 Never delete stack objects. Stack objects are auto-destroyed, never delete them.
You can directly return dummyNode.next.

Objects are created in stack memory and when we use new keyword at that time heap memory is being used.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n)

💾 Space Complexity
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Create a dummy node before the head to handle edge cases uniformly.
Use a pointer curr starting from dummy.
While curr->next exists:
If next node’s value equals val, delete it.
Otherwise, move curr forward.
Return dummy.next as the updated head.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // Dummy node to handle deletion of head uniformly
        ListNode dummyNode(0);
        dummyNode.next = head;

        // Pointer to traverse the list
        ListNode *curr = &dummyNode;

        while (curr->next != nullptr)
        {
            if (curr->next->val == val)
            {
                // Node to be deleted
                ListNode *temp = curr->next;

                // Bypass the node
                curr->next = temp->next;

                // Free memory
                delete temp;
            }
            else
            {
                // Move forward only if no deletion
                curr = curr->next;
            }
        }

        // New head after deletions
        return dummyNode.next;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
