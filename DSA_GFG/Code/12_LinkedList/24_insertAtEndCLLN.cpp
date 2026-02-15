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
        Node *curr = head;
        while (curr->next != head)
            curr = curr->next;

        curr->next = temp;
        temp->next= head;
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
    head = insertAtEnd(head, 40);
    printCll(head);

    return 0;
}


// Approach
/*
Create a new node with value x
If list is empty
Make the new node point to itself
Return it as head
If list is non-empty
Traverse the list to reach the last node
(curr->next == head)
Link last node to the new node
Make new node point back to head
*/

// Time Complexity
// O(n)
// (Traversal to the last node)

// 📦 Space Complexity
// O(1)