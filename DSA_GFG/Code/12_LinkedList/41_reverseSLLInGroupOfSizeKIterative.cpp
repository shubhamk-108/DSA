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
    if (head == NULL || k <= 1)
        return head;

    Node *curr = head;
    Node *nextNode = nullptr;
    Node *prevNode = nullptr;
    Node *newHead = nullptr;
    Node *tailOfPrevGroupAfterReversal = NULL;
    bool isFirstGroup = true;

    while (curr != NULL)
    {
        prevNode = NULL;
        Node *groupHeadBeforeReversal = curr;
        int count = 0;
        while (curr != NULL && count < k)
        {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
            count++;
        }
        if (isFirstGroup)
        {
            isFirstGroup = false;
            newHead = prevNode;
        }
        else
        {
            tailOfPrevGroupAfterReversal->next = prevNode;
        }
        tailOfPrevGroupAfterReversal = groupHeadBeforeReversal;
    }
    return newHead;
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
// Explanation
//___________________________________________________________________________________________________________________________________________
/*

Problem in one line

Reverse a singly linked list in groups of size k.

Example (k = 3):

10 → 20 → 30 → 40 → 50 → 60 → 70 → 80 → 90
30 → 20 → 10 → 60 → 50 → 40 → 90 → 80 → 70

The key idea (before code)
We repeat this process until the list ends:
Take k nodes
Reverse them
Connect them to the previously reversed group
To do this iteratively, we must remember:
the head of the first reversed group (final answer)
the tail of the previous group (to connect groups)

Now, line-by-line explanation
1️⃣ Edge case
if (head == NULL || k <= 1)
    return head;

Empty list → nothing to reverse
k = 1 → reversing does nothing
2️⃣ Pointer setup
Node* curr = head;
Node* nextNode = nullptr;
Node* prevNode = nullptr;
Node* newHead = nullptr;
Node* tailOfPrevGroupAfterReversal = NULL;
bool isFirstGroup = true;


What each pointer means:
| Pointer                        | Meaning                          |
| ------------------------------ | -------------------------------- |
| `curr`                         | Where we are in the list         |
| `prevNode`                     | Builds the reversed group        |
| `nextNode`                     | Temporarily stores next node     |
| `newHead`                      | Head of the final answer         |
| `tailOfPrevGroupAfterReversal` | Used to connect groups           |
| `isFirstGroup`                 | Special handling for first group |


3️⃣ Process the list group by group
while (curr != NULL)
As long as nodes remain, we keep reversing groups.

4️⃣ Prepare for a new group
prevNode = NULL;
Node* groupHeadBeforeReversal = curr;
int count = 0;

Important:
groupHeadBeforeReversal will become the tail after reversal

prevNode = NULL ensures a clean reversal

5️⃣ Reverse exactly k nodes
while (curr != NULL && count < k)
{
    nextNode = curr->next;
    curr->next = prevNode;
    prevNode = curr;
    curr = nextNode;
    count++;
}

This is standard linked list reversal:
Reverse pointer
Move forward
Repeat k times
After this loop:
prevNode → head of the reversed group
groupHeadBeforeReversal → tail of the reversed group
curr → start of next group

6️⃣ Handle the first group specially
if (isFirstGroup)
{
    isFirstGroup = false;
    newHead = prevNode;
}

Why?
The first reversed group defines the new head of the list
We save it once and never change it again

7️⃣ Connect previous group to current group
else
{
    tailOfPrevGroupAfterReversal->next = prevNode;
}

For all groups except the first:
Connect the previous group’s tail
To the current group’s head

8️⃣ Update tail pointer
tailOfPrevGroupAfterReversal = groupHeadBeforeReversal;
Now this group becomes the “previous group” for the next iteration.

9️⃣ Return final head
return newHead;
This is the head of the entire reversed list.
Why this works (mental model)
Think in blocks:
[10 20 30] → [40 50 60] → [70 80 90]
Each block:
Is reversed independently
Then stitched together using tail pointers

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n)
Each node is visited exactly once.

📦 Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Handle edge cases:
If the list is empty or k <= 1, no reversal is needed.
Traverse the list group by group.
For each group:
Reverse exactly k nodes using the standard iterative reversal technique.
Keep track of
The head of the group before reversal (it becomes the tail after reversal).
The new head of the list after the first group is reversed.
Connect:
The tail of the previous reversed group to the head of the current reversed group.
Continue until all nodes are processed.
Return the new head of the list.
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


Node* reverseK(Node* head, int k)
{
    // Edge cases: empty list or no reversal needed
    if (head == NULL || k <= 1)
        return head;

    Node* curr = head;                 // Pointer to traverse the list
    Node* nextNode = nullptr;          // Temporarily stores next node
    Node* prevNode = nullptr;          // Used for reversing links
    Node* newHead = nullptr;           // New head of the final list
    Node* tailOfPrevGroupAfterReversal = NULL; // Tail of previous reversed group
    bool isFirstGroup = true;           // Flag to handle first group separately

    // Process the list group by group
    while (curr != NULL)
    {
        prevNode = NULL;               // Reset for each group
        Node* groupHeadBeforeReversal = curr; // Will become tail after reversal
        int count = 0;

        // Reverse k nodes
        while (curr != NULL && count < k)
        {
            nextNode = curr->next;     // Save next node
            curr->next = prevNode;     // Reverse link
            prevNode = curr;           // Move prev forward
            curr = nextNode;            // Move curr forward
            count++;
        }

        // If this is the first reversed group, set newHead
        if (isFirstGroup)
        {
            isFirstGroup = false;
            newHead = prevNode;
        }
        else
        {
            // Connect previous group to current reversed group
            tailOfPrevGroupAfterReversal->next = prevNode;
        }

        // Update tail for next iteration
        tailOfPrevGroupAfterReversal = groupHeadBeforeReversal;
    }

    return newHead; // Return head of the fully reversed list
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



*/
