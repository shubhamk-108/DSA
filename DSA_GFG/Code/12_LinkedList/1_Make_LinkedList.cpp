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

int main(){
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    cout<<head->data<<" "<<temp1->data<<" "<<temp2->data<<" ";
}

//___________________________________________________________________________________________________________________________________________
// Explanation
//___________________________________________________________________________________________________________________________________________

/*
Defining the Node structure
struct Node{
    int data;
    Node* next;

Each Node has:
data → stores the value (here, an int)
next → stores the address of the next node
This is what makes it a linked list.

3️⃣ Constructor of Node
    Node(int x){
        data=x;
        next=NULL;
    }
};

This constructor runs whenever you create a new node.
data = x → stores the value
next = NULL → initially, the node is not linked to anything

👉 So every new node starts as a standalone node.
4️⃣ Creating nodes in main()
Node *head = new Node(10);
Allocates memory on the heap

Creates a node with:
data = 10
next = NULL
head stores the address of this node

📌 head points to the first node of the linked list.
Node *temp1 = new Node(20);
Node *temp2 = new Node(30);

Now you have three separate nodes in memory:

head   → [10 | NULL]
temp1  → [20 | NULL]
temp2  → [30 | NULL]

At this moment, they are NOT linked yet.

5️⃣ Linking the nodes
head->next = temp1;
head->next now stores the address of temp1
temp1->next = temp2;

temp1->next now stores the address of temp2

Now the list looks like:
head
 ↓
[10 | • ] → [20 | • ] → [30 | NULL]


This is a singly linked list:
10 → 20 → 30 → NULL

6️⃣ Printing the data
cout << head->data << "-->"
     << temp1->data << "-->"
     << temp2->data;
This prints:
10-->20-->30

*/

//___________________________________________________________________________________________________________________________________________
// Question 1: usually we should have done Node head(10) but we didnt . is it wrong
//___________________________________________________________________________________________________________________________________________

/*


1️⃣ What if we write Node head(10);?
Node head(10);
This creates:
a Node object, not a pointer
stored on the stack
Memory looks like:
[ data=10 | next=NULL ]   ← head
To link nodes, you’d write:
Node temp1(20);
Node temp2(30);
head.next = &temp1;temp1.next = &temp2;

✔️ This works perfectly fine.
So no — it’s not wrong.

2️⃣ Then why do we usually write Node* head = new Node(10);?
Because linked lists are meant to be:
🔹 Dynamic in size
Nodes can be added/removed at runtime
Stack objects die when the function ends
Heap objects live until you delete them
👉 Using new gives you full control over lifetime.
🔹 Easier to manage with functions
Most linked list functions expect:
Node* head
Example:
void insert(Node*& head, int x);
If head were an object (Node head;), things get messy and restrictive.
🔹 Matches real-world implementations
In practice:
Nodes are created dynamically
Head is just a pointer to the first node
This avoids copying large objects
This is why textbooks and interviews almost always use:
Node* head = new Node(10);

3️⃣ Big conceptual difference (IMPORTANT)
Using object (Node head)
head is the node
Cannot easily change head itself
Limited flexibility
Using pointer (Node* head)
head points to the node
Head can be reassigned:
head = head->next;
Essential for deletion, insertion, reversing, etc.

4️⃣ What happens when main() ends?
| Method           | Memory               |
| ---------------- | -------------------- |
| `Node head(10);` | Auto-deleted (stack) |
| `new Node(10)`   | Stays until `delete` |


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
