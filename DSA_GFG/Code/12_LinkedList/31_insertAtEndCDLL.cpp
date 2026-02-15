#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void printCDLL(Node *head)
{
    if (head == NULL)
        return;

    Node *curr = head;

    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

Node *insertAtEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    Node *last = head->prev;
    
    last->next = temp;
    temp->prev = last;

    temp->next = head;
    head->prev = temp;

    return head;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;

    temp2->next = head;
    head->prev = temp2;

    printCDLL(head);
    head = insertAtEnd(head, 50);
    printCDLL(head);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(1)
No traversal is required because the last node is directly accessible via head->prev.

💾 Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Create a new node with the given value.
If the list is empty:
Make the node point to itself in both next and prev.
Return it as the head.
If the list is non-empty:
Use head->prev to get the last node.
Insert the new node between the last node and the head.
Update both forward and backward pointers to maintain circularity.
Return the head since insertion is at the end.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


Node *insertAtEnd(Node *head, int x)
{
    // Create a new node with given value
    Node *temp = new Node(x);

    // Case 1: Empty list
    if (head == NULL)
    {
        // Point new node to itself (circular + doubly)
        temp->next = temp;
        temp->prev = temp;
        return temp;   // new node becomes head
    }

    // Get the last node using head->prev
    Node *last = head->prev;
    
    // Link new node after last node
    last->next = temp;
    temp->prev = last;

    // Complete the circular links
    temp->next = head;
    head->prev = temp;
    
    // Head remains unchanged
    return head;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
