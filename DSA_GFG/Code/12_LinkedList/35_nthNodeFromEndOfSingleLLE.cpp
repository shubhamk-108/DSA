// find Nth Node From End Of Singly LinkedList

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
int findNthNodeFromEndOfSinglyLinkedList(Node *head, int n)
{
    // If linked list is empty
    if (head == NULL)
        return -1;

    // First pointer (fast pointer)
    Node *first = head;

    // Move first pointer n steps ahead
    for (int i = 0; i < n; i++)
    {
        // If n is greater than length of list
        if (first == NULL)
            return -1;
        first = first->next;
    }

    // Second pointer (slow pointer)
    Node *second = head;

    // Move both pointers until first reaches NULL
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    // Second now points to nth node from end
    return second->data;
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
    cout << findNthNodeFromEndOfSinglyLinkedList(head, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n)

Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Step-by-step logic:
Initialize two pointers:
first → used to create a gap
second → will eventually point to the answer
Move first ahead by n nodes:
This creates a fixed distance of n nodes between first and second
If n is greater than the length of the list, return -1
Move both pointers together:
Move first and second one step at a time
When first reaches NULL, second will be at the n-th node from the end
Return second->data

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

int findNthNodeFromEndOfSinglyLinkedList(Node *head, int n)
{
    // If linked list is empty
    if (head == NULL)
        return -1;

    // First pointer (fast pointer)
    Node *first = head;

    // Move first pointer n steps ahead
    for (int i = 0; i < n; i++)
    {
        // If n is greater than length of list
        if (first == NULL)
            return -1;
        first = first->next;
    }

    // Second pointer (slow pointer)
    Node *second = head;

    // Move both pointers until first reaches NULL
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    // Second now points to nth node from end
    return second->data;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

👉 Two Pointer / Fast–Slow Pointer Pattern


*/
