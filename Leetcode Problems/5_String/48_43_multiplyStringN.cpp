/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

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
    string multiply(string num1, string num2)
    {

        int n1 = num1.length();
        int n2 = num2.length();

        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        vector<int> res(n1 + n2, 0);

        for (int i = n2 - 1; i >= 0; i--)
        {
            for (int j = n1 - 1; j >= 0; j--)
            {
                int digit1 = num2[i] - '0';
                int digit2 = num1[j] - '0';

                int product = digit1 * digit2;

                int unit_place_position = i + j + 1;
                int carry_position = i + j;

                int new_sum = product + res[unit_place_position];

                res[unit_place_position] = new_sum % 10;
                res[carry_position] += new_sum / 10;
            }
        }

        string final_res = "";
        int i = 0;
        while (i < res.size() && res[i] == 0)
            i++;

        for (; i < res.size(); i++)
        {
            final_res += res[i] + '0';
        }
        return final_res.empty() ? "0" : final_res;
    }
};

int main()
{
    Solution sol;
    string num1 = "986";
    string num2 = "-24";
    cout << sol.multiply(num1, num2);
    return 0;
}

// ___________________________________________________________________________________________________________________________


// timespace

/*'

Time Complexity: O(M * N)
Space Complexity: O(M + N)

m and n and n1 and n2
*/


// ___________________________________________________________________________________________________________________________


// code 



/*


// This is same as our multiplication that we did in school.
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        // Edge case: if one of the numbers is "0", the product is "0".
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        int n1 = num1.length();
        int n2 = num2.length();

        vector<int> res(n1 + n2, 0);

        for (int i = n2 - 1; i >= 0; i--)
        {
            for (int j = n1 - 1; j >= 0; j--)
            {
                // extracting digits from string
                int digit1 = num2[i] - '0';
                int digit2 = num1[j] - '0';

                // multiply those digits just like we did in school
                int product = digit1 * digit2;

                // these are the positions on unit place digit and carry after multiplication. suppose 4*6 = 24. Then here 4 is unit place digit
                // and 2 is the carry. So to put them in our vector we have to find their position in the res vector. so these are that positions.
                // how i found them. For ex - 456 * 239 then very first digit multiplication 9*6 will go to very last place and very second last
                // place in vector. so here n1+n2 = 3+3 = 6. 6 size vector from 0-5 index. So i will be 2 and j will be 2,1,0. so i+j = 2*2 = 4
                // so 4 is the carry position and i + j + 1 = 4+1 = 5 is the unit place position. and so on. and this works for everything.
                int unit_place_position = i + j + 1;
                int carry_position = i + j;

                // Sum the new product with any existing value (a carry from the previous position)
                // in the result vector at that position.
                // Now we dont have any problem to the very first digit multiplication but afte that for next digit multiplication there will
                // be previous digit's multiplication values present in the res vector. So we will have new carry and new unit place position.
                // so we add that existing value to the new multication value. Then we extract its unit place position by doing % and we 
                // extract its carry by dividing by 10.
                int new_sum = product + res[unit_place_position];

                // then we will have new sum after doing above operation. Now carry and unit place digit both will change. But unit place digit
                // will get overwritten that is why = sign below. But the whatever the new carry we have to add that carry to existing value present
                // there. That is why += sign below. Because if we get carry as 7 then we dont discard existing value and place 7 there insted but
                // we add that carry to the exisiting value.
                // The new unit digit is the remainder of the sum.
                res[unit_place_position] = new_sum % 10;
                // The carry is added to the next position to the left.
                res[carry_position] += new_sum / 10;

                // And the new_sum and then changing unit place digit and carry, all this because of -
                //  we are directly adding our final result to the res vector. we are managing our intermediate steps in between directly.
                // for ex : 347 * 514 then in manual multiplication we do multiply fitst 7,4,3 to 4. Then we will have one answer. Then
                // we skip one block like putting 0 to the very right block. and again we multiply 7,4,3 by 1 then again we get new answer.
                // then again we put two zeros and multiply 7,4,3 by 5. And after that we add all three results. 
                // But here we are managing this intermediate steps in that new_sum operation by adding existing value then and there and 
                // by updating new unit digit and new carry.
            }
        }

        string final_res = "";
        int i = 0;
        // Skip any leading zeros in the result vector.
        while (i < res.size() && res[i] == 0)
            i++;

        // Build the final string from the numbers in the vector.
        for ( i starts from where the last loop left off ; i < res.size(); i++)
        {
            final_res += res[i] + '0';
        }

        // This handles cases like "0" * "0" where the string would be empty.
        return final_res.empty() ? "0" : final_res;
    }
};


*/

// ___________________________________________________________________________________________________________________________


// dyr run



/*


let’s do a full dry run of your code for

num1 = "348"
num2 = "627"

Initial Setup
num1 = "348", num2 = "627"

n1 = 3, n2 = 3

The if condition is false.

res is created: std::vector<int> res(6, 0); which is {0, 0, 0, 0, 0, 0}.

Outer Loop: i = 2 (for num2[2], which is '7')
Inner Loop 1: j = 2

digit1 = 7, digit2 = 8

product = 56

unit_place_position = 2 + 2 + 1 = 5

carry_position = 2 + 2 = 4

new_sum = 56 + res[5] -> 56 + 0 = 56

res[5] = 56 % 10 -> 6

res[4] += 56 / 10 -> res[4] is 0 + 5 = 5

res: {0, 0, 0, 0, 5, 6}

Inner Loop 2: j = 1

digit1 = 7, digit2 = 4

product = 28

unit_place_position = 2 + 1 + 1 = 4

carry_position = 2 + 1 = 3

new_sum = 28 + res[4] -> 28 + 5 = 33

res[4] = 33 % 10 -> 3

res[3] += 33 / 10 -> res[3] is 0 + 3 = 3

res: {0, 0, 0, 3, 3, 6}

Inner Loop 3: j = 0

digit1 = 7, digit2 = 3

product = 21

unit_place_position = 2 + 0 + 1 = 3

carry_position = 2 + 0 = 2

new_sum = 21 + res[3] -> 21 + 3 = 24

res[3] = 24 % 10 -> 4

res[2] += 24 / 10 -> res[2] is 0 + 2 = 2

res: {0, 0, 2, 4, 3, 6}

Outer Loop: i = 1 (for num2[1], which is '2')
Inner Loop 4: j = 2

digit1 = 2, digit2 = 8

product = 16

unit_place_position = 1 + 2 + 1 = 4

carry_position = 1 + 2 = 3

new_sum = 16 + res[4] -> 16 + 3 = 19

res[4] = 19 % 10 -> 9

res[3] += 19 / 10 -> res[3] is 4 + 1 = 5

res: {0, 0, 2, 5, 9, 6}

Inner Loop 5: j = 1

digit1 = 2, digit2 = 4

product = 8

unit_place_position = 1 + 1 + 1 = 3

carry_position = 1 + 1 = 2

new_sum = 8 + res[3] -> 8 + 5 = 13

res[3] = 13 % 10 -> 3

res[2] += 13 / 10 -> res[2] is 2 + 1 = 3

res: {0, 0, 3, 3, 9, 6}

Inner Loop 6: j = 0

digit1 = 2, digit2 = 3

product = 6

unit_place_position = 1 + 0 + 1 = 2

carry_position = 1 + 0 = 1

new_sum = 6 + res[2] -> 6 + 3 = 9

res[2] = 9 % 10 -> 9

res[1] += 9 / 10 -> res[1] is 0 + 0 = 0

res: {0, 0, 9, 3, 9, 6}

Outer Loop: i = 0 (for num2[0], which is '6')
Inner Loop 7: j = 2

digit1 = 6, digit2 = 8

product = 48

unit_place_position = 0 + 2 + 1 = 3

carry_position = 0 + 2 = 2

new_sum = 48 + res[3] -> 48 + 3 = 51

res[3] = 51 % 10 -> 1

res[2] += 51 / 10 -> res[2] is 9 + 5 = 14. We just store 14 for now.

res: {0, 0, 14, 1, 9, 6}

Inner Loop 8: j = 1

digit1 = 6, digit2 = 4

product = 24

unit_place_position = 0 + 1 + 1 = 2

carry_position = 0 + 1 = 1

new_sum = 24 + res[2] -> 24 + 14 = 38

res[2] = 38 % 10 -> 8

res[1] += 38 / 10 -> res[1] is 0 + 3 = 3

res: {0, 3, 8, 1, 9, 6}

Inner Loop 9: j = 0

digit1 = 6, digit2 = 3

product = 18

unit_place_position = 0 + 0 + 1 = 1

carry_position = 0 + 0 = 0

new_sum = 18 + res[1] -> 18 + 3 = 21

res[1] = 21 % 10 -> 1

res[0] += 21 / 10 -> res[0] is 0 + 2 = 2

res: {2, 1, 8, 1, 9, 6}

Final Conversion to String
The for loops are complete. The res vector holds {2, 1, 8, 1, 9, 6}.

final_res is initialized to "".

The while loop runs to skip leading zeros. i starts at 0. res[0] is 2, which is not 0. The loop does not execute. i remains 0.

The final for loop starts with i=0.

final_res += res[0] + '0' -> "2"

final_res += res[1] + '0' -> "21"

final_res += res[2] + '0' -> "218"

final_res += res[3] + '0' -> "2181"

final_res += res[4] + '0' -> "21819"

final_res += res[5] + '0' -> "218196"

final_res is not empty, so the code returns "218196".




*/


// ___________________________________________________________________________________________________________________________