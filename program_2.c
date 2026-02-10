#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100


struct CharStack {
    char items[MAX];
    int top;
};

void initCharStack(struct CharStack* s) {
    s->top = -1;
}

int isCharStackEmpty(struct CharStack* s) {
    return s->top == -1;
}

void pushChar(struct CharStack* s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = c;
}

char popChar(struct CharStack* s) {
    if (isCharStackEmpty(s)) {
        return '\0';
    }
    return s->items[s->top--];
}

char peekChar(struct CharStack* s) {
    if (isCharStackEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}


struct IntStack {
    int items[MAX];
    int top;
};

void initIntStack(struct IntStack* s) {
    s->top = -1;
}

int isIntStackEmpty(struct IntStack* s) {
    return s->top == -1;
}

void pushInt(struct IntStack* s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = val;
}

int popInt(struct IntStack* s) {
    if (isIntStackEmpty(s)) {
        return 0;
    }
    return s->items[s->top--];
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}


void infixToPostfix(char* infix, char* postfix) {
    struct CharStack s;
    initCharStack(&s);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        
        else if (c == '(') {
            pushChar(&s, '(');
        }
        
        else if (c == ')') {
            while (!isCharStackEmpty(&s) && peekChar(&s) != '(') {
                postfix[k++] = popChar(&s);
            }
            popChar(&s); 
        }
        
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (!isCharStackEmpty(&s) && precedence(peekChar(&s)) >= precedence(c)) {
                postfix[k++] = popChar(&s);
            }
            pushChar(&s, c);
        }
    }

    while (!isCharStackEmpty(&s)) {
        postfix[k++] = popChar(&s);
    }
    postfix[k] = '\0';
}

int evaluatePostfix(char* postfix) {
    struct IntStack s;
    initIntStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            pushInt(&s, c - '0');
        } else {
            int val2 = popInt(&s);
            int val1 = popInt(&s);
            switch (c) {
                case '+': pushInt(&s, val1 + val2); break;
                case '-': pushInt(&s, val1 - val2); break;
                case '*': pushInt(&s, val1 * val2); break;
                case '/': pushInt(&s, val1 / val2); break;
                case '^': pushInt(&s, (int)pow(val1, val2)); break;
            }
        }
    }
    return popInt(&s);
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);

    return 0;
}
