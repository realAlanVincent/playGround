#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insert_begin(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_end(int data) {
    Node *new_node = malloc(sizeof(Node)), *temp = head;
    new_node->data = data;
    new_node->next = NULL;
    if (!head) {
        head = new_node;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}

void insert_pos(int data, int pos) {
    if (pos == 0) {
        insert_begin(data);
        return;
    }
    Node *new_node = malloc(sizeof(Node)), *temp = head;
    new_node->data = data;
    for (int i = 0; temp && i < pos - 1; i++)
        temp = temp->next;
    if (!temp) return;
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_begin() {
    if (!head) return;
    Node *temp = head;
    head = head->next;
    free(temp);
}

void delete_end() {
    if (!head) return;
    if (!head->next) {
        free(head);
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void delete_pos(int pos) {
    if (!head) return;
    if (pos == 0) {
        delete_begin();
        return;
    }
    Node *temp = head, *prev = NULL;
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
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n");
        printf("7. Print\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            insert_begin(data);
        } else if (choice == 2) {
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insert_end(data);
        } else if (choice == 3) {
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            insert_pos(data, pos);
        } else if (choice == 4) {
            delete_begin();
        } else if (choice == 5) {
            delete_end();
        } else if (choice == 6) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            delete_pos(pos);
        } else if (choice == 7) {
            print();
        } else if (choice == 8) {
            break;
        } else {
            printf("Invalid input, try again.\n");
        }
    }
    return 0;
}