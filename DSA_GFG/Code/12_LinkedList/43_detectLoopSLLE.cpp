#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

bool detectLoop(Node *head)
{

    Node *slow = head;
    Node *fast= head;

    while(fast!=NULL && fast->next!= NULL)
    {
        slow = slow->next;
        fast= fast->next->next;

        if(slow==fast)
            return true;
    }
    return false;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    head->next->next->next = head->next;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

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

Time Complexity
O(n)
📦 Space Complexity
O(1) (optimal)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
slow moves 1 step
fast moves 2 steps
If a loop exists:
fast will eventually catch up with slow
If no loop:
fast reaches NULL


By this the distance between slow and fast increases by one in each iteration. That is why we are doing fast = fast->next->next 
and not by moving fast 3 or 4 or 5 or etc times ahead.
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


bool detectLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;          // move by 1
        fast = fast->next->next;   // move by 2

        if (slow == fast)
            return true;            // loop detected
    }
    return false;                   // no loop
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two-Pointer (Tortoise & Hare)

Cycle Detection Pattern


*/
