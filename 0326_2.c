// Calculating postfix notation 

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX_STACK_SIZE 100
#define MAX_INPUT_SIZE 100

typedef int element;
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
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    s->data[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[s->top];
}

int isOperand(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int Calculator(int n1, int n2, char operator) {
    switch (operator) {
    case '+': return n1 + n2;
    case '-': return n1 - n2;
    case '*': return n1 * n2;
    case '/': return n1 / n2;
    default:
        fprintf(stderr, "잘못된 연산자: %c\n", operator);
        exit(1);
    }
}

int ParseInt(char c) {
    return c - '0';
}

int main(void) {
    StackType numbers;
    init_stack(&numbers);

    char input[MAX_INPUT_SIZE];
    printf("Enter postfix notation: ");
    scanf("%s", input);

    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        char token = input[i];

        if (!isOperand(token)) { // 숫자이면 push
            push(&numbers, ParseInt(token));
        }
        else { // 연산자이면 연산 수행
            int tmpN2 = pop(&numbers);
            int tmpN1 = pop(&numbers);
            int tmp = Calculator(tmpN1, tmpN2, token);
            push(&numbers, tmp);
        }
    }

    int result = pop(&numbers);
    printf("The result of the postfix notation: %d\n", result);

    return 0;
}
