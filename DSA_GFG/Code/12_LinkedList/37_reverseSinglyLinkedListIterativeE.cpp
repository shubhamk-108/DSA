// Reverse Singly Singly LinkedList

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

Node * reverseSinglyLinkedList(Node *head)
{
    if(head==NULL)
        return NULL;
    Node *curr = head;
    
    Node*prevNode = NULL;
    Node *nextNode;

    while(curr!= NULL)
    {
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }
    return prevNode;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = new Node(70);
    printlist(head);
    head = reverseSinglyLinkedList(head);
    printlist(head);
    return 0;
}



//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n) — single traversal
Space: O(1) — no extra data structures
*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*

Initialize three pointers
curr → starts at head (current node being processed)
prev → starts as NULL (previous node)
next → used to temporarily store curr->next
Iterate through the list
Save the next node
next = curr->next

Reverse the current link
curr->next = prev
Move pointers forward
prev = curr
curr = next
Finish
When curr becomes NULL, the list is fully reversed
prev now points to the new head
Return prev


*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

Node * reverseSinglyLinkedList(Node *head)
{
    // If list is empty
    if (head == NULL)
        return NULL;

    // Current pointer starts at head
    Node *curr = head;

    // Previous node starts as NULL
    Node *prevNode = NULL;

    // Will store next node temporarily
    Node *nextNode;

    // Traverse the list
    while (curr != NULL)
    {
        nextNode = curr->next;   // Save next node
        curr->next = prevNode;   // Reverse the link
        prevNode = curr;         // Move prev forward
        curr = nextNode;         // Move curr forward
    }

    // prevNode is the new head
    return prevNode;
}



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/

