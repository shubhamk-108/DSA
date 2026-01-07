/*
There is a bookstore owner that has a store open for n minutes.
You are given an integer array customers of length n
where customers[i] is the number of the customers that enter the store at the start of the ith minute
and all those customers leave after the end of that minute.
During certain minutes, the bookstore owner is grumpy.
You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.
When the bookstore owner is grumpy, the customers entering during that minute are not satisfied. Otherwise, they are satisfied.
The bookstore owner knows a secret technique to remain not grumpy for minutes consecutive minutes, but this technique can only be used once.
Return the maximum number of customers that can be satisfied throughout the day.

Example 1:

Input: customers = [1,0,1,2,1,1,7,5],
          grumpy = [0,1,0,1,0,1,0,1], minutes = 3

Output: 16

Explanation:

The bookstore owner keeps themselves not grumpy for the last 3 minutes.

The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

You are given:

customers[i] → number of customers entering the bookstore at minute i

grumpy[i] →

0 → owner is not grumpy, customers are satisfied

1 → owner is grumpy, customers are unsatisfied

minutes → duration of a special technique that can make the owner not grumpy for minutes consecutive minutes

Your goal:

👉 Choose one continuous window of length = minutes
where you turn the grumpy owner to NOT grumpy
so that the total number of satisfied customers becomes maximum.

🎯 What Counts as Satisfied?
Customers are satisfied if:

Owner is NOT grumpy (grumpy[i] == 0) → always satisfied

Owner is grumpy (grumpy[i] == 1) → but you apply the special technique on that minute → they become satisfied

You can only apply the technique once, and it lasts for exactly minutes length.

📌 Restating the Goal

Maximize:

(naturally satisfied customers) + (extra customers satisfied by using the technique)
📘 Example to Understand
customers = [1, 0, 1, 2, 1, 1, 7]
grumpy    = [0, 1, 0, 1, 0, 1, 0]
minutes = 3

Step 1: Natural satisfaction

Only where grumpy = 0:

Index	grumpy	customers	satisfied?
0	0	1	yes
1	1	0	no
2	0	1	yes
3	1	2	no
4	0	1	yes
5	1	1	no
6	0	7	yes

Naturally satisfied = 1 + 1 + 1 + 7 = 10

Step 2: Extra satisfaction by using technique

We choose one window of size 3.

Check each possible window:

Window [0..2]: extra = customers where grumpy = 1 → only index 1 → extra = 0
Window [1..3]: extra = customers at index 1 + 3 → extra = 0 + 2 = 2
Window [2..4]: extra = customers at index 3 → extra = 2
Window [3..5]: extra = customers at index 3 + 5 → 2 + 1 = 3
Window [4..6]: extra = customers at index 5 → 1

Best extra = 3 (window starting at index 3)

customers = [1,0,1,2,1,1,7,5]
This means:
Minute 0 → 1 customer came
Minute 1 → 0 customers came
Minute 2 → 1 customer came
Minute 3 → 2 customers came
Minute 4 → 1 customer
Minute 5 → 1 customer
Minute 6 → 7 customers
Minute 7 → 5 customers

And here owner was not grumpy for minutes consecutive minutes, and here min was 3. That means owner was not grumpy for 3 min.
So we have to find those 3 min like is it min 1,2,3 or min 3,4,5 or min 5,6,7, etc such a that its happy customer count is maximum.

so in sliding window we have to find maximum num of customers who were not satisfied and who has potential to get satisfied

Final answer
natural + best extra = 10 + 3 = 13

🧠 What the Problem Really Is

This problem is a:

✔ Sliding Window
✔ Max sum of customers in windows where grumpy=1
✔ Add to natural satisfaction

You are basically finding the window where converting grumpy minutes gives the largest possible benefit.

🚀 In One Line

Choose a window of length minutes that maximizes the number of grumpy customers inside it, add that to the naturally satisfied customers, and return the total.



*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        int happyCustomers = 0;
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
                happyCustomers += customers[i];
        }

        int windowCustomers = 0;
        int customerThatCanBeSatisfied = 0;

        for (int i = 0; i <= n - minutes; i++)
        {
            customerThatCanBeSatisfied = 0;
            for (int j = i; j < i + minutes; j++)
            {
                if (grumpy[j] == 1)
                    customerThatCanBeSatisfied += customers[j];
            }
            windowCustomers = max(windowCustomers, customerThatCanBeSatisfied);
        }


        return happyCustomers + windowCustomers;
    }
};

int main()
{
    Solution sol;
    vector<int> c = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> g = {0, 1, 0, 1, 0, 1, 0, 1};
    cout << sol.maxSatisfied(c, g, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
O(n × minutes)

Because for every starting index i, you loop for minutes steps to calculate the window.

Worst-case: minutes = n, so
→ O(n²)

💾 Space Complexity
O(1)

Only u

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


First count all customers who are already satisfied (grumpy[i] == 0).
These customers always contribute to the result.
Now, for every possible window of size minutes, compute:
how many additional customers can be satisfied (those where grumpy[i] == 1 inside the window)
Track the maximum such "potential satisfied customers" window.
Final answer =
happyCustomers (already satisfied)+ windowCustomers (best window of angry → satisfied customers)

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();

        // Count customers who are already satisfied (grumpy == 0)
        int happyCustomers = 0;
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
                happyCustomers += customers[i];
        }

        int windowCustomers = 0; // will store max customers that can be additionally satisfied
        int customerThatCanBeSatisfied = 0;

        // Try every window of size "minutes"
        for (int i = 0; i <= n - minutes; i++)
        {
            customerThatCanBeSatisfied = 0; // reset for current window

            // Count customers in the window who were unsatisfied but can be satisfied by using technique
            for (int j = i; j < i + minutes; j++)
            {
                if (grumpy[j] == 1)
                    customerThatCanBeSatisfied += customers[j];
            }

            // Keep track of best window
            windowCustomers = max(windowCustomers, customerThatCanBeSatisfied);
        }

        // Total satisfied = originally satisfied + best window of potentially satisfied customers
        return happyCustomers + windowCustomers;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force + Sliding Window (Non-optimized)


*/
