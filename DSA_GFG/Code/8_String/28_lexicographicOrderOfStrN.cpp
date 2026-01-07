/*
The lexicographic rank of a string is the position of the string in the sorted list of all its permutations (dictionary order).
Example 1
👉 Input: "STRING"
All permutations of "STRING" (there are 6! = 720) arranged in dictionary order.
The rank of "STRING" is 598.
Example 2
👉 Input: "ABC"
All permutations sorted:
ABC
ACB
BAC
BCA
CAB
CBA
Here, "ABC" is 1st, "ACB" is 2nd, "BAC" is 3rd, etc.


---
suppose we have given string nkra so we have to find where does it lexicographically come at positin. (basically alphabeical sequence number in short)

Take one example: rank

Imagine you have to create a dictionary of all possible unique arrangements (permutations) of the letters in "rank". The lexicographical rank is
simply the position of the word "rank" in that alphabetically sorted dictionary.
The algorithm is a clever way to count how many words come before "rank" in this dictionary without actually writing the whole dictionary out.
Let's look at the process step-by-step to understand the "why".

1. The First Character: 'r'
The Question We're Asking: How many words in our dictionary start with a letter that comes before 'r'?
Why this matters: In a dictionary, all words starting with 'a' come before any word starting with 'b'. The first letter is the most important for
sorting. Any permutation of "rank" that starts with a letter smaller than 'r' is guaranteed to come before "rank".
countRight (The number of smaller characters):
The letters available are 'r', 'a', 'n', 'k'.
The letters smaller than 'r' are 'a', 'n', and 'k'.
So, countRight = 3. This tells us there are three groups of words that will appear before "rank":
All words starting with 'a'.
All words starting with 'n'.
All words starting with 'k'.
The Factorial (3!) (The size of each group):
Let's take the first group: words starting with 'a'. If we fix 'a' as the first letter, we have three remaining letters ('r', 'n', 'k') to arrange
in the three remaining spots.
How many ways can you arrange 3 distinct letters? The answer from mathematics is 3! (3 * 2 * 1 = 6).
This means there are 6 words that start with 'a', 6 words that start with 'n', and 6 words that start with 'k'.
Putting it together (countRight * factorial):
We have 3 groups of smaller starting letters, and each group contains 3! words.
Total words that come before "rank" based on the first letter = 3 * 3! = 18.
At this point, we have counted all permutations like "aknr", "ankr", "knar", etc., and we know they all come before "rank".

2. The Second Character: 'a'
The Question We're Asking: We have now "locked in" 'r' as the first letter. Among all words that start with 'r', how many come before "rank"? To
answer this, we look at the second letter. A word "r***..." will come before "rank" if its second letter is smaller than 'a'.
countRight:
We have already used 'r'. The remaining letters are 'a', 'n', 'k'.
Are any of these letters smaller than our target second letter, 'a'? No.
Therefore, countRight = 0. There are no groups of words starting with 'r' that come before "rank" due to the second letter.
The Factorial (2!):
If there had been a smaller letter, we would have fixed it. After fixing the first two letters, we would have 2 spots left to fill. The number
of ways to arrange the 2 remaining letters is 2!.Putting it together:
The number of words we add to our count is 0 * 2! = 0. This makes sense. We can't make a word that starts with 'r' and is lexicographically smaller than "rank" if the second letter is 'a' or greater.

3. The Third Character: 'n'
The Question We're Asking: We have now locked in "ra". Among all words that start with "ra", how many come before "rank"? We look at the third letter.
countRight:
We have used 'r' and 'a'. The remaining letters are 'n' and 'k'.
Which of these is smaller than our target third letter, 'n'? 'k' is smaller.
Therefore, countRight = 1. This means there is one group of words we must count: words that start with "rak".
The Factorial (1!):
If we fix the prefix as "rak", we have one letter left ('n') to fill one spot.
The number of ways to arrange 1 letter is 1! = 1.
Putting it together:
We add 1 * 1! = 1 to our count. This single permutation is "rakn", which we have now correctly accounted for as coming before "rank".
In summary, the countRight identifies how many smaller options you had at each position, and the factorial calculates how many unique words you
could have created for each of those smaller options. By summing these up, you systematically count every single permutation that would appear
earlier in a dictionary.
Putting it t

There are 19 unique permutations of the letters 'r', 'a', 'n', 'k' that come before "rank" in alphabetical order.
"rank" itself is the very next one in the sequence, so it appears at the 20th position.


YOu must have understood the maths part so now lets understand the logic behind it.

see the first letter in rank is r.
lets fix r at the first position and now we want to find that how many permutations are there before rank.

put r : r _ _ _ . THere are 3 slots vacant there. Now we have 3 letters a,n,k and to put there in the slots, we can fill slots in 3! ways.
3! = 6. THat is
ank
akn
nak
nkn
kan
kna
Now what we want? we want that all of them come before rank word. i.e. before letter r. So where we can put r.
obviously we can not put r in the very beginning because that way all of them become greater than r but we want smaller than r.
so we can pur r in below posiiton.

a (here) n (here) k (here). in ank
we can put r whereever i have written here.

that is to ank,akn, nak, nkn, kan, kna for every permutation we have 3 possibilities. so 3 * 6 = 18 or 3 * 3!
where is this 3! come from. 3 ! we calculated by : if we take r as first letter then how many of the subsequent letters are smaller than r.
a, n, k all were smaller than r.

by doing this we will have something like this:
arnk, anrk, ankr
arkn, akrn, aknr
nrak, nark, nakr
nkn ...
kan ...
kna ...

= 3! * 3 or 6 * 3
That is this many works are before rank

Now the next step is:

we have fixed r at first position now consider that we have pur a in rank in the second position. i.e. r a _ _ .
r a _ _ . Means we have two vacant slots that can be filled in 2! ways. And how many of subsequent letters are smaller than a. zero.
Therefore 0 * 2! = 0. Add this 0 to above 18. 18 + 0 = 19

Now the next step is

r a n _ .
We can fill this empty slot in 1! ways. And there are 1 samller letter after n that is k.
Therefore 1! * 1 = 1. Add this 1 to above 18.

18 + 0 + 1 = 19.

Next step:

r a n k . There are no slots to filled . So 0 slots can be filled in 0 ways = 0! = 1. And how many letters are smaller after k. None.
Therefore 1* 0 = 0. Add this 0 to above 19.
18 + 0 + 1 + 0 = 19.

That means there are 19 words before the word rank and the rank comes at 20th position. So our answer is 20.

---

Now some additional logic:

If we have word rank then length of rank is 4. SO there are 4! ways = 24 ways of total permutations possible.

So these were the 20 permutations we saw. SO what are the remaining. By now you must have got that if the word rank is given then
we are finding all the words or possible permutations that are occured before the word rank.

Again if r is fixed at first then we remain with 3. a, n, k. these 3 have total permtations of 3! = 6.
ank
akn
nak
nkn
kan
kna
Now we want all those which have appered after word rank. (This is not the part of question, i am only telling you because it is
necessary to understand overall logic)
Now if we want greater than word rank means r must be at 1st position. So all the other permutations we saw before will be smaller than
rank and now we are finding remaining permutaitons.

(here) ank : rank : this has already been covered in question above.
(here) akn : rakn. This also appear before rank alphabetically. So this has also been covered already.
(here) nak : remaining permutation
(here) nkn : remaining permutation
(here) kan : remaining permutation
(here) kna : remaining permutation

r can be put (here).


*/

#include <bits/stdc++.h>

using namespace std;
int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}
void populatecount(int *count, char *str)
{
    // store the characters smaller than this in the count array
    for (int i = 0; i < strlen(str); i++)
        count[str[i]]++;
    for (int i = 1; i < 256; i++)
        count[i] += count[i - 1];
}
void updatecount(int *count, char ch)
{
    // after using a charcater , we need to decrease its count , so that the smaller
    // elements in the right can be calculated correctly.
    for (int i = ch; i < 256; i++)
        count[i]--;
}
int findRank(char *str)
{
    int len = strlen(str);
    int mul = fact(len);
    int rank = 1;
    int count[256] = {0}; // first initialised with 0
    populatecount(count, str); // populating the count
    for (int i = 0; i < len; i++)
    {
        mul /= len - i;
        rank += count[str[i] - 1] * mul; // getting the rank
        updatecount(count, str[i]);      // updating the count of str[i] in the count array
    }
    return rank;
}
int main()
{
    char str[] = "cba";
    cout << "Lexiographic rank is: " << findRank(str);
    return 0;
}