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

Node *pairwiseSwap(Node *head)
{
    Node *curr = head;
    Node *prev = nullptr;

    while (curr != NULL && curr->next != NULL)
    {
        Node *first = curr;
        Node *second = curr->next;
        Node *third = curr->next->next;

        second->next = first;
        first->next = third;
        if (prev == nullptr)
        {
            head = second;
        }
        else
        {
            prev->next = second;
        }
        prev = first;
        curr = third;
    }
    return head;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printlist(head);
    head = pairwiseSwap(head);
    printlist(head);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// why first->next = third; even though we do prev->next = second; and here prev is first.
//___________________________________________________________________________________________________________________________________________

/*

Question:
For list 1-2-3-4
for the second iteration our prev will become 1 abd then we connect prev->next = sec means 1->next which is 4 which is 1->4. 
then why we have to connect 1->3 in the first iteration. anyways we are checking it in second iteration and to go in tird iteration we have 
already stored third node so not helping these also.

Ans:

Because the linked list must remain valid after every iteration.
You are allowed to fix links only when you reach the next iteration — not before.
If you skip first->next = third, the list becomes invalid immediately, even if it might be fixed later.
Algorithms are not allowed to rely on “future corrections”.

That link is:
required to avoid cycles
required to keep the list traversable
required to maintain invariants
It is a temporary bridge, not a final one.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity:
O(n)

4️⃣ Space Complexity
Auxiliary Space:
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal:
Swap nodes of a singly linked list in pairs without swapping data.
Example:

Input :  1 → 2 → 3 → 4 → 5
Output:  2 → 1 → 4 → 3 → 5

Idea
Traverse the list two nodes at a time.
For each pair:
Reverse the links between the two nodes.
Connect the swapped pair with the previously swapped part.
Keep the remaining list intact.
Maintain the invariant:
After every iteration, the list remains valid and partially swapped.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

Node *pairwiseSwap(Node *head)
{
    // curr points to the first node of the current pair
    Node *curr = head;

    // prev points to the tail of the previously swapped pair
    Node *prev = nullptr;

    // Process nodes in pairs
    while (curr != NULL && curr->next != NULL)
    {
        // Identify the current pair
        Node *first = curr;
        Node *second = curr->next;

        // Store the start of the next pair
        Node *third = curr->next->next;

        // Reverse the current pair
        second->next = first;
        first->next = third;

        // Update head for the first swapped pair
        if (prev == nullptr)
        {
            head = second;
        }
        else
        {
            // Connect previous swapped pair to current swapped pair
            prev->next = second;
        }

        // Move prev to the tail of the current swapped pair
        prev = first;

        // Move curr to the next pair
        curr = third;
    }

    // Return the new head of the list
    return head;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
