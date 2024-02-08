#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    char key;
    struct treenode *left;
    struct treenode *right;
} TreeNode;

typedef int Boolean;

//CreateTree
void CreateTree(TreeNode **root) {
    *root = NULL;
}

//TreeEmpty
Boolean TreeEmpty(TreeNode *root) {
    return (root == NULL);
}

void preOrder(TreeNode *bTree) {
    if (bTree != NULL) {
        printf("%c ", bTree->key);
        preOrder(bTree->left);
        preOrder(bTree->right);
    }
}

void inOrder(TreeNode *bTree) {
    if (bTree != NULL) {
        inOrder(bTree->left);
        printf("%c ", bTree->key);
        inOrder(bTree->right);
    }
}

void postOrder(TreeNode *bTree) {
    if (bTree != NULL) {
        postOrder(bTree->left);
        postOrder(bTree->right);
        printf("%c ", bTree->key);
    }
}

int main() {
    TreeNode *B3; // Declare the root of the tree

    CreateTree(&B3);

    // Manually creating a simple tree for demonstration
    // Example tree structure:
    //      A
    //     / \
    //    B   C
    B3 = (TreeNode*)malloc(sizeof(TreeNode)); // Allocate memory for root node
    B3->key = 'A'; // Set root node key
    B3->left = (TreeNode*)malloc(sizeof(TreeNode)); // Allocate memory for left child
    B3->left->key = 'B'; // Set left child key
    B3->left->left = NULL; // Left child's left is NULL
    B3->left->right = NULL; // Left child's right is NULL

    B3->right = (TreeNode*)malloc(sizeof(TreeNode)); // Allocate memory for right child
    B3->right->key = 'C'; // Set right child key
    B3->right->left = NULL; // Right child's left is NULL
    B3->right->right = NULL; // Right child's right is NULL

    printf("PreOrder: ");
    preOrder(B3);
    printf("\n");

    printf("InOrder: ");
    inOrder(B3);
    printf("\n");

    printf("PostOrder: ");
    postOrder(B3);
    printf("\n");

    free(B3->left); // Free left child
    free(B3->right); // Free right child
    free(B3); // Free root node

    return 0;
}
