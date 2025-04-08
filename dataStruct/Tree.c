#include <stdio.h>
#include <stdlib.h>
#define MAX 25
#define max(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode *root = NULL;

struct TreeNode *create(int val) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    if (!node) return NULL;
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void insert(int val) {
    if (!root) {
        root = create(val);
        return;
    }
    struct TreeNode *q[MAX], *temp;
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front < rear) {
        temp = q[front++];
        if (!temp->left) {
            temp->left = create(val);
            return;
        } else q[rear++] = temp->left;
        if (!temp->right) {
            temp->right = create(val);
            return;
        } else q[rear++] = temp->right;
    }
}

void delete(int key) {
    if (!root) return;
    if (!root->left && !root->right && root->val == key) {
        free(root); root = NULL; return;
    }
    struct TreeNode *q[MAX], *temp, *key_node = NULL, *last_parent = NULL;
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front < rear) {
        temp = q[front++];
        if (temp->val == key) key_node = temp;
        if (temp->left) { last_parent = temp; q[rear++] = temp->left; }
        if (temp->right) { last_parent = temp; q[rear++] = temp->right; }
    }
    if (key_node) {
        key_node->val = temp->val;
        if (last_parent->right == temp) last_parent->right = NULL;
        else last_parent->left = NULL;
        free(temp);
    }
}

int search(int key) {
    if (!root) return 0;
    struct TreeNode *q[MAX];
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front < rear) {
        struct TreeNode *t = q[front++];
        if (t->val == key) return 1;
        if (t->left) q[rear++] = t->left;
        if (t->right) q[rear++] = t->right;
    }
    return 0;
}

int height(struct TreeNode *node) {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

void inorder(struct TreeNode *node) {
    if (!node) return;
    inorder(node->left);
    printf("%d ", node->val);
    inorder(node->right);
}

void preorder(struct TreeNode *node) {
    if (!node) return;
    printf("%d ", node->val);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct TreeNode *node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->val);
}

void levelorder() {
    if (!root) return;
    struct TreeNode *q[MAX];
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front < rear) {
        struct TreeNode *t = q[front++];
        printf("%d ", t->val);
        if (t->left) q[rear++] = t->left;
        if (t->right) q[rear++] = t->right;
    }
}

int main() {
    int ch, val;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Height 5.Inorder 6.Preorder 7.Postorder 8.Levelorder 9.Exit\n> ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &val); insert(val); break;
            case 2: printf("Delete: "); scanf("%d", &val); delete(val); break;
            case 3: printf("Search: "); scanf("%d", &val); printf(search(val) ? "Found\n" : "Not Found\n"); break;
            case 4: printf("Height: %d\n", height(root)); break;
            case 5: inorder(root); break;
            case 6: preorder(root); break;
            case 7: postorder(root); break;
            case 8: levelorder(); break;
            case 9: return 0;
            default: printf("Invalid\n");
        }
    }
}
