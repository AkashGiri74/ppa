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

struct node *findNode(struct node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return findNode(root->left, key);
    }
    return findNode(root->right, key);
}

struct node *findPredecessor(struct node *root, int key) {
    struct node *targetNode = findNode(root, key);
    if (targetNode == NULL) {
        return NULL;
    }

    if (targetNode->left != NULL) {
        return findMax(targetNode->left);
    }

    struct node *predecessor = NULL;
    struct node *current = root;
    while (current != targetNode) {
        if (key < current->data) {
            current = current->left;
        } else {
            predecessor = current;
            current = current->right;
        }
    }
    return predecessor;
}

struct node *findSuccessor(struct node *root, int key) {
    struct node *targetNode = findNode(root, key);
    if (targetNode == NULL) {
        return NULL;
    }

    if (targetNode->right != NULL) {
        struct node *current = targetNode->right;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    struct node *successor = NULL;
    struct node *current = root;
    while (current != targetNode) {
        if (key > current->data) {
            current = current->right;
        } else {
            successor = current;
            current = current->left;
        }
    }
    return successor;
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
    printf("Enter the key to find predecessor and successor: ");
    scanf("%d", &key);

    struct node *predecessor = findPredecessor(root, key);
    struct node *successor = findSuccessor(root, key);

    if (predecessor != NULL) {
        printf("Predecessor of %d is %d\n", key, predecessor->data);
    } else {
        printf("No predecessor found for %d\n", key);
    }

    if (successor != NULL) {
        printf("Successor of %d is %d\n", key, successor->data);
    } else {
        printf("No successor found for %d\n", key);
    }

    return 0;
}
