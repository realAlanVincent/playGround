#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

void display() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            return 0;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}
