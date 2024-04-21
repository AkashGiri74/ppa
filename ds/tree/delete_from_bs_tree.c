#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left, *right;
    int data;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *createBST(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = createBST(root->left, data);
    } else if (data >= root->data) {
        root->right = createBST(root->right, data);
    }
    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node *findMax(struct node *root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (largest in the left subtree)
        struct node *maxNode = findMax(root->left);

        // Copy the inorder predecessor's content to this node
        root->data = maxNode->data;

        // Delete the inorder predecessor
        root->left = deleteNode(root->left, maxNode->data);
    }
    return root;
}

int main() {
    struct node *root = NULL;
    int data;
    do {
        printf("Enter data (-1 to stop): ");
        scanf("%d", &data);
        if (data != -1) {
            root = createBST(root, data);
        }
    } while (data != -1);

    printf("Inorder traversal:");
    inorder(root);
    printf("\n");

    int key;
    printf("Enter the key to delete: ");
    scanf("%d", &key);

    root = deleteNode(root, key);

    printf("Inorder traversal after deletion:");
    inorder(root);
    printf("\n");

    return 0;
}
