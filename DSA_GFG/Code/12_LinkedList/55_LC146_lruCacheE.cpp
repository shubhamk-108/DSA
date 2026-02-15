/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of
keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

What is LRU Cache Design?
Cache acts as a temporary storage layer between the central processing unit (CPU) and the main memory (RAM), providing faster access to frequently
used data.

The Last Recently Used (LRU) cache design is a popular algorithmic approach used to manage cache memory in computer systems. It aims to
maximize cache hit rates by evicting the least recently used items when the cache becomes full.

The LRU cache design maintains a fixed-size cache that stores frequently accessed data or resources. Each item in the cache has a key-value pair.
When an item is accessed (read or written), it is moved to the front of the cache, indicating that it is the most recently used item. On the other
hand, when the cache is full and a new item needs to be added, the least recently used item, located at the end of the cache, is evicted to make
room for the new item.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class LRUCache
{
private:
    int capacity;
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> um;

    void bringKeyToFront(int key)
    {
        dll.erase(um[key].first);
        dll.push_front(key);
        um[key].first = dll.begin();
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (um.find(key) == um.end())
            return -1;

        bringKeyToFront(key);
        return um[key].second;
    }

    void put(int key, int value)
    {
        if (um.find(key) != um.end())
        {
            bringKeyToFront(key);
            um[key].second = value;
            return;
        }
        if (dll.size() == capacity)
        {
            int lruKey = dll.back();
            dll.pop_back();
            um.erase(lruKey);
        }

        dll.push_front(key);
        um[key] = {dll.begin(), value};
    }
};

//___________________________________________________________________________________________________________________________________________
// Intuition
//___________________________________________________________________________________________________________________________________________

/*

🌱 The Core Intuition (in one line)
LRU Cache is about answering one question efficiently:
“Which key was used most recently, and which was used least recently?”
Everything in the code exists only to answer that question in O(1) time.
🧠 Why a normal data structure fails
Let’s say you use:

only an unordered_map
❌ You can find keys fast, but you don’t know which is least recently used
only a list
❌ You know order, but searching is O(n)
So the intuition becomes:
We need fast lookup AND fast reordering
That’s the birth of this idea:
unordered_map  +  doubly linked list

🧩 Mental Model (very important)
Think of the cache like this:

[ MOST RECENT ]  <---->  [ LEAST RECENT ]
        ↑                         ↑
      front                     back

Rule of the universe:
Any key that is used (get/put) becomes MOST RECENT
When cache is full, remove LEAST RECENT

🔑 Why list?
Because in a doubly linked list:
delete a node → O(1) (if you have iterator)
insert at front → O(1)
delete last node → O(1)
This perfectly matches LRU rules.

🔑 Why unordered_map?
Because:
we must jump to a node instantly
so we store:
key → { iterator to list node, value }
This avoids searching the list.

🧠 Intuition of each part (conceptual)
1️⃣ dll (list)
list<int> dll;
Intuition
This list is NOT data storage.
It is only an ordering of usage.
“Who was used last? Who was used least?”

2️⃣ unordered_map
unordered_map<int, pair<list<int>::iterator, int>> um;
Intuition
For every key, we must know:
where it is in the list (iterator)
what value it stores
So we never traverse the list.

3️⃣ bringKeyToFront()
void bringKeyToFront(int key)
Intuition
Any access = “this key is important again”
So we:
remove it from wherever it was
put it at the front (MRU)
This maintains the LRU invariant:
Front = most recently used
Back = least recently used

4️⃣ get(key)
int get(int key)
Intuition
If key doesn’t exist → return -1
If it exists:
mark it as recently used
return value
Getting a key is also usage.

5️⃣ put(key, value)
This function has three real-world cases:

Case 1: Key already exists
“Update value + refresh usage”
So:
move key to front
update value
stop

Case 2: New key, cache is full
“Someone must be forgotten”

Who?
➡ Least recently used → back of list
So:
remove back
erase from map

Case 3: Insert new key
“New key becomes most important”
So:
push to front
store iterator + value in map

*/


//___________________________________________________________________________________________________________________________________________
// List in c++ stl
//___________________________________________________________________________________________________________________________________________

/*
What is std::list in C++ STL?
std::list is a doubly linked list container provided by the C++ Standard Library.

#include <list>
list<int> dll;

Each element (node) contains:
data
pointer to previous node
pointer to next node

🧠 Internal Structure (conceptual)
NULL ←→ [10] ←→ [20] ←→ [30] ←→ NULL

This structure allows fast insertion and deletion when you already know the node.
🚀 Key Characteristics of std::list

1️⃣ Doubly linked by default
Every node has prev and next
Guaranteed by the C++ standard
📌 Not to confuse with:
forward_list  // singly linked list

2️⃣ Non-contiguous memory
Nodes are scattered in memory
❌ No index-based access
dll[2]; // ❌ INVALID

3️⃣ Supports bidirectional iteration
You can move:
forward: ++it
backward: --it
❌ Random access not allowed (it + 3 invalid)

⏱️ Time Complexity (VERY IMPORTANT)
Operation	Time
push_front()	O(1)
push_back()	O(1)
pop_front()	O(1)
pop_back()	O(1)
erase(it)	O(1)
insert(it, x)	O(1)
Search	O(n)

📌 Key condition: erase/insert is O(1) only if iterator is known

🔥 Iterator behavior
auto it = dll.begin();
++it;   // OK
--it;   // OK
it + 1; // ❌ ERROR


Because list iterators are bidirectional, not random-access.

🧹 Erase behavior
dll.erase(it);

Deletes the node pointed by it
O(1) operation
Only that iterator becomes invalid

📌 Compare with vector:
vector erase → O(n)
list erase → O(1)
❗ Important limitations
❌ No direct indexing
❌ Extra memory overhead (2 pointers per node)
❌ Cache-unfriendly (scattered memory)

🟢 When should you use std::list?
Use std::list when:
You need frequent insertions/deletions
You already have iterators
Order matters
Example problems:
LRU Cache
Undo/Redo
Playlist navigation

🔴 When NOT to use std::list
Avoid std::list when:
You need random access
You mostly traverse sequentially
Cache locality matters
Use vector instead.

*/



//___________________________________________________________________________________________________________________________________________
// Some important details about list.
//___________________________________________________________________________________________________________________________________________

/*

---- Point No 1: 

std::list in STL is doubly linked by default. ✅
Why this is guaranteed
In C++, the container:
std::list<T>
is defined by the standard as a doubly linked list.
That means every node has:
a pointer to the next node
a pointer to the previous node
So operations like:
push_front
push_back
erase(it)
pop_back
pop_front
are all O(1) when you already have an iterator.
How this matters for your LRU cache
Your LRU solution depends on this property:
dll.erase(um[key].first);  // O(1)
This is only possible because:
std::list is doubly linked
the iterator directly points to the node
If list were singly linked, this would be impossible in O(1).
Quick comparison (important)

| Container           | Type               | Can erase in O(1) with iterator? |
| ------------------- | ------------------ | -------------------------------- |
| `std::list`         | Doubly Linked List | ✅ Yes                            |
| `std::forward_list` | Singly Linked List | ❌ No                             |
| `std::vector`       | Dynamic Array      | ❌ No (shifts elements)           |
| `std::deque`        | Block Array        | ❌ No (middle erase expensive)    |

---- Point No 2

1️⃣ vector::erase

vec.erase() takes an iterator, not a value
Example:
vec.erase(vec.begin() + i);
Time Complexity: O(n)
(elements after the erased position must be shifted)
Reason: vector is a contiguous array



--- point No 3

2️⃣ unordered_map::erase
mp.erase(key) takes a key directly
No iterator is required
Average Time Complexity: O(1)
Reason: hash table → direct bucket access


--- point no 4 

3️⃣ list::erase
list.erase(it) takes an iterator (node address)
Time Complexity: O(1) if iterator is known
Reason: doubly linked list → no shifting


--- point no 5

5️⃣ Why it - 1 works for vector but not for list

vector iterators are random access
vec.begin() + 3  // valid
it - 1           // valid


list iterators are bidirectional
++it, --it       // valid
it + 1, it - 1   // ❌ INVALID because random access is not possible in list unlike vector.


📌 That’s why:
dll.erase(it - 1);  // ❌ error


--- point no 6

6️⃣ end() is NOT a valid element
For all STL containers:
end() points past the last element
You must do:
auto it = container.end();
--it; // now points to last element


--- point no 7

7️⃣ Why LRU requires list, not forward_list
forward_list (singly linked):
❌ Cannot erase in O(1) without previous node
list (doubly linked):
✅ Can erase in O(1) using iterator
📌 That’s why std::list is mandatory for optimal LRU.


7️⃣ --- point no 8

to store address in the map we can store it like this. list<int>::iterator
like unordered_map<int, pair<list<int>::iterator, int>> um;
But then this will not store address directly. we have to tell address like dll.begin().
for this map, it will be, um[key].first = dll.begin() for first node's address
*/



//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time & Space Complexity
Time

get() → O(1)
put() → O(1)

Space
O(capacity)
(list + hashmap store at most capacity elements)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

LRU Cache needs two things at the same time:
Fast access by key → unordered_map
Fast update of recent usage order → list (DLL)
Core idea
Most Recently Used (MRU) → front of list
Least Recently Used (LRU) → back of list

So:
get(key) → move key to front
put(key, value):
if key exists → update + move to front
if new key & full → remove back (LRU)
insert new key at front


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class LRUCache
{
private:
    int capacity;

    // Doubly linked list stores keys in usage order
    // Front = Most Recently Used
    // Back  = Least Recently Used
    list<int> dll;

    // Map: key -> {iterator to list node, value}
    unordered_map<int, pair<list<int>::iterator, int>> um;

    // Moves an existing key to the front (MRU position)
    void bringKeyToFront(int key)
    {
        dll.erase(um[key].first);   // remove from old position
        dll.push_front(key);        // move to front
        um[key].first = dll.begin();// update iterator
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        // Key not found
        if (um.find(key) == um.end())
            return -1;

        // Mark key as most recently used
        bringKeyToFront(key);
        return um[key].second;
    }

    void put(int key, int value)
    {
        // Case 1: key already exists
        if (um.find(key) != um.end())
        {
            bringKeyToFront(key);
            um[key].second = value;
            return;
        }

        // Case 2: cache full → evict LRU
        if (dll.size() == capacity)
        {
            int lruKey = dll.back();
            dll.pop_back();
            um.erase(lruKey);
        }

        // Case 3: insert new key
        dll.push_front(key);
        um[key] = {dll.begin(), value};
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
