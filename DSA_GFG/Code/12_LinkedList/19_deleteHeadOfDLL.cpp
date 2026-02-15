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

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *newHead = head->next;

    newHead->prev = NULL;
    head->next = NULL;
    delete (head);
    return newHead;
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
    head = deleteHead(head);
    printList(head);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time: O(1)
Space: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Handle edge cases
If the list is empty → return NULL
If there is only one node → delete it and return NULL
Move head forward
Store head->next as newHead
Fix links
Set newHead->prev = NULL to make it the new head
Delete old head
Free memory of the old head node
Return new head

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
