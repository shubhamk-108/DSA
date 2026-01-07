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

        for (int i = 0; i < minutes; i++)
        {
            if (grumpy[i] == 1)
                customerThatCanBeSatisfied += customers[i];
        }
        windowCustomers = max(windowCustomers, customerThatCanBeSatisfied);
       
        int left = 0;
        int right = minutes;
        for (right; right < n; right++)
        {
            if (grumpy[left] == 1)
                customerThatCanBeSatisfied -= customers[left];

            if (grumpy[right] == 1)
                customerThatCanBeSatisfied += customers[right];

            windowCustomers = max(windowCustomers, customerThatCanBeSatisfied);

            left++;
        }

        return windowCustomers + happyCustomers;
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

Time Complexity
O(n)

Space Complexity
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Goal:
Maximize satisfied customers by using the boss’s “not-grumpy” technique for exactly minutes consecutive minutes.
A customer is satisfied if:
grumpy[i] == 0 → always satisfied
grumpy[i] == 1 → satisfied only if inside the chosen window of size minute
Step 1 — Count already satisfied customers
Loop through customers:
 If grumpy[i] == 0, add customers[i] to happyCustomers
These customers are always satisfied, no matter what.
Step 2 — Use Sliding Window (Fixed Size = minutes)
Goal: Find the window that covers the maximum number of grumpy (1) customers, because those are the ones we can convert to satisfied.
Build the first window [0 … minutes-1]
Add customers[i] only when grumpy[i] == 1
Slide window:
Remove left value (if grumpy=1)
Add right value (if grumpy=1)
Track maximum sum → windowCustomers
Step 3 — Final Answer
Add:
customers always satisfied
customers satisfied due to technique in best window
return happyCustomers + windowCustomers;



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
        
        // 1. Customers already satisfied (grumpy = 0)
        int happyCustomers = 0;
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
                happyCustomers += customers[i];
        }

        // 2. Customers that can become satisfied during the secret technique
        int customerThatCanBeSatisfied = 0;
        int windowCustomers = 0;

        // Build first window of size `minutes`
        for (int i = 0; i < minutes; i++)
        {
            if (grumpy[i] == 1)
                customerThatCanBeSatisfied += customers[i];
        }
        windowCustomers = max(windowCustomers, customerThatCanBeSatisfied);

        // 3. Slide the window
        int left = 0;
        for (int right = minutes; right < n; right++)
        {
            if (grumpy[left] == 1)
                customerThatCanBeSatisfied -= customers[left];

            if (grumpy[right] == 1)
                customerThatCanBeSatisfied += customers[right];

            windowCustomers = max(windowCustomers, customerThatCanBeSatisfied);

            left++;
        }

        // Total satisfied = always-happy + best possible rescued customers
        return windowCustomers + happyCustomers;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Sliding Window – Fixed Size Window
Because:
Window size = minutes is constant.
You slide from left → right.
You update the window incrementally.


*/
