
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

        vector<int> res(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            q.push(i);
        }

        sort(deck.begin(), deck.end());

        int i_deck = 0;

        while (!q.empty())
        {
            int idx = q.front();
            res[idx] = deck[i_deck];
            i_deck++;
            q.pop();
            if (!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
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

Time : 
sort : nlogn
Queue simulation (each index pushed & popped at most once): O(n)

Overall: nlogn

Space:
Result array: O(n)
Queue storing indices: O(n)

Therefore overall O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Key idea
Instead of simulating cards directly, we simulate positions using a queue.
Sort the deck so we place cards in increasing order
Use a queue to store indices 0 … n-1
Repeatedly:
Take the front index and place the next smallest card there
Move the next index in the queue to the back (simulates “move top card to bottom”)
Continue until all cards are placed
This exactly mirrors the problem’s reveal process.

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

        // Result array to store final deck order
        vector<int> res(n, 0);

        // Queue to simulate positions in the deck
        queue<int> q;

        // Push all indices into the queue
        for (int i = 0; i < n; i++)
        {
            q.push(i);
        }

        // Sort the deck so we place cards in increasing order
        sort(deck.begin(), deck.end());

        int i_deck = 0; // Index for sorted deck

        // Simulate the reveal process using indices
        while (!q.empty())
        {
            // Take the front position and place the next card
            int idx = q.front();
            q.pop();
            res[idx] = deck[i_deck];
            i_deck++;

            // Move the next position to the back (if any)
            if (!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }

        return res;
    }
};





*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Queue simulation
Reverse simulation
Greedy placement


*/
