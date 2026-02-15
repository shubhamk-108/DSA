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

Node* insertAtEnd(Node*head, int x)
{
    Node *newNode = new Node(x);
    if(head==NULL)
        return newNode;
    Node *temp = head;

    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;

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

int main() {
  
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head = insertAtEnd(head, 6);

    printList(head);

    return 0;
}


//___________________________________________________________________________________________________________________________________________
// Question: Node *temp = head; temp->next = newNode; But here we are changing temp's next. original head's linked list is as it is. 
// so how it is reflectiing in original list.
//___________________________________________________________________________________________________________________________________________

/*

👉 temp is NOT a copy of the node
👉 temp is another pointer to the SAME node in heap
Very important distinction
❌ What you think is happening
“temp is a separate thing, so changing temp->next shouldn’t affect head”
✅ What is actually happening
“temp and head point to the same node, so modifying the node modifies the list”

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n)
Because in the worst case we traverse the entire list to reach the last node.
Space Complexity
O(1) (Auxiliary space)

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*
Create a new node with the given value x.
If the linked list is empty (head == NULL), the new node itself becomes the head.
Otherwise:
Start from the head.
Traverse the list until you reach the last node (temp->next == NULL).
Link the last node’s next to the new node.
Return the (unchanged) head pointer.



*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*


#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    // Constructor to initialize a node
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to insert a node at the end of the linked list
Node* insertAtEnd(Node* head, int x)
{
    // Create a new node with given value
    Node *newNode = new Node(x);

    // If list is empty, new node becomes the head
    if (head == NULL)
        return newNode;

    // Temporary pointer to traverse the list
    Node *temp = head;

    // Traverse till the last node
    while (temp->next != NULL)
        temp = temp->next;

    // Link last node to new node
    temp->next = newNode;

    // Head remains unchanged
    return head;
}

// Function to print the linked list
void printList(Node *head)
{
    Node *temp = head;

    // Traverse and print each node's data
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating initial linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Insert 6 at the end
    head = insertAtEnd(head, 6);

    // Print updated linked list
    printList(head);

    return 0;
}


*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/

