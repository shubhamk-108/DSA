// Prerequisite for Rabin Karp Algorithm

// 1. How to calculate exponential term

/*

If we have to calcualte 2^8 then do like this

int ans = 1;

for (int i = 0; i < 8; i++)
{
    ans = 2 * ans;
}


*/


// 2. Incremental exponential

/*

We can do like 2^8 operation but that will be very computationally expensive. We need this in pattern searching. And what if we are 
searching for a pattern of 5000 length then it will become something^5000.
So in this case we should use for incremental exponential.

suppose pattern = bac then patten[i] will be b, a, and c.
d is the base value that we multiply to each character pattern[i] as it is needed in hashing. 
int p = 0;


for (i = 0; i < m; i++)
    {
        p = d * p + pattern[i];
    }

for hashing the pattern suppose abc we do like this. Consider base as 31. 31^2 * 1 + 31^1 * 2 + 31^0 * 3. 


Start with p = 0.

First character:
p = (d * 0 + pattern[0]) % q = pattern[0]

Second character:
p = (d * p + pattern[1]) % q
→ p = d*pattern[0] + pattern[1]

Third character:
p = (d * (d*pattern[0] + pattern[1]) + pattern[2])
→ p = d^2*pattern[0] + d*pattern[1] + pattern[2]

Fourth character:
→ p = d^3*pattern[0] + d^2*pattern[1] + d*pattern[2] + pattern[3]

…and so on.




// 3. Negative Modulo

t = (d * (t - text[i] * h) + text[i + m]) % q;

t - text[i] * h can be negative (because we’re subtracting the old char’s contribution).
When you then take % q in C++, the result may also be negative (unlike in math, where modulo always gives a positive remainder).
(-5) % 101 = -5   // in C++

Why not just flip the sign?

Suppose t = -5.
If we just “flip the sign”: t = 5.
But the mathematical equivalent of -5 mod 101 is actually 96, not 5.
(Why? Because -5 + 101 = 96, and 96 ≡ -5 (mod 101).)
So just changing the sign would give the wrong hash value.


Why add q?

When t is negative:
t = (t + q);

This shifts it back into the valid range [0, q-1].

Example: if t = -5,
t + q = -5 + 101 = 96 ✅ correct remainder.
That’s why we add q instead of just flipping the sign.
*/