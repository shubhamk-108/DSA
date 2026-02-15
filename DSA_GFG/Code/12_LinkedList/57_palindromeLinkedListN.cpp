#include <bits/stdc++.h>
#include <stack>
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

bool isPalindrome(Node *head)
{
    stack<char> st;
    for (Node *curr = head; curr != NULL; curr = curr->next)
        st.push(curr->data);
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (st.top() != curr->data)
            return false;
        st.pop();
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
One traversal to push
One traversal to compare

🧠 Space Complexity
O(n)
Stack stores all node values

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Traverse the linked list from head to end
Push each node’s data onto a stack
(stack reverses the order)
Traverse the linked list again from head
For each node:
Compare its value with the stack’s top
If mismatch → not a palindrome
If all values match → palindrome
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


bool isPalindrome(Node *head)
{
    stack<int> st;
    Node *curr = head;

    // Push all elements into stack
    while (curr != nullptr)
    {
        st.push(curr->data);
        curr = curr->next;
    }

    // Compare stack elements with list from start
    curr = head;
    while (curr != nullptr)
    {
        if (st.top() != curr->data)
            return false;
        st.pop();
        curr = curr->next;
    }

    return true;
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
