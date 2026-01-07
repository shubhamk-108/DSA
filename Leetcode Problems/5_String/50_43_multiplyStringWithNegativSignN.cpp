
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>


// This code is same as leetcode 43, just that this code also handles the negative numbers or string. So to understand this code see file no 48.
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        // Step 1: Handle signs. Dont assign true false, insted flip the sign. It elegantly handles the cases.

        bool isAnswerNegative = false;
        if (num1[0] == '-')
        {
            isAnswerNegative = !isAnswerNegative;
            num1 = num1.substr(1);
        }
        if (num2[0] == '-')
        {
            isAnswerNegative = !isAnswerNegative;
            num2 = num2.substr(1);
        }

        int n1 = num1.length();
        int n2 = num2.length();

        // Step 2: Handle zero case
        if (num1 == "0" || num2 == "0")
            return "0";

        // Step 3: Perform multiplication using vector
        vector<int> res(n1 + n2, 0);

        for (int i = n2 - 1; i >= 0; i--)
        {
            for (int j = n1 - 1; j >= 0; j--)
            {
                int digit1 = num2[i] - '0';
                int digit2 = num1[j] - '0';

                int product = digit1 * digit2;
                int unit_place_position = i + j + 1;
                int carry_place_position = i + j;

                int new_sum = product + res[unit_place_position];
                res[unit_place_position] = new_sum % 10;
                res[carry_place_position] += new_sum / 10;
            }
        }

        // Step 4: Build final string
        string final_res = "";
        int i = 0;
        while (i < res.size() && res[i] == 0)
            i++;

        for (; i < res.size(); i++)
            final_res += (res[i] + '0');

        if (final_res.empty())
            return "0";

        // Step 5: Add negative sign if needed
        if (isAnswerNegative)
            final_res = "-" + final_res;

        return final_res;
    }
};

int main()
{
    Solution sol;
    string num1 = "-12";
    string num2 = "-4";
    cout << sol.multiply(num1, num2);

    return 0;
}


// logic and timespace

// This code is same as leetcode 43, just that this code also handles the negative numbers or string. So to understand this code see file no 48.
