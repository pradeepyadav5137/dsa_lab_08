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


struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}


void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main() {
    int nums[] = {50, 70, 60, 20, 90, 10, 40, 100};
    int n = sizeof(nums) / sizeof(nums[0]);
    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, nums[i]);
    }

    printf("Inorder Traversal of the BST:\n");
    inorder(root);
    printf("\n");

    return 0;
}
