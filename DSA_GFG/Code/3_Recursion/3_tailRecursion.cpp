// Tail recursion is a special kind of recursion where the recursive call is the last operation in the function 
// — meaning there’s nothing left to do after the recursive call returns.

//  Normal Recursion vs Tail Recursion
// Let’s understand by an example.

// 🚫 Normal Recursion (Not Tail Recursive)

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);  // Multiplication happens after recursion
}
// After calling factorial(n - 1), it has to multiply the result by n. So it waits.
// This is not tail recursion.


// ✅ Tail Recursion

int tailFactorial(int n, int result = 1) {
    if (n == 0) return result;
    return tailFactorial(n - 1, n * result);  // Recursive call is the LAST operation
}
// No operation after recursive call.

// All results are passed along as parameters.

// This is tail recursive.
// Why is Tail Recursion Useful?
// In languages that support Tail Call Optimization (TCO), tail recursive functions are converted into loops by the compiler.
// This avoids stack overflow errors and is memory efficient.
