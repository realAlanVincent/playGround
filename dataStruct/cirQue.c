#include <stdio.h>

#define QUEUE_SIZE 100

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % QUEUE_SIZE == front) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % QUEUE_SIZE;
    queue[rear] = value;
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % QUEUE_SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front;; i = (i + 1) % QUEUE_SIZE) {
        printf("%d\n", queue[i]);
        if (i == rear)
            break;
    }
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
