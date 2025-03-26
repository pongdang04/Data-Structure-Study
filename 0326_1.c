// Parentheses Checking Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX_STACK_SIZE 100
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
        return 0;
    }
    return s->data[s->top];
}

void PrintError(int n) {
    if (n == 1) {
        printf("괄호의 쌍이 맞지 않습니다\n");
    }
    else if (n == 2) {
        printf("괄호의 포함관계가 맞지 않습니다\n");
    }
}

int isOpening(char c) {
    if (c == '(' || c == '{' || c == '[') {
        return 1;
    }
    else
        return 0;
}

int isMatching(char open, char close) {
    if ((open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']')) {
        return 1;
    }
    else
        return 0;
}

int main() {
    char a[MAX_STACK_SIZE];
    int i, length;
    StackType s;

    init_stack(&s);

    printf("Enter String: ");
    scanf("%s", a);
    length = strlen(a);

    for (i = 0; i < length; i++) {
        char ch = a[i];

        if (isOpening(ch)) {//if opening of the bracket -> push
            push(&s, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {//if closing of the bracket
            if (is_empty(&s)) {//nothing to match
                PrintError(1);
                return 0;
            }

            char top = pop(&s);
            if (!isMatching(top, ch)) {//compare Matching
                PrintError(2);
                return 0;
            }
        }
    }

    if (!is_empty(&s)) {
        PrintError(2);
        return 0;
    }
    else {
        printf("Test success");
        return 0;
    }
}
