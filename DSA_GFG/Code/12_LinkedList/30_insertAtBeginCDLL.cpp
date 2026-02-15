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

Node *insertAtBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    temp->next = head;
    temp->prev = head->prev;
    head->prev->next = temp;
    head->prev = temp;
    return temp;
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
    head = insertAtBegin(head, 5);
    printCDLL(head);

    return 0;
}




//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(1)
No traversal is required; only constant pointer updates.

💾 Space Complexity
O(1)
Only one extra node is allocated.
*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*


Create a new node with the given value.
If the list is empty:
Make the new node point to itself in both next and prev.
Return it as the new head.
If the list is non-empty:
Link the new node before the current head.
Update the last node’s next to point to the new node.
Update the current head’s prev to point to the new node.
Return the new node as the updated head.
This preserves both:
Circularity (last->next = head)
Doubly links (prev and next in both directions)

*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*


Node *insertAtBegin(Node *head, int x)
{
    Node *temp = new Node(x);

    // Case 1: Empty list
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    // Case 2: Non-empty list
    temp->next = head;           // new node points forward to old head
    temp->prev = head->prev;     // new node points backward to last node

    head->prev->next = temp;     // last node points forward to new node
    head->prev = temp;           // old head points backward to new node

    return temp;                 // new node becomes head
}


*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/

