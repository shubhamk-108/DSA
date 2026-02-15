#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int data;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void printList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *reverseList(Node *head)
{
    if(head == NULL)
        return head;
    
    Node *nextNode = head->next;

    head->next = head->prev;
    head->prev = nextNode;

    if(head->prev == NULL)
        return head;
    return reverseList(head->prev); // equivalent to Node *newHead = reverseList(nextNode);
    
}
int main()
{
    Node *head = new Node(10);

    Node *second = new Node(20);
    Node *third = new Node(30);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    printList(head);
    head = reverseList(head);
    printList(head);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Understanding: but why this recusive code is so different that we solve before in Linked list. It is hard to reason which recursive 
// code to use when.
// Why in single LL recursive we went till the end and then start changing links but here we are first changing the links and 
// then making recursive calls.
//___________________________________________________________________________________________________________________________________________

/*

The real reason the recursive codes are different
Because the problem structure is different.
Recursion follows the structure of the data, not the name of the problem.
Both are called “reverse linked list”, but they are not the same problem structurally.
1️⃣ Singly Linked List (SLL): one-way structure
Structure:
node → node → node → NULL
What’s missing?
No backward lin
Once you move forward, you cannot come back
Consequence:
You MUST:
Go to the end first
Fix links while returning
That forces this recursive pattern:
Go deep → fix while coming back
This is why SLL reverse recursion looks like:
reverse(rest)
attach head at end

2️⃣ Doubly Linked List (DLL): two-way structure
Structure:
node ⇄ node ⇄ node ⇄ node
What’s special?
You already have a prev pointer
You can reverse links locally
Consequence:
You DON’T need:
Tail-first logic
Return-value propagation
You just:
Fix current node and move on
This leads to a totally different recursive style:
Fix → move → recurse
That’s why the DLL recursive code looks like iterative logic in disguise.

3️⃣ This is the key rule to decide “which recursion to use”
Ask yourself this ONE question:
“Can I fix the current node without knowing the future?”
If the answer is NO → Post-order recursion
(Do work while returning)
✔ Singly linked list reverse
✔ Tree height
✔ DFS post-order
recurse()
fix current
If the answer is YES → Pre-order recursion
(Do work before recursive call)
✔ Doubly linked list reverse
✔ Tree traversal
✔ Array traversal
fix current
recurse()

4️⃣ Apply this rule to your case (this is the “aha”)
Singly LL
You cannot reverse head until the tail is reversed
So you must wait
➜ post-order recursion
Doubly LL
You can reverse head immediately by swapping pointers
No dependency on future nodes
➜ pre-order recursion
That’s it.


can i write in doubly LL that we can change links before recursive call locally and still we can go to next node 
using nextNode = curr->prex since prev and next links exchanged now. So here 10->20->30 , if we change links between 10 and 20 when 
our curr pointer was on 10 then to go ahead from here to jump on 20 for next call we can use nextNode = curr->prev


so 40 will be returned from last call to all the remaining calls in function call stack. And other calls will also return 40 because 
there is no code or lines after we call recursive function. So below this line reverseList(head->prev); there is nothing. So next call
which is reverse(30) will again start its remaining execution but it will see no lines of code so it will just go out of recursion 
stack and same with 20, 10. and at the end 40 is returned.
*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time & Space Complexity
⏱ Time Complexity
O(n) where n is number of nodes

🧠 Space Complexity
O(n) recursive call stack
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Key idea
In a doubly linked list, every node has:
a next pointer
a prev pointer
Because of this, we can reverse the links of the current node immediately and still move forward safely.

Step-by-step approach
1️⃣ Handle base case
If the list is empty (head == NULL), nothing to reverse.
Return head.

2️⃣ Store the next node
Save head->next in a temporary pointer.
This is important because links will be swapped.

3️⃣ Reverse links at the current nod
Swap next and prev pointers of the current node.
After this:
prev points to the original next
next points to the original prev
This reverses the direction locally.

4️⃣ Identify the new head
After swapping, if head->prev == NULL,
this node was the original tail
it becomes the new head
Return this node.

5️⃣ Recurse forward
Move to the next node using head->prev
(because after swapping, prev holds the original next)
Call recursion and return its result so the new head propagates up the call stack.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

Node* reverseList(Node* head)
{
    if (head == NULL)
        return NULL;

    Node* nextNode = head->next;

    // swap next and prev
    head->next = head->prev;
    head->prev = nextNode;

    // if this is the new head
    if (head->prev == NULL)
        return head;

    // propagate new head upward
    return reverseList(head->prev);
}


*/

//___________________________________________________________________________________________________________________________________________
// About recursion
//___________________________________________________________________________________________________________________________________________

/*

1️⃣ Recursion shape depends on dependency
Singly LL → must wait → post-order recursion
Doubly LL → can act immediately → pre-order recursion

2️⃣ Return value in recursion has different roles
Sometimes it builds the solution (SLL)
Sometimes it only carries information (DLL)

3️⃣ Recursion ≠ “go to end first”
You learned that:
“go to end” is a requirement, not a rule
it exists only when current work depends on future work

4️⃣ Local vs deferred work
If local changes break traversal → defer (SLL)
If local changes preserve traversal → do now (DLL)
This insight applies far beyond linked lists.
*/
