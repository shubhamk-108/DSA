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
using namespace std;

class LRUCache
{
private:
    vector<pair<int, int>> vec;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        int value = -1;
        int i = 0;
        for (i; i < vec.size(); i++)
        {
            if (key == vec[i].first)
            {
                value = vec[i].second;
                break;
            }
        }
        if (value != -1)
        {
            vec.erase(vec.begin() + i);
            vec.push_back({key, value});
            return value;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        int i = 0;
        bool keyExist = false;
        for (i; i < vec.size(); i++)
        {
            if (key == vec[i].first)
            {
                keyExist = true;
                break;
            }
        }

        if (keyExist)
            vec.erase(vec.begin() + i);

        else if (!keyExist && capacity == vec.size())
            vec.erase(vec.begin());

        vec.push_back({key, value});
    }
};


//___________________________________________________________________________________________________________________________________________
// Intuition
//___________________________________________________________________________________________________________________________________________

/*
Big picture: What is LRU Cache really doing?
LRU = Least Recently Used
That means:
If I use something, it becomes important
If I don’t touch something for long, it becomes useless first
So the cache must always answer two questions:
Did I use this key recently?
Which key was used least recently?

Core Intuition (mental model)
Think of your cache as a queue of usage
[ LRU ............... MRU ]

Left side (front) → least recently used
Right side (back) → most recently used
Your vector is doing exactly this.
Why vector works conceptually
Even though vector is not optimal, it’s perfect for understanding:
Order is preserved
Front = old
Back = recent
So every operation becomes:
GET → “I used this, move it to the back”
PUT → “Insert new as most recent”
Overflow → “Remove from front”

Intuition behind get(key)
What does get mean logically?
“I just used this key, so it becomes the most recently used.”
Steps in your code:
Search for key
If not found → return -1
If found
Remove it from its current position
Insert it at the back
Why remove + push_back?

Because:
It might be in the middle or front
Back always represents most recently used

💡 Key intuition
Access = importance → move to back
Intuition behind put(key, value)
put has three scenarios.

Case 1: Key already exists
Cache: [ 1 , 2 , 3 ]
put(2, 20)


What does this mean?
Old value is useless
2 just became most recently used
So we:
Remove old (2, value)
Insert (2, newValue) at the back

💡 Intuition
Update = access → move to back

Case 2: Key does NOT exist & cache is full
Cache (capacity = 3):
[ 1 , 2 , 3 ]
put(4, 40)

Who should go?
1 → least recently used → front
So we:
Remove front
Insert new key at back

💡 Intuition
When space is needed, delete the oldest usage
Case 3: Key does NOT exist & cache has space
Just insert it at back.

💡 Intuition
New entries are always “recent”

*/
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

ime Complexity
Operation	Complexity
get()	    O(n) (linear search + erase)
put()	       O(n)
Space	    O(capacity)

Space Complexity
Uses a vector of at most capacity elements
No auxiliary data structures
✅ O(capacity)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We simulate an LRU (Least Recently Used) cache using a vector:
Each element in the vector stores {key, value}
Front of vector → Least Recently Used (LRU)
Back of vector → Most Recently Used (MRU)
Rules enforced:
GET
If key exists → return value and move it to MRU position
Else → return -1
PUT
If key exists → remove old entry
If key doesn’t exist and cache is full → evict LRU
Insert new (key, value) at MRU position


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class LRUCache
{
private:
    // Stores cache entries as {key, value}
    // Front = Least Recently Used
    // Back  = Most Recently Used
    vector<pair<int, int>> vec;

    // Maximum number of entries allowed
    int capacity;

public:
    // Constructor to initialize cache capacity
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    // Returns value if key exists, else -1
    int get(int key)
    {
        // Search for the key
        for (int i = 0; i < vec.size(); i++)
        {
            if (key == vec[i].first)
            {
                int value = vec[i].second;

                // Move accessed element to MRU position
                vec.erase(vec.begin() + i);
                vec.push_back({key, value});

                return value;
            }
        }
        // Key not found
        return -1;
    }

    // Inserts or updates the key-value pair
    void put(int key, int value)
    {
        bool keyExist = false;
        int i = 0;

        // Check if key already exists
        for (i = 0; i < vec.size(); i++)
        {
            if (key == vec[i].first)
            {
                keyExist = true;
                break;
            }
        }

        // If key exists, remove old entry
        if (keyExist)
            vec.erase(vec.begin() + i);

        // If key does not exist and cache is full, evict LRU
        else if (!keyExist && capacity == vec.size())
            vec.erase(vec.begin());

        // Insert new entry as MRU
        vec.push_back({key, value});
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
