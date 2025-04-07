#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL, *tail = NULL;

void insert_begin(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;
    if (head)
        head->prev = new_node;
    else
        tail = new_node;
    head = new_node;
}

void insert_end(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = tail;
    if (tail)
        tail->next = new_node;
    else
        head = new_node;
    tail = new_node;
}

void insert_pos(int data, int pos) {
    if (pos == 0) {
        insert_begin(data);
        return;
    }
    Node *temp = head;
    for (int i = 0; temp && i < pos - 1; i++)
        temp = temp->next;
    if (!temp) return;

    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next)
        temp->next->prev = new_node;
    else
        tail = new_node;
    temp->next = new_node;
}

void delete_begin() {
    if (!head) return;
    Node *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    else
        tail = NULL;
    free(temp);
}

void delete_end() {
    if (!tail) return;
    Node *temp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = NULL;
    else
        head = NULL;
    free(temp);
}

void delete_pos(int pos) {
    if (!head) return;
    if (pos == 0) {
        delete_begin();
        return;
    }
    Node *temp = head;
    for (int i = 0; temp && i < pos; i++)
        temp = temp->next;
    if (!temp) return;

    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp == head)
        head = temp->next;
    if (temp == tail)
        tail = temp->prev;
    free(temp);
}

void print_forward() {
    for (Node *temp = head; temp; temp = temp->next)
        printf("%d%s", temp->data, temp->next ? " -> " : "\n");
}

void print_backward() {
    for (Node *temp = tail; temp; temp = temp->prev)
        printf("%d%s", temp->data, temp->prev ? " <- " : "\n");
}

int main() {
    int choice, data, pos;
    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n");
        printf("7. Print Forward\n8. Print Backward\n9. Exit\n");
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
            print_forward();
        } else if (choice == 8) {
            print_backward();
        } else if (choice == 9) {
            break;
        } else {
            printf("Invalid input, try again.\n");
        }
    }
    return 0;
}