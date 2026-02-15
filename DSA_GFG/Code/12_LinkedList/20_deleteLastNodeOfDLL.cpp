#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int data;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void printList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *curr = head;

    while (curr->next->next != NULL)
        curr = curr->next;

    Node *tail = curr->next;   
    curr->next = NULL;
    tail->prev = NULL;
    delete (tail);
    return head;
}

int main()
{
    Node *head = new Node(10);

    Node *second = new Node(20);
    Node *third = new Node(30);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    printList(head);
    head = deleteTail(head);
    printList(head);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n) — traversal to second-last node

📦 Space Complexity
O(1) — constant extra space
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Handle edge cases (empty or single node list)
Traverse to the second-last node
Store tail node
Break forward and backward links
Delete tail
Return head

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
