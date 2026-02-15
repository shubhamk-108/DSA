
// problem statement:
//  Given a head of linked list where each node has two links: next pointer pointing to the next node and random pointer to any random node in the list.
//  Create a clone of this linked list. YOu have to create puerly new linked list means the addresses of both the links will be different.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next, *random;
	Node(int x)
	{
		data = x;
		next = random = NULL;
	}
};

void print(Node *start)
{
	Node *ptr = start;
	while (ptr)
	{
		cout << "Data = " << ptr->data << ", Random  = " << ptr->random->data << endl;
		ptr = ptr->next;
	}
}

Node *clone(Node *head)
{
	Node *curr = head;

	while (curr != NULL)
	{
		Node *NextNode = curr->next;
		curr->next = new Node(curr->data);
		curr->next->next = NextNode;
		curr = NextNode;
	}

	curr = head;
	while (curr != NULL && curr->next != NULL)
	{
		if (curr->random == NULL)
			curr->next->random = nullptr;
		else
			curr->next->random = curr->random->next;
		curr = curr->next->next;
	}

	curr = head;
	Node *cloneHead = head->next;
	Node *curr2 = cloneHead;

	while (curr != nullptr && curr->next != nullptr && curr2 != nullptr && curr2->next != nullptr)
	{
		curr->next = curr->next->next;
		curr2->next = curr2->next->next;
		curr = curr->next;
		curr2 = curr2->next;
	}
	return cloneHead;
}

int main()
{
	Node *head = new Node(10);
	head->next = new Node(5);
	head->next->next = new Node(20);
	head->next->next->next = new Node(15);
	head->next->next->next->next = new Node(20);

	head->random = head->next->next;
	head->next->random = head->next->next->next;
	head->next->next->random = head;
	head->next->next->next->random = head->next->next;
	head->next->next->next->next->random = head->next->next->next;

	cout << "Original list : \n";
	print(head);

	cout << "\nCloned list : \n";
	Node *cloned_list = clone(head);
	print(cloned_list);

	return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity	
Step 1: O(n)
Step 2: O(n)
Step 3: O(n)
✅ Overall: O(n)

💾 Space Complexity
✅ O(1) extra space (output list doesn’t count)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

This problem asks for a deep copy of a linked list where each node has:
next pointer
random pointer (can point anywhere or be NULL)
The optimal solution avoids extra space (like a hash map) by using a 3-step in-place strategy:

Step 1: Interleave cloned nodes with original nodes
For every original node X, create a clone X' and insert it right after X.
Original:  X → Y → Z
Becomes:   X → X' → Y → Y' → Z → Z'

Step 2: Assign random pointers to cloned nodes
Because clones are placed immediately after originals:
If X.random = Y
Then X'.random = Y.next
This works in O(1) time per node.

Step 3: Separate the two lists
Restore the original list and extract the cloned list by fixing next pointers.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

Node *clone(Node *head)
{
    Node *curr = head;

    // STEP 1: Insert cloned nodes after each original node
    while (curr != NULL)
    {
        Node *NextNode = curr->next;          // Save original next
        curr->next = new Node(curr->data);    // Create clone
        curr->next->next = NextNode;          // Link clone to next original
        curr = NextNode;                      // Move to next original node
    }

    // STEP 2: Set random pointers of cloned nodes
    curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->random == NULL)
            curr->next->random = nullptr;     // Clone random is null
        else
            curr->next->random = curr->random->next; // Point to clone of random

        curr = curr->next->next;              // Jump to next original
    }

    // STEP 3: Separate original and cloned lists
    curr = head;
    Node *cloneHead = head->next;              // Head of cloned list
    Node *curr2 = cloneHead;

    while (curr != nullptr && curr->next != nullptr &&
           curr2 != nullptr && curr2->next != nullptr)
    {
        curr->next = curr->next->next;        // Restore original next
        curr2->next = curr2->next->next;      // Fix clone next

        curr = curr->next;                    // Move originals
        curr2 = curr2->next;                  // Move clones
    }

    return cloneHead;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
