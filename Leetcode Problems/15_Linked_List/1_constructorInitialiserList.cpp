// what is constructor initialiser. Explained in this file.
// Linkedlist's constructor is made using this specially on platform like leetcode.

// Linked list constructor using constructior initialiser

// Definition for singly-linked list.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nextNodeAddress) : val(x), next(nextNodeAddress) {}
};


/*

1️⃣ What is this code overall?
struct ListNode
{
    int val;
    ListNode *next;


This defines a struct (used heavily on platforms like LeetCode) for a singly linked list node.
Each node has:
val → data
next → pointer to next node

2️⃣ The part that looks unfamiliar 👇
ListNode() : val(0), next(nullptr) {}
This is a constructor with an initializer list.
🔹 Constructor
A constructor is a special function that runs when an object is created.
🔹 Initializer list (: val(0), next(nullptr))
This initializes data members before the constructor body runs.

Equivalent (but worse style) code:

ListNode() {
    val = 0;
    next = nullptr;
}
Initializer lists are:
Faster
Mandatory for const and reference members
Preferred modern C++ style

3️⃣ All three constructors explained

✅ 1. Default constructor
ListNode() : val(0), next(nullptr) {}
Used when:
ListNode node;
Result:
val = 0
next = nullptr

✅ 2. Constructor with value
ListNode(int x) : val(x), next(nullptr) {}
Used when:
ListNode node(5);
Result:
val = 5
next = nullptr

✅ 3. Constructor with value + next pointer
ListNode(int x, ListNode *next) : val(x), next(next) {}
Used when:
ListNode* node2 = new ListNode(10);
ListNode* node1 = new ListNode(5, node2);
Result:
node1.val = 5
node1.next = node2

4️⃣ Why does next(next) look weird?
ListNode(int x, ListNode *next) : val(x), next(next) {}
Left side → member variable
Right side → constructor parameter
Same as:
this->next = next;


Another Example:

ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3)));


but this creates list reverse. i mean list is straight but we need to create 2nd node before first. this is strange.
ListNode* node2 = new ListNode(10);
ListNode* node1 = new ListNode(5, node2);

we can use either nested version or link them explicitely.
Version 2 (nested)
ListNode* head = new ListNode(5, new ListNode(10));

✔ Version 3 (explicit linking)
ListNode* node1 = new ListNode(5);
ListNode* node2 = new ListNode(10);
node1->next = node2;


*/