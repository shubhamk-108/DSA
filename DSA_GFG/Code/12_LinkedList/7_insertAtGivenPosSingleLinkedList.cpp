

#include <iostream>
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

Node *insertAtPos(Node *head, int x, int pos)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        if (pos == 1)
            return temp;
        else
            return head;
    }
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }

    Node *curr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        curr = curr->next;
        if (curr == NULL)
        {
            cout << "position out of range\n";
            return head;
        }
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

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

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printlist(head);
    head = insertAtPos(head, 25, 2);
    printlist(head);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n)
Because in the worst case, you traverse the list to reach the given position.

💾 Space Complexity
O(1) (auxiliary space)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Create a new node with value x.
Handle edge cases:
If the list is empty:
If pos == 1, return the new node as head.
Otherwise, insertion is not possible.
If pos == 1 in a non-empty list:
Insert at the beginning.
Traverse the list to reach the (pos - 1)th node.
If traversal goes out of bounds, position is invalid.
Adjust pointers:
New node points to current node’s next.
Current node points to new node.
Return the head pointer


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

Node* insertAtPos(Node* head, int x, int pos)
{
    // Create new node with given value
    Node* temp = new Node(x);

    // Case 1: Empty list
    if (head == NULL)
    {
        // Only valid insertion is at position 1
        if (pos == 1)
            return temp;
        else
            return head;
    }

    // Case 2: Insert at beginning
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }

    // Traverse to (pos - 1)th node
    Node* curr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        curr = curr->next;

        // If position is out of range
        if (curr == NULL)
        {
            cout << "position out of range\n";
            return head;
        }
    }

    // Insert node at the given position
    temp->next = curr->next;
    curr->next = temp;

    // Head remains unchanged
    return head;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
