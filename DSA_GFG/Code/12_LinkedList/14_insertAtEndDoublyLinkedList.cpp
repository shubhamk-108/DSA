#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data = d;
        prev = NULL;
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

Node *insertAtEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head != NULL)
    {
        Node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;

        curr->next = temp;
        temp->prev = curr;
        return head;
    }
    return temp;
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    printlist(head);
    head = insertAtEnd(head, 5);
    printlist(head);
    return 0;
}

// time:O(n)
// space:O(1)

// Time Complexity
// ⏱ O(n)
// Why?
// In the worst case, you traverse the entire list to reach the last node: