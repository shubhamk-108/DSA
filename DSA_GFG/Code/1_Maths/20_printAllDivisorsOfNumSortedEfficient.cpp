#include <iostream>
#include <cmath>
using namespace std;

class Divisors {
public:
    static void printFactors(int n) {
        int i;
        for (i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cout << i << " ";
            }
        }
        for (; i > 1;) 
        {
            i--;
            if (i != n / i && n % i == 0)
                cout << n / i << " ";
        }
    }
};

int main() {
    Divisors d;
    int n = 90 ;

    d.printFactors(n);

    return 0;
}

// Time Complexity: O(sqrt(n)) 

// Auxiliary Space: O(1)



// logic :
// first understand previous code's logic and then continue from here
// we have to print in sorted order so first loop prints all the prime divisors and that are already sorted.
// Now in second loop we continued from whatever i's value. Now i was already increamented at the most
// so i is larger and when i was at dinominator and was larger number, we get automatically sorted element.

// why the second loop is not standard. why we decremented i's value inside loop and not like standard practice.
// consider for n = 90. for i = 9 , i*i = 81 the loop will run but when i become 10 and i*i = 100 first loop will end.
// second loop will begin from i = 10 and 90/10= 9 which is valid but this 9 was already printed by first loop so it will repeat here
// that is why we decremented i manually inside loop.

// second loop meaning:
// for (int i = 0; i<n ; i--) {  code } . This code will run first and then at the end i will be decremented
// for (int i = 0; i<n ;) { i --  code } . here i will be decremented first and then remaining code will run