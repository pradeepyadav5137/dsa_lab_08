#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct TreeNode* createTree(int parent[], int n) {
    struct TreeNode** nodes = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    struct TreeNode* root = NULL;


    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(i);
    }

 
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = nodes[i];  // The root node
        } else {
            struct TreeNode* parentNode = nodes[parent[i]];
            if (parentNode->left == NULL) {
                parentNode->left = nodes[i];
            } else {
                parentNode->right = nodes[i];
            }
        }
    }

 
    free(nodes);
    return root;
}


void printTree(struct TreeNode* root, int level) {
    if (root != NULL) {
        printTree(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("-> %d\n", root->data);
        printTree(root->left, level + 1);
    }
}


int main() {
    int parent[] = {1, 5, 5, 2, 2, -1, 3};
    int n = sizeof(parent) / sizeof(parent[0]);

    struct TreeNode* root = createTree(parent, n);

    printf("Tree Structure:\n");
    printTree(root, 0);

    return 0;
}
