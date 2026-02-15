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

void printCDLL(Node *head)
{
    if (head == NULL)
        return;

    Node *curr = head;

    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout<<endl;
}

void printCDLLBackward(Node *head)
{
    if (head == NULL)
        return;

    Node *curr = head->prev;

    do
    {
        cout << curr->data << " ";
        curr = curr->prev;
    } while (curr != head->prev);
    cout<<endl;
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

    temp2->next = head;
    head->prev = temp2;

    printCDLL(head);
    printCDLLBackward(head);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Operation   | Complexity |
| ----------- | ---------- |
| Traversal   | **O(n)**   |
| Extra Space | **O(1)**   |

*/
