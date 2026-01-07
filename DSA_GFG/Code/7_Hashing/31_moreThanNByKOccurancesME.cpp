// THis algo is Misra-Gries Summary. It's a direct extension of the simpler Boyer-Moore Majority Vote Algorithm.

// 31_moreThanNByKOccurancesME here last ME means more efficient.
// The Problem Statement
// "Given an array of N integers and an integer K, find all the unique elements in the array that appear more than N/K times."
// The Misra-Gries / Boyer-Moore Extended Method (O(N) time, O(K) space)
// YOu have to solve this problem which is already solved in previous two code files but here you have to solve this in O(k) time

// { 30, 10, 20, 20, 10, 20, 30, 30}, n = 8 , k = 4 , n/k = 2 That is we have to find the number which is occuring 3 or more than 3 times
// Therefore op = 20 30

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void printMoreThanNByKOccurances(int arr[], int n, int k)
{

    unordered_map<int, int> um;

    for (int i = 0; i < n; i++)
    {
        if (um.find(arr[i]) != um.end())
            um[arr[i]]++;

        else if (um.size() < k - 1)
            um[arr[i]] = 1;
        else
        {
            for (auto it = um.begin(); it != um.end();)
            {
                it->second--;
                if (it->second == 0)
                    it = um.erase(it);

                else
                    it++;
            }
        }
    }

    for (auto &r : um)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (r.first == arr[i])
                count++;
        }
        if (count > (n / k))
            cout << r.first << " ";
    }
}

int main()
{
    int arr[] = {30, 10, 20, 20, 20, 10, 40, 30, 30, 10};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    printMoreThanNByKOccurances(arr, n, k);

    return 0;
}

// -----------------------------------------------------------------------------------------------------

// Time and space:

/*

The Correct (Amortized) Analysis: O(N)
Time Complexity: O(N * k) is the Worst Case, but O(N) is the Amortized Case
This is the tricky part. It's easy to look at the nested loops and assume the worst.
The Naive (Worst-Case) Analysis: O(N * k)
The outer loop runs N times (once for each element in the array).
The inner "cancellation" loop (for (auto it = m.begin()...) runs only when the map is full and a new element arrives.
In the absolute worst case, this inner loop has to iterate over all k-1 elements in the map.
If this worst-case cancellation happens for every single element in the array, the complexity would seem to be O(N * k).
The Correct (Amortized) Analysis: O(N)

Space Complexity: O(k)

*/

// -----------------------------------------------------------------------------------------------------

// Questions and answer

/*


_____________________________________________________________________________________________________________
Question 0
_____________________________________________________________________________________________________________

Misra-Gries or extension of the simpler Boyer-Moore Majority Vote Algorithm.

Answer:

This is a significantly more advanced and less intuitive approach than the simple sorting or hash map solutions we discussed. The goal of this
algorithm is to solve the problem in O(N) time while using only O(k) extra space, which is a huge improvement over the O(N) space your previous
hash map solution used.
Let's break down how it works. It's a two-pass algorithm.
Pass 1: Finding the Candidates
This is the first for loop, and it's the core of the algorithm. Its goal is to identify up to k-1 candidates that might be the elements appearing
more than n/k times.
The logic is based on a "vote cancellation" idea:
The Map's Role: The unordered_map m does not store the true frequency. Instead, it stores a list of current candidates and their "scores" or "votes".
The size of this map is strictly limited to be less than k (specifically, at most k-1 elements).
Processing an Element arr[i]:
if (m.find(arr[i]) != m.end()): If the current element is already a candidate in our map, we increment its score. It gets another vote.
else if (m.size() < k - 1): If the element is not a candidate, but we still have empty slots in our map (i.e., fewer than k-1 candidates), we
add it as a new candidate with a score of 1.
else: This is the most important step. If the element is not a candidate and our map is already full (with k-1 candidates), we can't add it.
So, we perform a "cancellation" step:
We decrement the score of every single candidate currently in the map.
If any candidate's score drops to 0, we remove them from the map.
Why does this work? Think of it like this: if you have k distinct numbers (arr[i] and the k-1 candidates in the map), it's guaranteed that
none of them can be a majority element in that specific group. By decrementing all their scores, you are effectively canceling them all out.
An element that appears frequently will survive this cancellation process many times, while infrequent elements will be quickly added and then
removed.
At the end of this first pass, the map m contains a small list of "survivor" elements. These are the only possible candidates for elements
that appear more than n/k times. It's not guaranteed that they do, but it's guaranteed that no other element can.
Pass 2: Verifying the Candidates
This is the second for loop. The first pass only gave us a list of potential suspects. Now we need to confirm their guilt.
For each candidate x.first that survived Pass 1:
We reset a count to 0.
We do a full scan of the original array to get the true frequency of that candidate.
If its true frequency is greater than n/k, we print it.

_____________________________________________________________________________________________________________
Question 1
_____________________________________________________________________________________________________________
Why we have only allowing k-1 elements in the map or hash. That is why m.size() < k - 1

Answer:

Suppose n is 13 and k is 4 then n/k is 3.25 means element can be our answer if it occurs at least 4 times.
So lets say elements are :
1 1 1 1
2 2 2 2
3 3 3 3
4
Observe that our answer will be 1,2 and 3. That means total 3 values. THat is  our answer is at most k-1 = 4-1 = 3. Means 3 elements at max
can be your answer.
Now this will continue till we have n = 15 and k =4. Because as soon as n becomes 16 then n/k becomes 4 and in that case
our answer will be that element which occurs at least 5 times.

So now if we have n = 16 and k = 4 then n/k = 4 . i.e. we need 5 occurances of element to be the answer. So
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4

See we again have 3 answers 1,2, and 3. Means we will get at most k-1 answer. i.e. here we got 3 different elements as answer.


_____________________________________________________________________________________________________________
Question 2
_____________________________________________________________________________________________________________
Why decrement all the values of elements  present in the hashmap. i.e. code is else part

Answer:
Because when we get the new element when we are traversing array then we check if it is already present, if yes then increment count.
Second if hash is empty then directly insert element. And thirdly if first two conditions fail then we try to decrement all to see
if any spot become empty then we can put that element there on that emptied spot.
So how we are preserving answer here. The idea is that if we have some element occuring many time then decrementing it
will not affect its presence because at the end of the day that element will still have some count so that we can comapare at the end.
But the those elements which does not occur a low of time , say 1 time 2 time (based on n and k, here 1 and 2 is just for example)
and if other elements are occuring 3 4 times then those elements who have appeared one or two time they will get decremented and
they will get out of hashmap when they become zero after decrementing. On the contrary those who appear more time they will preserve there
space there in hash map. (Read Next question . Next quesiton is the follow up question of this). And the elements which stays even at the
end will be the potential candidate that they can be the n/k occuring elements. So we again run another loop and check them if they really
occured more that n/k times.
It is like  survival of the fittest"
You can also say that: we are checking if element has already occured, if is there space in hashmap to store element. If both condions
are false then we are decrementing all the elements because we can not store that element because we dont have space so it is like
we are not storing that element means we are not considering that vote. And if we are not considering that vote then we also
have to decrement other elements that is other votes so that there is a fair game of voting.
Jr tya element la apan hash map madhe yeun nahi dil tr baki saglya element la pn 1 ne decrement karayach. Ani as decrement karun
pn jo survive karel toch potentially winning candidate asel jyala aapan pudhe jaun parat check krnar aahot.

_____________________________________________________________________________________________________________
Question 3
_____________________________________________________________________________________________________________
what we are doing if we dont find that element already existing in the map, we dont have more space to store that element in
map and after decrementing none element having value as zero so that we can discard that. so such element get ignore or what

Answer:

You're asking about this specific scenario:
A new element arr[i] arrives.
It's not already a candidate in the map m.
The map m is full (size is k-1).
We perform the cancellation step (decrement all counters).
After decrementing, no counter drops to zero, so no space is freed up.
So, what happens to the new element arr[i]?
It gets ignored.
That's it. It doesn't get stored, its count isn't tracked, it's simply discarded for that turn.
Why is it Okay to Ignore It?
This seems strange and lossy, but it's the core magic of the algorithm. When this situation occurs, you have a group of k distinct elements:
The k-1 candidates already in your map.
The new element arr[i].
By decrementing the counters of the k-1 elements in the map and simultaneously not adding the new element, you are effectively "canceling out" this
entire group of k distinct items. You are treating it as a block where each of the k different items appeared once, and you've conceptually
removed that block from the stream.
The Guarantee: The mathematical proof behind the Misra-Gries algorithm guarantees that even with this "ignoring" step, any element that truly
appears more than n/k times will have a positive counter and will remain in the map at the end of the first pass.
So, in short: Yes, the element gets ignored


*/

// -----------------------------------------------------------------------------------------------------

// logic:

/*

void printNByK(int arr[], int n, int k)
{
    // The map stores at most k-1 candidates and their current scores.
    std::unordered_map<int, int> m;

    // --- PASS 1: Find potential candidates ---
    for (int i = 0; i < n; i++)
    {
        // If the element is already a candidate, increment its score.
        if (m.find(arr[i]) != m.end())
        {
            m[arr[i]]++;
        }
        // If there is space for a new candidate, add it with a score of 1.
        else if (m.size() < k - 1)
        {
            m[arr[i]] = 1;
        }
        // If the map is full, decrement all candidates' scores.
        else
        {
            // --- CORRECTED CANCELLATION LOOP ---
            // Use an explicit iterator to safely erase while looping.
            // for (auto it = um.begin(); it != um.end(); it++)
            // The increment it++ happens automatically at the end of every single iteration.
            // This is fine if you are just reading from the map. But it's dangerous if you are deleting from it.
            // The Problem with erase: When you call um.erase(it), the iterator it that you pass in becomes invalidated. It's now a 
            // dangling pointer to memory that is no longer part of the map. If you were to use it again (for example, by letting the loop try 
            // to automatically increment it), your program would have undefined behavior and likely crash.
            // The erase Solution: The C++ erase function for maps is designed to solve this exact problem. When you call it, it safely 
            // deletes the element and then returns a new, valid iterator that points to the element after the one you just deleted.


            for (auto it = m.begin(); it != m.end(); ) // no increment here
            {
                it->second--; // Decrement the score of the current candidate.
                if (it->second == 0)
                {
                    // If score is 0, erase the element and the erase() function
                    // returns an iterator to the next valid element.
                    it = m.erase(it);
                }
                else
                {
                    // If not erased, manually move to the next element.
                    ++it;
                }
            }
        }
    }

    // --- PASS 2: Verify candidates and print ---
    // At this point, 'm' holds the only possible candidates.
    // We must now count their true frequency in the original array.
    for (auto &p : m)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (p.first == arr[i])
            {
                count++;
            }
        }

        if (count > n / k)
        {
            std::cout << p.first << " ";
        }
    }
}



*/