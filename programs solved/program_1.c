#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 100
struct stack{
    char items[max];
    int top;

};
void initStack(struct stack* s) {
    s->top = -1;
}
void push(struct stack* s , char c)
{
    if (s->top ==max-1){
        printf("stack overflow\n");
        return;
    }
    s->top++;
    s->items[s->top]=c;
}
char pop(struct stack* s)
{
    if(s->top==-1){
        printf("stack underflow\n");
        return '\0';
    }
    char c=s->items[s->top];
    s->top--;
    return c;

}
int isempty(struct stack* s)
{
    if(s->top==-1){
        return 1;
    }
    else return 0;
}
int ispair(char left , char right)
{
    if(left=='(' && right == ')') return 1;
    if(left=='{' && right == '}') return 1;
    if(left=='[' && right == ']') return 1;
    return 0;
}
int isbalanced(char *exp)
{
    struct stack s;
    initStack(&s);
    for (int i = 0; exp[i] != '\0'; i++) {
       
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&s, exp[i]);
        }
       
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isempty(&s)==1) {
                return 0;
            }
            char topChar = pop(&s);
            if (ispair(topChar, exp[i])==0) {
                return 0;
            }
        }
    }
    return isempty(&s);
    
}

int main(){
    char* testCases[] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };
    
    for (int i = 0; i < 3; i++) {
        printf("Expression: %s\n", testCases[i]);
        if (isbalanced(testCases[i])==1) {
            printf("Result: Balanced\n");
        } else {
            printf("Result: Unbalanced\n");
        }
        printf("\n");
    }
    return 0;
}
