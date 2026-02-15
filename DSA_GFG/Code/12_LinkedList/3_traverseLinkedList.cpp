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
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printlist(head);
    printlist(head);
    return 0;
}

// Time:O(n)
//Space:O(1)

//___________________________________________________________________________________________________________________________________________
// About pointer passing to function
//___________________________________________________________________________________________________________________________________________

/*

When you call:
printList(head);
you are passing a COPY of the pointer head, not the original pointer variable.
What changes and what doesn’t
void printList(Node* head)
head is a local copy
Moving head or curr inside the function does NOT affect main
Only the node contents (head->data) could be modified
So after first call:
curr becomes NULL
main’s head is unchanged
Second call prints the list again
Why reference behaves differently
void f(int& x)
x is an alias of the original variable
Changes affect main memory directly
But:
void f(Node* p)
p is just a copied value (address)
Changing p doesn’t change the original pointer
If you want head to become NULL
You must pass the pointer by reference:

void printList(Node*& head)
or
void printList(Node** head)
Then modifying head will affect main.

*/



