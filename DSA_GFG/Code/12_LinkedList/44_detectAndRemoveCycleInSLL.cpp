#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void detectRemoveLoop(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow != fast)
        return;

    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;

}

int main()
{
    Node *head = new Node(15);
    head->next = new Node(10);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20);
    head->next->next->next->next = head->next;
    detectRemoveLoop(head);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Imp mathematical property.
//___________________________________________________________________________________________________________________________________________
/*
1️⃣ Detecting a loop
If slow and fast meet at some point, then a cycle exists.

2️⃣ Where they meet
The point where slow and fast meet is NOT necessarily the node where the cycle starts.
They usually meet somewhere inside the loop, not at the entry.

3️⃣ Finding the starting node of the loop
Move slow to the start and keep fast where they met earlier.
Move both pointers one step at a time.
The node where they meet is the start of the cycle.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

⏱ Time Complexity
O(n)
Detection + removal both take linear time.

📦 Space Complexity
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The solution works in three phases:

Phase 1: Detect the loop
Use Floyd’s Cycle Detection (slow & fast pointers).
If slow and fast meet, a loop exists.
If fast reaches NULL, no loop exists → return.

Phase 2: Find the node just before loop start
Reset slow to head.
Keep fast at the meeting point.
Move both pointers one step at a time.
Stop when slow->next == fast->next.
At this point:
fast->next is the starting node of the loop.

Phase 3: Remove the loop
Set fast->next = NULL.
This breaks the cycle safely.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

void detectRemoveLoop(Node *head)
{
    Node *slow = head, *fast = head;

    // Phase 1: Detect loop using Floyd’s algorithm
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;          // move by 1
        fast = fast->next->next;   // move by 2

        if (slow == fast)           // loop detected
            break;
    }

    // If no loop was found
    if (slow != fast)
        return;

    // Phase 2: Find node just before loop start
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Phase 3: Remove the loop
    fast->next = NULL;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Floyd’s Cycle Detection (Tortoise & Hare)

*/
