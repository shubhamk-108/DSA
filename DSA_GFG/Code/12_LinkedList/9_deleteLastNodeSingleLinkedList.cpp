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

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *delTail(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while (curr->next->next != NULL)
        curr = curr->next;
    delete (curr->next);
    curr->next = NULL;
    return head;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printlist(head);
    head = delTail(head);
    printlist(head);

    return 0;
}




//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n)
You traverse the list once to reach the second-last node.

🧠 Space Complexity
O(1)

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*

To delete the tail (last node) in a singly linked list:
Handle edge cases first
If the list is empty → nothing to delete.
If the list has only one node → delete it and return NULL.
Traverse to the second-last node
Since it’s a singly linked list, you cannot go backward.
So you stop at the node whose next->next == NULL.
Delete the last node
Free memory using delete.
Update the second-last node’s next to NULL.
Return the original head
Head does not change when deleting the tail.
Key idea:
You must stop one node before the tail to safely delete it.


*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

Node* delTail(Node* head)
{
    if (head == NULL)          // Case 1: Empty linked list
        return NULL;

    if (head->next == NULL)    // Case 2: Only one node in the list
    {
        delete head;           // Delete the only node
        return NULL;           // List becomes empty
    }

    Node* curr = head;         // Start traversal from head

    // Move curr to the second last node
    while (curr->next->next != NULL)
        curr = curr->next;

    delete (curr->next);       // Delete the last node
    curr->next = NULL;         // Set second last node's next to NULL

    return head;               // Head remains unchanged
}



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/

