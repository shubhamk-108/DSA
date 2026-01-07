/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.
Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"

*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<string> numString(n);
        for (auto const &x : nums)
            numString.push_back(to_string(x));

        sort(numString.begin(), numString.end(), [](const string &a, const string &b)
             { return a + b > b + a; });

        string ans;
        for (const auto &x : numString)
            ans += x;

        if (ans[0] == '0')
        {
            return "0";
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 30, 34, 5, 9};

    cout << sol.largestNumber(nums);
    return 0;
}

// time and space

/*

Complexity Analysis
Time Complexity: O(N * K * logN)

Let N be the number of integers in the input vector nums.
Let K be the average number of digits (length of the string) for the numbers.
Conversion: Converting N numbers to strings takes O(N * K) time.
Sorting: The sort function performs O(N log N) comparisons. Each comparison involves string concatenation (a + b), which takes O(K) time. 
Therefore, the total time for sorting is O(N * K * logN).
Concatenation: Joining the sorted strings takes O(N * K) time.
The dominant operation is sorting, making the overall time complexity O(N * K * logN).

Space Complexity: O(N * K)
We create a vector<string> to store the string representation of each number. This requires O(N * K) space.
The final ans string also takes O(N * K) space.


*/
// code

/*

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        // If the input vector is empty, return an empty string.
        if (nums.empty()) {
            return "";
        }

        int n = nums.size();
        vector<string> numString;
        // Reserve space for n strings to avoid multiple reallocations.
        numString.reserve(n);

        // Convert each integer to its string representation.
        for (const auto &x : nums)
        {
            numString.push_back(to_string(x));
        }

        // Sort the strings using a custom comparison lambda.
        // This comparator ensures that for any two numbers 'a' and 'b',
        // if 'a' followed by 'b' (a+b) is larger than 'b' followed by 'a' (b+a),
        // 'a' is placed before 'b' in the sorted sequence.
        sort(numString.begin(), numString.end(), [](const string &a, const string &b)
             { return a + b > b + a; });

        string ans;
        // Concatenate the sorted strings to form the largest possible number.
        for (const auto &x : numString)
        {
            ans += x;
        }

        // Handle the edge case where the largest number starts with '0'.
        // This happens if the input contains only zeros, e.g., [0, 0].
        // In this case, the result should be "0", not "00".
        if (ans[0] == '0') {
            return "0";
        }

        return ans;
    }
};


*/




// seperate explanation for 
// sort(numString.begin(), numString.end(), [](const string &a, const string &b)
            //  { return a + b > b + a; });


/*

1. sort(numStrings.begin(), numStrings.end(), ...);
std::sort is a function in <algorithm>.
It sorts a range of elements: here from the first element (numStrings.begin()) to the one past the last (numStrings.end()).
Normally, sort arranges elements in ascending order, using < operator by default.
But here we provide our own rule (a comparator) to tell it how to order the elements.
2. [](string &a, string &b) { return a + b > b + a; }
This is a lambda function (an anonymous function). Let’s break it:
[] → capture list: empty here, meaning the lambda doesn’t capture any variables from outside.
(string &a, string &b) → parameters: it takes two string& references (the two elements being compared during sort).
{ return a + b > b + a; } → function body: it concatenates a+b and b+a, and returns true if a+b is greater.
So this lambda is the custom comparator given to sort.
a and b are just the two elements that std::sort is currently comparing.
Question: so it is only sorting it and not giving concanated result like 9534330 insted it only sorts like numStrings = ["9", "5", "34", "3", "30"]
ChatGPT said:
Exactly ✅ — you’ve got it.

*/


// Question 

/*

are both same.
vector<string> numString(n);
numString.reserve(n);

Answer:

1. vector<string> numStrings(n);
This creates a vector of size n.
It actually constructs n string objects inside the vector.
After this, numStrings.size() == n.
Each element is default-initialized (empty string "" in this case).
1. vector<string> numStrings(n);
This creates a vector of size n.
It actually constructs n string objects inside the vector.
After this, numStrings.size() == n.
Each element is default-initialized (empty string "" in this case).
vector<string> v(6);
v.reserve(12);
size() → 6 (still 6 actual elements)
capacity() → at least 12 (enough space to grow without reallocating)


*/