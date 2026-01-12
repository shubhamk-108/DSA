/*

Information about stack

In C++ STL, stack is not implemented as a separate data structure from scratch.
It is implemented as a container adapter.

1️⃣ What does “container adapter” mean?
A container adapter means:
stack uses another STL container internally and restricts its interface to behave like a stack (LIFO).
So STL stack does not store data itself — it wraps another container.

Why deque is chosen by default?
Because deque suports:
push_back() → O(1)
pop_back() → O(1)
back() → O(1)
No reallocation issues like vector

Question:
wasnt vector better choice to build stack but cpp used deque

Yes — vector looks perfect for stack

Stack needs only:

push_back

pop_back

back

And vector supports all of these in amortized O(1).

So logically, you’re right:

Vector can implement a stack efficiently

2️⃣ Then why didn’t STL choose vector? 🤔
🔴 Problem 1: Reallocation issue

vector stores elements in contiguous memory.
When capacity is full:
It allocates new memory
Copies/moves all elements
Frees old memory
Even though amortized O(1) is acceptable, STL prefers strict O(1) guarantees where possible.
📌 deque never reallocates the entire container.



*/