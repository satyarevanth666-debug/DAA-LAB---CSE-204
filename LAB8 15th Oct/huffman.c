#include <stdio.h>
#include<stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* newNode(char ch, int freq) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;

    return temp;
}

void printCodes(struct Node *root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->ch);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
    }
}

int main() {
    int n, i, j, min1, min2, code[20];
    struct Node *nodes[40], *temp;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        char ch;
        int freq;

        printf("Enter character and frequency: ");
        scanf(" %c %d", &ch, &freq);

        nodes[i] = newNode(ch, freq);
    }

    for (i = n; i < 2 * n - 1; i++) {
        min1 = min2 = -1;

        for (j = 0; j < i; j++) {
            if (nodes[j] != NULL) {
                if (min1 == -1 ||
                    nodes[j]->freq < nodes[min1]->freq) {
                    min2 = min1;
                    min1 = j;
                } else if (min2 == -1 ||
                           nodes[j]->freq < nodes[min2]->freq) {
                    min2 = j;
                }
            }
        }

        temp = newNode('$',
                       nodes[min1]->freq + nodes[min2]->freq);

        temp->left = nodes[min1];
        temp->right = nodes[min2];

        nodes[min1] = NULL;
        nodes[min2] = NULL;
        nodes[i] = temp;
    }

    printf("\nHuffman Codes:\n");
    printCodes(nodes[2 * n - 2], code, 0);

    return 0;
}