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

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;

    else if (head->next == head)
    {
        delete (head);
        return NULL;
    }
    else
    {
        Node *temp = head->next;
        head->data = temp->data;
        head->next = temp->next;
        delete(temp);
        return head;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    printCll(head);
    head = deleteHead(head);
    printCll(head);

    return 0;
}


// approach 
// Handle empty list
// Handle single-node list
// Copy data from second node into head
// Bypass second node
// Delete second node
// Return head

// Time Complexity
// O(1)

// 📦 Space Complexity
// O(1)