



/*


Efficient / Optimized Algorithms (Beyond Brute Force)

“This is the classical grade-school O(n×m) solution, which is optimal for Leetcode constraints.
For larger numbers (like in big integer libraries), faster algorithms such as Karatsuba or FFT can be used to achieve sub-quadratic complexity.”

These are not required in interviews unless you’re in advanced rounds or research / comp-sci-heavy roles,
but still, here’s what exists:
1. Karatsuba Algorithm

2. FFT (Fast Fourier Transform) Multiplication
Represent numbers as polynomials
This is how Python’s int or C++ big integer libraries multiply internally when numbers are very large (e.g., 10⁵ digits).

3.Toom-Cook and Schönhage-Strassen
Even faster and used in libraries like GMP, but very complex

*/