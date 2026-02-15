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

void printList(Node *head)
{
    if(head == NULL)
        return;

    cout<<head->data<<" ";
    printList(head->next);  
}

int main()
{
    Node * head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printList(head);
}

// Time:O(n)
//Space:O(n) due to recursive function call stack
