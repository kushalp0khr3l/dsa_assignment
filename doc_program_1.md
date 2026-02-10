# Documentation for program_1.c

This program implements a parenthesis matching checker using a stack data structure in C.

##  Explanation of Data Structures

### struct stack
The core data structure used in this program is a **Stack**, implemented using a structure. 
- **char items[max]**: An array of characters to store the opening brackets. **max** is defined as 100.
- **int top**: An integer variable to keep track of the index of the top element in the stack. It is initialized to -1, indicating an empty stack.

##  Description of Functions

-  __void initStack(struct stack* s)__ : Initializes the stack by setting its **top** member to -1.
- __void push(struct stack* s, char c)__ : Adds a character **c** to the top of the stack. It checks for stack overflow before incrementing top.
- __char pop(struct stack* s)__ : Removes and returns the top character from the stack. It checks for stack underflow and returns \0 if the stack is empty.
- **int ispair(char left, char right)**: Checks if the **left** character (opening bracket) matches the right character (closing bracket). Returns 1 if they match, 0 otherwise.
- **int isbalanced(char *exp)**: The main logic for checking if an expression is balanced. It iterates through the string, pushing opening brackets onto the stack and popping/matching when closing brackets are encountered.
- **int main()**: The entry point of the program.



## The main() function is organized as follows:
1.  **Declaration**: An array testCases is declared and initialized with a string containing various brackets: "{}[]()".
2.  **Logic**: It calls the isbalanced() function, passing the testCases string as an argument.
3.  **Output**: Based on the return value of isbalanced() (1 for balanced, 0 for unbalanced), it prints either "balanced" or "not balanced" to the console.

##  Sample Output

```
Expression: a + (b - c) * (d  
Result: Unbalanced

Expression: m + [a - b * (c + d * {m)]
Result: Unbalanced

Expression: a + (b - c)
Result: Balanced
```

