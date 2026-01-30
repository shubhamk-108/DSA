/*
You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1. Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> res(n, 0);

        int i_deck = 0;
        bool skip = false;
        int j_res = 0;

        while (i_deck < n)
        {
            if (res[j_res] == 0)
            {
                if (skip == false)
                {
                    res[j_res] = deck[i_deck];
                    i_deck++;
                }
                skip = !skip;
            }

            j_res = (j_res + 1) % n;
        }

        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {17, 13, 11, 2, 3, 5, 7};
    vector<int> ans = sol.deckRevealedIncreasing(v);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Sorting
O(nlogn)
In the worst case, you may scan the array multiple times

Overall bounded by:
O(n^2)
	​
✅ Final Time Complexity
O(n^2)

But, 

In youtube video he says, 
isnt time is nlon only. Because when skipping we always feel half array that is n/2 and then next half of it that is n/4 and then n/8 
and so on . thus this give us log n and we are doing this n times so nlogn total and not n^2. 
I asked chatgpt and it said that n^2 is correct. But keep in mind both.
	​

🧠 Space Complexity
Result array: O(n)

No extra data structures
O(n)
	​


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Core idea
Instead of using an explicit queue, you:
Sort the deck (smallest card revealed first)
Simulate the reveal + skip process using:
A result array res
A skip flag that alternates between:
placing a card
skipping a position
How it works conceptually
The smallest card is revealed first → place it
Next position is skipped (simulating “move top card to bottom”)
Repeat this process in a circular manner
Continue until all cards are placed
This is a manual simulation of queue behavior using an array.

Important note (for interviews)
This line:
if (res[j_res] == 0)
Works only because LC950 guarantees deck[i] ≥ 1.
In an interview, you should say:
“I’m using 0 as a sentinel value because the problem guarantees all card values are positive.”
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();

        // Sort the deck so we place cards in increasing order
        sort(deck.begin(), deck.end());

        // Result array, initialized with 0 (used as empty marker)
        vector<int> res(n, 0);

        int i_deck = 0;     // Index for sorted deck
        bool skip = false; // Controls reveal / skip behavior
        int j_res = 0;     // Circular index for result array

        // Continue until all cards are placed
        while (i_deck < n)
        {
            // Only act on empty positions
            if (res[j_res] == 0)
            {
                // If not skipping, place the next smallest card
                if (skip == false)
                {
                    res[j_res] = deck[i_deck];
                    i_deck++;
                }

                // Toggle skip to simulate reveal / move-to-bottom
                skip = !skip;
            }

            // Move circularly through result array
            j_res = (j_res + 1) % n;
        }

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern Used
Simulation
Circular traversal

*/
