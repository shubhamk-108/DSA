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
    cout << endl;
}

Node *reverseK(Node *head, int k)
{
    Node *curr = head;
    Node *nextNode = NULL;
    Node *prevNode = NULL;
    int count = k;
    while (curr != NULL && count > 0)
    {
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
        count--;
    }

    if (curr != NULL)
    {
        Node *newHeadOfSubLL = reverseK(curr, k);
        head->next = newHeadOfSubLL;
    }

    return prevNode;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = new Node(70);
    head->next->next->next->next->next->next->next = new Node(80);
    head->next->next->next->next->next->next->next->next = new Node(90);
    printlist(head);
    head = reverseK(head, 3);
    printlist(head);
    return 0;
}


//___________________________________________________________________________________________________________________________________________
// Some of my imp understanding
//___________________________________________________________________________________________________________________________________________
/*
if (curr != NULL)
    {
        Node *newHeadOfSubLL = reverseK(curr, k);
        head->next = newHeadOfSubLL;
    }

    return prevNode;

LL = 10-20-30-40-50-60-70-80-90
New LL = 30-20-10   60-50-40  90-80-70-Null.

Now you see that after each froup reversal we have to connect groups like 10-60, 40-90.
But we dont have to connect 70 to the some next because there is no group next to it. Thus, we are connecting in the if condition
head->next = newHeadOfSubLL; Because the we dont have to connect last group to any next group. if(curr!=NULL) then only
we connect that is we are skipping connection to the last group. 
The last call here in this ex will return prevNode which is new head and it is 90. Now we have to connect 40 to 90.
90 has been returned to its parent and we are in parent's call that is 60-50-40. Now 40 will be called as head because
it was the head of the group before reversal. So we connect head->next which is 40 the the prevNode which is newHeadOfSubLL which
was returned to its parent as return prevNode statement.


*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
time:
O(n)
Each node is visited exactly once.

📦 Space Complexity
O(n / k) due to recursion stack
Worst case: O(n) when k = 1

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Start from the head of the linked list.
Reverse the first k nodes using the standard iterative reversal technique.
After reversing k nodes:
prevNode becomes the new head of the current group.
old head becomes the last node of the current group.
Recursively reverse the remaining list starting from curr.
Connect the last node of the current reversed group (old head) to the head of the next reversed group (prevNode).
Return prevNode as the new head.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

Node* reverseK(Node* head, int k)
{
    // Pointer to traverse the list
    Node* curr = head;

    // Will store next node during reversal
    Node* nextNode = NULL;

    // Will become the new head of the reversed group
    Node* prevNode = NULL;

    // Counter to reverse exactly k nodes
    int count = k;

    // Reverse first k nodes
    while (curr != NULL && count > 0)
    {
        nextNode = curr->next;   // store next node
        curr->next = prevNode;   // reverse the link
        prevNode = curr;         // move prev forward
        curr = nextNode;         // move curr forward
        count--;
    }

    // If nodes are still left, reverse remaining list recursively
    if (curr != NULL)
    {
        Node* newHeadOfSubLL = reverseK(curr, k);

        // Connect current group to the next reversed group
        head->next = newHeadOfSubLL;
    }

    // prevNode is the new head of the reversed group
    return prevNode;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

K-Group Linked List Reversal
This problem combines multiple patterns:
In-place Linked List Reversal
Divide & Conquer (by groups of size k)
Recursion
Two-Pointer Technique (curr, prevNode)


*/
