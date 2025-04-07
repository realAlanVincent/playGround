#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL;

void insert_begin(int data) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) return;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;
    if (head)
        head->prev = new_node;
    head = new_node;
}

void insert_end(int data) {
    Node *new_node = malloc(sizeof(Node)), *temp = head;
    if (!new_node) return;
    new_node->data = data;
    new_node->next = NULL;
    if (!head) {
        new_node->prev = NULL;
        head = new_node;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}

void insert_pos(int data, int pos) {
    if (pos == 0) {
        insert_begin(data);
        return;
    }
    Node *new_node = malloc(sizeof(Node)), *temp = head;
    if (!new_node) return;
    for (int i = 0; temp && i < pos - 1; i++)
        temp = temp->next;
    if (!temp) {
        free(new_node);
        return;
    }
    new_node->data = data;
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next)
        temp->next->prev = new_node;
    temp->next = new_node;
}

void delete_begin() {
    if (!head) return;
    Node *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
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
    while (temp->next)
        temp = temp->next;
    temp->prev->next = NULL;
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
    free(temp);
}

void print() {
    for (Node *temp = head; temp; temp = temp->next)
        printf("%d%s", temp->data, temp->next ? " <-> " : "\n");
}

int main() {
    int choice, data, pos;
    while (1) {
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n7. Print\n8. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &data);
            insert_begin(data);
        } else if (choice == 2) {
            scanf("%d", &data);
            insert_end(data);
        } else if (choice == 3) {
            scanf("%d %d", &data, &pos);
            insert_pos(data, pos);
        } else if (choice == 4) {
            delete_begin();
        } else if (choice == 5) {
            delete_end();
        } else if (choice == 6) {
            scanf("%d", &pos);
            delete_pos(pos);
        } else if (choice == 7) {
            print();
        } else {
            break;
        }
    }
    return 0;
}