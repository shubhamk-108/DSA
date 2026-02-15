#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void printCll(Node *head)
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
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = temp->data;
        temp->data = head->data;
        head->data = t;
        return head->next;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    printCll(head);
    head = insertAtEnd(head, 40);
    printCll(head);

    return 0;
}

// approach
/*
Create a new node with value x
If list is empty
Make new node point to itself
Return it as head
If list is non-empty
Insert new node after head
Swap data between head and new node
(so old head data moves forward)
Return head->next as the new tail
👉 Logical effect: new value x appears at the end.
*/

// Time Complexity
// O(1)
// No traversal required
// 📦 Space Complexity
// O(1)