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

Node *insertInSortedSLL(Node *head, int x)
{
    Node *newNode = new Node(x);
    if (head == NULL)
        return newNode;
    if (x < head->data)
    {
        newNode->next = head;
        return newNode;
    }

    Node *curr = head;

    while (curr->next != NULL && x > curr->next->data)
        curr = curr->next;
    
    newNode->next = curr->next;
    curr->next = newNode;
    return head;    
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *head = new Node(15);
    head->next = new Node(27);
    head->next->next = new Node(41);
    head->next->next->next = new Node(58);

    head = insertInSortedSLL(head, 30);

    printList(head);

    return 0;
}


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
Best case: O(1) (insert at beginning)
Worst case: O(n) (insert at end)
Overall: O(n)

💾 Space Complexity
O(1)

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*


Create a new node with value x.
If the list is empty, return the new node as head.
If x is smaller than the head’s data, insert at the beginning.
Traverse the list until:
The next node is NULL, or
The next node’s value is greater than or equal to x.
Insert the new node by adjusting next pointers.
Return the original head.
This keeps the list sorted at all times.

*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

Node *insertInSortedSLL(Node *head, int x)
{
    // Create a new node with value x
    Node *newNode = new Node(x);

    // Case 1: Empty list
    if (head == NULL)
        return newNode;

    // Case 2: Insert before head
    if (x < head->data)
    {
        newNode->next = head;
        return newNode;
    }

    // Traverse to find correct position
    Node *curr = head;

    // Move while next node exists and its value is smaller than x
    while (curr->next != NULL && x > curr->next->data)
        curr = curr->next;
    
    // Insert new node at correct position
    newNode->next = curr->next;
    curr->next = newNode;

    // Head remains unchanged
    return head;    
}



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/

