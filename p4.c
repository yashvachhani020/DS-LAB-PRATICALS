#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int isRightAssociative(char op) {
    return (op == '^');
}

void infixToPostfix(char *infix, char *postfix) {
    int i = 0, k = 0;
    char token, popped;

    while ((token = infix[i++]) != '\0') {

        if (isspace(token)) {
            continue;
        }

        if (isalnum(token)) {
            postfix[k++] = token;
        }

        else if (token == '(') {
            push(token);
        }
   
        else if (token == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); 
        }
 
        else {
            while (!isEmpty() && peek() != '(') {
                int precToken = precedence(token);
                int precTop = precedence(peek());

                if ((!isRightAssociative(token) && precTop >= precToken) ||
                    (isRightAssociative(token) && precTop > precToken)) {
                    postfix[k++] = pop();
                } else {
                    break;
                }
            }
            push(token);
        }
    }

    while (!isEmpty()) {
        popped = pop();
        if (popped != '(' && popped != ')') {
            postfix[k++] = popped;
        }
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an Infix Expression: ");
    if (fgets(infix, sizeof(infix), stdin) != NULL) {
        // Strip trailing newline
        size_t len = strlen(infix);
        if (len > 0 && infix[len - 1] == '\n') {
            infix[len - 1] = '\0';
        }

        infixToPostfix(infix, postfix);

        printf("\nOriginal Infix : %s\n", infix);
        printf("Postfix Form   : %s\n", postfix);
    }

    return 0;
}