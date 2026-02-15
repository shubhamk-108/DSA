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

int findMiddlle(Node *head)
{
    if(head==NULL)
        return -1;
    int count = 0;
    Node *curr;
    for(curr = head; curr!= NULL;curr = curr->next)
        count++;

    curr= head;
    for(int i =0; i<count /2; i++)
        curr = curr->next;
    return curr->data;
}

//for 2 middle in even case print 2nd middle
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    printlist(head);
    cout << "Middle of Linked List: ";
    cout << findMiddlle(head);
    return 0;
}
           
// timespace
/*
Time Complexity
First traversal → O(n)
Second traversal → O(n)
👉 Total Time = O(n)
💾 Space Complexity
👉 Space = O(1)
*/

// approach 

/*

Counts the number of nodes.
Traverses again to reach the middle node.
Returns the middle node’s data.
For even number of nodes, it returns the second middle, which is standard in many problems.
Example:
1 → 2 → 3 → 4 → returns 3
1 → 2 → 3 → 4 → 5 → returns 3

🧠 Approach (Naive / Two Traversals)

Step 1: Count nodes
Traverse the linked list from head to NULL
Store total number of nodes in count

Step 2: Move to middle
Middle index = count / 2
Traverse again from head for count / 2 steps
The node reached is the middle node

*/
