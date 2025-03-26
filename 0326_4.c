#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 6
#define MAX_STACK_SIZE MAX_SIZE * MAX_SIZE

typedef struct {
    short r;
    short c;
} location;

typedef struct {
    location data[MAX_STACK_SIZE];
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

void push(StackType* s, location item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    s->data[++(s->top)] = item;
}

location pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

location peek(StackType* s) {
    if (is_empty(s)) {
        location error = { -1, -1 };
        return error;
    }
    return s->data[s->top];
}

location here = { 1, 0 }, entry = { 1, 0 };

char maze[MAX_SIZE][MAX_SIZE] = {
    { '1', '1', '1', '1', '1', '1' },
    { 'e', '0', '1', '0', '0', '1' },
    { '1', '0', '0', '0', '1', '1' },
    { '1', '0', '1', '0', '1', '1' },
    { '1', '0', '1', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' }
};

void push_loc(StackType* s, int r, int c) {
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {//if 1 == blocked, if . == visited
        location tmp = { r, c };
        push(s, tmp);
    }
}

void maze_print(char maze[MAX_SIZE][MAX_SIZE]) {
    printf("\n");
    for (int r = 0; r < MAX_SIZE; r++) {
        for (int c = 0; c < MAX_SIZE; c++) {
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

void pushEverywhere(StackType* s, int r, int c) { 
    push_loc(s, r - 1, c);
    push_loc(s, r + 1, c);
    push_loc(s, r, c - 1);
    push_loc(s, r, c + 1);
}

int main() {
    int r, c;
    StackType s;
    init_stack(&s);
    here = entry;

    while (maze[here.r][here.c] != 'x') {// if here is not the destination
        r = here.r;
        c = here.c;
        maze[r][c] = '.';//visited mark
        maze_print(maze);
        pushEverywhere(&s, r, c);//push possible location

        if (is_empty(&s)) { //Stack Empty -> Fail
            printf("Failed\n");
            return 0;
        }
        here = pop(&s); 
    }

    maze_print(maze); 
    printf("Success\n");
    printf("The final location is : {%d, %d}\n", here.r, here.c);
    return 0;
}