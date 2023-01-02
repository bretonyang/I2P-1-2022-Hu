#include <stdio.h>
#include <stdlib.h>

#include "function.h"

static Node* InsertHelper(Node* root, int src);
static void PrintHelper(Node* root);

void Insert(Node** root, int src) {
    *root = InsertHelper(*root, src);
}

static Node* InsertHelper(Node* root, int src) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = src;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Left
    if (root->val > src) {
        root->left = InsertHelper(root->left, src);
    }
    // Right
    else if (root->val < src) {
        root->right = InsertHelper(root->right, src);
    }

    return root;
}

// Pre-order: VLR
void Print(Node* root) {
    // The following is just for fixing the presentation error, where the trailing
    // white space is not allowed.

    // Provided the root is never empty
    printf("%d", root->val);
    PrintHelper(root->left);
    PrintHelper(root->right);
    printf("\n");
}

static void PrintHelper(Node* root) {
    if (root == NULL) {
        return;
    }

    printf(" %d", root->val);
    PrintHelper(root->left);
    PrintHelper(root->right);
}

