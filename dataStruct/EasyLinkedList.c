#include <stdio.h>
#include <stdlib.h>

// Define a node
typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* head = NULL;

// Insert at beginning
void insertAtBeginning(int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at position
void insertAtPosition(int val, int pos) {
    if (pos == 0) {
        insertAtBeginning(val);
        return;
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->value = val;

    Node* temp = head;
    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) return;  // position too far

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteAtBeginning() {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void deleteAtEnd() {
    if (head == NULL) return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete from position
void deleteAtPosition(int pos) {
    if (head == NULL) return;

    if (pos == 0) {
        deleteAtBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 0; temp->next != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp->next == NULL) return;  // invalid position

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
}

// Print the list
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->value);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n");
        printf("7. Print List\n8. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(value);
        } else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
        } else if (choice == 3) {
            printf("Enter value and position: ");
            scanf("%d %d", &value, &pos);
            insertAtPosition(value, pos);
        } else if (choice == 4) {
            deleteAtBeginning();
        } else if (choice == 5) {
            deleteAtEnd();
        } else if (choice == 6) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
        } else if (choice == 7) {
            printList();
        } else if (choice == 8) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}