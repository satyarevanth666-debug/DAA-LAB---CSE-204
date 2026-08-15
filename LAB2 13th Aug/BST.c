#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

struct Node* deleteNode(struct Node* root, int data) {

    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {

        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        else {
            struct Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {

    struct Node* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 60);
    root = insertNode(root, 45);
    root = insertNode(root, 55);
    root = insertNode(root, 35);
    root = insertNode(root, 70);
    root = insertNode(root, 65);
    root = insertNode(root, 68);

    printf("BST after insertion:\n");
    inorder(root);

    root = deleteNode(root, 20);
    printf("\n\nAfter deleting 20:\n");
    inorder(root);

    root = deleteNode(root, 55);
    printf("\n\nAfter deleting 55:\n");
    inorder(root);

    root = deleteNode(root, 50);
    printf("\n\nAfter deleting 50:\n");
    inorder(root);

    return 0;
}