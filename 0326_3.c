// Infix -> Postfix notation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_INPUT_SIZE 100

typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러r\n");
        return;
    }
    s->data[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러|n");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(StackType* s) {
    if (is_empty(s)) {
        return 0;
    }
    return s->data[s->top];
}

int Priority(char c) {
    switch (c) {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    default:
        return 0;
    }
}

int isOperator(char c) {
    switch (c) {
    case '(':
    case '+':
    case '-':
    case '*':
    case '/':
    case ')':
        return 1;
    default:
        return 0;
    }
}

int CmpPriority(char op1, char op2) {
    int priority1 = Priority(op1);
    int priority2 = Priority(op2);
    return priority1 - priority2;
}

int main() {
    StackType stack;
    init_stack(&stack);
    char input[MAX_INPUT_SIZE], tmp;
    int priority;

    printf("Enter infix notation expression you want to convert: ");
    scanf("%s", input);

    printf("Postfix notation: ");
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        char token = input[i];

        if (!isOperator(token)) {//if number -> just print
            printf("%c", token);
        }
        else if (token == '(') {//if ( the lowest operation
            while (!is_empty(&stack)) {//pop out All prev operations
                printf("%c", pop(&stack));
            }
            push(&stack, token);
        }
        else if (token == ')') {// if ) -> pop all operations except (
            while (!is_empty(&stack)) {
                tmp = peek(&stack);
                if (tmp == '(') {
                    pop(&stack);  // '(' Delete
                    break;
                }
                printf("%c", pop(&stack));
            }
        }
        else {//ordinary operation
            while (!is_empty(&stack)) {
                priority = CmpPriority(peek(&stack), token);
                if (priority >= 0) {
                    printf("%c", pop(&stack));
                }
                else {
                    break;
                }
            }
            push(&stack, token);
        }
    }

    //print all the leftovers
    while (!is_empty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");

    return 0;
}
