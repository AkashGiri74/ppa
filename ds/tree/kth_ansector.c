#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *left, *right;
    int data;
};

struct node *createnode(int value) {
    struct node *newnode = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        return NULL;
    }
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *build_tree() {
    int data;
    printf("enter data:");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    struct node *root = createnode(data);
    printf("enter value for left child of %d ", data);
    root->left = build_tree();
    printf("enter value for right child of %d ", data);
    root->right = build_tree();

    return root;
}

int kth_ansector(struct node *root, struct node *p, struct node *key) {
    int leftans, rightans;
    if (root == NULL) {
        return 0;
    }
    if (root->data == p->data) {
        return 1;
    }
    leftans = kth_ansector(root->left, p, key);
    if (leftans != 1)
     {
        rightans = kth_ansector(root->right, p, key);
    }

    if (leftans || rightans)
     {
        (key->data)--;
    } 
    if (key->data == 0) {
        printf(" kth ansector : %d", root->data);
        key->data = -1;
    }
    return leftans || rightans;
}

int main() {
    struct node *root = NULL;
    root = build_tree();
    int p, key;
    printf("enter node you want to find kth ancestor of this node: ");
    scanf("%d", &p);
    printf("enter key which number of ancestor you want to find: ");
    scanf("%d", &key);

    kth_ansector(root, createnode(p), createnode(key));
    return 0;
}
