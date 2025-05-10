#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insert_begin(int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_end(int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new_node;
}

void insert_pos(int data, int pos) {
    if (pos == 0) {
        insert_begin(data);
        return;
    }

    Node* temp = head;
    for (int i = 0; temp && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) return;

    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_begin() {
    if (!head) return;

    Node* temp = head;
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

    Node* temp = head;
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

    Node* temp = head;
    for (int i = 0; temp && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) return;

    Node* to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

void print_list() {
    Node* temp = head;
    while (temp) {
        printf("%d", temp->data);
        if (temp->next) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data, pos;

    while (1) {
        printf("\n1.Insert Begin 2.Insert End 3.Insert Pos\n");
        printf("4.Delete Begin 5.Delete End 6.Delete Pos\n");
        printf("7.Print 8.Exit\nChoice: ");
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
            print_list();
        } else if (choice == 8) {
            break;
        }
    }

    return 0;
}