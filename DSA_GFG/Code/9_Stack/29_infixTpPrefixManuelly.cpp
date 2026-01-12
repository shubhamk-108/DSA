/*
What is Prefix?

Prefix (Polish notation):

operator operand1 operand2


Example:

+ A B
* + A B C

🧠 Core Manual Idea (VERY IMPORTANT)

Prefix = operator written before its operands

So ask yourself repeatedly:
“Which operator will execute LAST?”
That operator goes FIRST in prefix.

This is the reverse thinking of postfix.

📜 Manual Rules (Memorize these)
Rule 1

Handle parentheses first

Rule 2

Within any expression:

Operator with lowest precedence executes last

That operator becomes the root → written first in prefix

Rule 3

Split expression around that operator:

(left expression)  operator  (right expression)


Convert left and right recursively

🧪 Example 1 (Very simple)
Infix
A + B


Last operation: +

Prefix
+ A B

🧪 Example 2 (Operator precedence)
Infix
A + B * C


+ has lower precedence than *

So + executes last

Split:

A   +   (B * C)


Convert right side:

* B C


Final prefix:

+ A * B C

🧪 Example 3 (Parentheses)
Infix
(A + B) * C


Parentheses force + first

So * executes last

Split:

(A + B)  *  C


Convert inside:

+ A B


Final prefix:

* + A B C

🧪 Example 4 (Multiple operators)
Infix
A + B * C - D

Step 1: Lowest precedence (last executed)

- is last (left to right for equal precedence)

Split:

(A + B * C)  -  D

Step 2: Convert left side
A + B * C


Lowest precedence here: +

Split:

A + (B * C)


Convert:

+ A * B C

Step 3: Combine
- + A * B C D

🧪 Example 5 (Power operator – IMPORTANT)
Infix
A ^ B ^ C


^ is right associative

So evaluation:

A ^ (B ^ C)


Split at the first ^:

A  ^  (B ^ C)


Convert right:

^ B C


Final prefix:

^ A ^ B C

🧪 Big Example (Confidence builder)
Infix
(A + B) * (C - D / E)

Step 1: Identify last operator

*

Split:

(A + B)   *   (C - D / E)

Step 2: Convert left
A + B → + A B

Step 3: Convert right
C - D / E


Lowest precedence: -

Split:

C  -  (D / E)


Convert:

- C / D E

Final Prefix
* + A B - C / D E

🧠 Mental Shortcut (VERY IMPORTANT)

Prefix = Preorder traversal of expression tree

If you imagine the expression tree:

Root → operator

Left subtree → left expression

Right subtree → right expression

Prefix is just:

root left right

*/