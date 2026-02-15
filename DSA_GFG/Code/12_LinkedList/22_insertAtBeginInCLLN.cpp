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

Node *insertAtBegin(Node *head, int x)
{
    Node *temp = new Node(x);

    if (head == NULL)
    {
        temp->next = temp;
    }
    else
    {
        Node *curr = head;
        while (curr->next != head)
            curr = curr->next;

        curr->next = temp;
        temp->next = head;
    }
    return temp;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    printCll(head);
    head = insertAtBegin(head, 40);
    printCll(head);

    return 0;
}

// Time Complexity
// O(n) — traversal to last node
// 📦 Space Complexity
// O(1) — constant extra space

// approach


/*

Create a new node
If list is empty:
Make new node point to itself
Else:
Traverse to last node
Link last node to new node
Link new node to old head
Return new node as head

*/