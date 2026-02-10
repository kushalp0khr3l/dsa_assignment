
# Documentation for program_2.c

Write a program to convert an infix mathematical expression to postfix and evaluate it.

(a) Data structures: `MAX` buffer, `CharStack { items[], top }` for operators, `IntStack { items[], top }` for evaluation.

(b) Key functions:
- `infixToPostfix(infix, postfix)` — converts infix → postfix (handles parentheses and operator precedence).
- `evaluatePostfix(postfix)` — evaluates postfix using an integer stack.
- stack helpers: `pushChar`, `popChar`, `peekChar`, `pushInt`, `popInt`, `precedence`.

(c) main(): reads expression with `scanf("%s", infix)`, converts, prints postfix and evaluation result.

Limitations: single-digit operands only, integer division, minimal error checking, `^` uses `pow()` cast to int.

(d) Sample run:
Input: `3+4*2`
Output:
```
Enter infix expression Postfix Expression: 342*+
Evaluation Result: 11
```


