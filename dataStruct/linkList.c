#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(int data, int pos) {
    Node *new_node = malloc(sizeof(Node)), *temp = head;
    new_node->data = data;
    if (pos == 0 || !head) {
        new_node->next = head;
        head = new_node;
        return;
    }
    for (int i = 0; temp && i < pos - 1; i++)
        temp = temp->next;
    new_node->next = temp ? temp->next : NULL;
    if (temp) temp->next = new_node;
}

void delete(int pos) {
    if (!head) return;
    Node *temp = head, *prev = NULL;
    if (pos == 0) {
        head = head->next;
        free(temp);
        return;
    }
    for (int i = 0; temp && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (prev && temp) {
        prev->next = temp->next;
        free(temp);
    }
}

void print() {
    for (Node *temp = head; temp; temp = temp->next)
        printf("%d%s", temp->data, temp->next ? " -> " : "\n");
}

int main() {
    int choice, data, pos;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Print\n4. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d %d", &data, &pos);
            insert(data, pos);
        } else if (choice == 2) {
            scanf("%d", &pos);
            delete(pos);
        } else if (choice == 3) {
            print();
        } else {
            break;
        }
    }
    return 0;
}
