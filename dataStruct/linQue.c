#include <stdio.h>

#define QUEUE_SIZE 100

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == QUEUE_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        front = rear = -1;
        return;
    }
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d\n", queue[i]);
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &value);
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else {
            break;
        }
    }
    return 0;
}
