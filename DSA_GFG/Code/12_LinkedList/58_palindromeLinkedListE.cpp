#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(char x)
    {
        data = x;
        next = NULL;
    }
};

Node *reverseList(Node *head)
{

    Node *curr = head;
    if (head == NULL || head->next == NULL)
        return head;

    Node *nextNode = NULL;
    Node *prevNode = NULL;

    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }
    return prevNode;
}

bool isPalindrome(Node *head)
{
    if (head == NULL)
        return true;
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *reversed = reverseList(slow->next);
    Node *curr = head;
    while (reversed != NULL)
    {
        if (curr->data != reversed->data)
            return false;
        reversed = reversed->next;
        curr = curr->next;
    }
    return true;
}

int main()
{
    Node *head = new Node('g');
    head->next = new Node('f');
    head->next->next = new Node('g');
    if (isPalindrome(head))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n)
Finding middle → O(n)
Reversing half → O(n)
Comparing → O(n)
Total is still linear.
🧠 Space Complexity
O(1) (constant extra space)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use slow and fast pointers to find the middle of the linked list
Reverse the second half of the list
Compare the first half and reversed second half
If all corresponding nodes match → palindrome
This avoids using a stack or array.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

bool isPalindrome(Node *head)
{
    // Empty list or single node is always a palindrome
    if (head == NULL)
        return true;

    Node *slow = head;
    Node *fast = head;

    // Step 1: Find middle of the list
    // slow moves 1 step, fast moves 2 steps
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half of the list
    Node *reversed = reverseList(slow->next);

    // Step 3: Compare first half and reversed second half
    Node *curr = head;
    while (reversed != NULL)
    {
        if (curr->data != reversed->data)
            return false;
        reversed = reversed->next;
        curr = curr->next;
    }

    return true;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Slow & Fast Pointer Pattern
Used to find middle efficiently
✅ Reverse-in-place Pattern
Reverse second half to simulate backward traversal
Combined Pattern Name:
Two-pointer + In-place modification




*/
