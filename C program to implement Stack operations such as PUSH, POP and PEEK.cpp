#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow! Cannot push element %d\n", value);
    } else {
        stack[++top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack underflow! Cannot pop element.\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top--]);
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    } else {
        return stack[top];
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    pop();
    printf("Top element after pop: %d\n", peek());

    pop();
    pop();
    pop();

    return 0;
}
