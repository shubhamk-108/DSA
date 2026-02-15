/*
Reverse singly linked list
*/

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

Node *reverseSinglyLinkedList(Node *head, Node *prevNode)
{
    if(head == NULL )
        return prevNode;

    Node *nextNode = head->next;
    head->next = prevNode;
    return reverseSinglyLinkedList(nextNode, head);
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
    head = reverseSinglyLinkedList(head, nullptr);
    printlist(head);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
Each node is processed once
O(n)

Space Complexity

Recursive call stack uses n frames
O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

It is the tail-recursive version of reversing a singly linked list

1️⃣ Approach (Logic Explanation)
This approach reverses the linked list using recursion while carrying state forward.
Key idea
Instead of waiting for recursion to return (like standard recursion),
We pass the previous node (prevNode) as a parameter,
Each recursive call reverses one link and moves forward.
Steps
Start with:
head → current node
prevNode → previous node (initially NULL)
Save the next node
Reverse the current node’s link
Recurse on the remaining list
When head becomes NULL, prevNode is the new head



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
Node *reverseSinglyLinkedList(Node *head, Node *prevNode)
{
    // Base case: end of list reached
    // prevNode now points to the new head
    if (head == NULL)
        return prevNode;

    // Store next node before breaking the link
    Node *nextNode = head->next;

    // Reverse the current node's link
    head->next = prevNode;

    // Recursive call with updated pointers
    return reverseSinglyLinkedList(nextNode, head);
}




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Tail Recursion

*/
